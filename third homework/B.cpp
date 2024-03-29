#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

const float INF = std::numeric_limits<float>::max();

class TGraph {
public:
    TGraph(uint32_t n)
        : VerticesNumber(n)
        , Cities(n, std::pair<uint32_t, uint32_t>(0,0))
        , SpecialRoads(n) 
    {}

    void ReadFromStream(std::istream& stream) {
        for (auto& [x, y] : Cities) {
            stream >> x >> y;
        }
    }

    void ReadSpecialRoads(std::istream& stream, uint32_t m) {
        uint32_t u, v, weight;
        for (uint32_t i = 0; i < m; i++) {
            stream >> u >> v >> weight;
            SpecialRoads[u - 1].emplace_back(v - 1, weight);
            SpecialRoads[v - 1].emplace_back(u - 1, weight);
        }
    }

    float Dijkstra(uint32_t a, uint32_t b) const {
        std::vector<float> dist(VerticesNumber, INF);
        std::vector<bool> visited(VerticesNumber, false);
        dist[a - 1] = 0;
        for (uint32_t i = 0; i < VerticesNumber; i++) {
            int32_t v = -1;
            for (uint32_t j = 0; j < VerticesNumber; j++) {
                if (!visited[j] && (v == -1 || dist[j] < dist[v])) {
                    v = j;
                }
            }
            visited[v] = true;
            for (uint32_t j = 0; j < VerticesNumber; j++) {
                bool flag = false;
                for (const auto& [vertice, weight] : SpecialRoads[v]) {
                    if (vertice == j) {
                        flag = true;
                        if (!visited[j] && dist[v] + weight < dist[j]) {
                            dist[j] = dist[v] + weight;
                        }
                        break;
                    }
                }

                if (!flag) {
                    float weight = sqrt(pow(abs(Cities[v].first - Cities[j].first), 2) + pow(abs(Cities[v].second - Cities[j].second), 2));
                    if (!visited[j] && dist[v] + weight  < dist[j]) {
                        dist[j] = dist[v] + weight;
                    }
                }
            }
        }
        return dist[b - 1];
    }

    private:
        uint32_t VerticesNumber;
        std::vector<std::pair<uint32_t, uint32_t>> Cities;
        std::vector<std::vector<std::pair<uint32_t, uint32_t>>> SpecialRoads;
    };

int main() {
    uint32_t n;
    std::cin >> n;
    TGraph graph(n);
    graph.ReadFromStream(std::cin);
  
    uint32_t m;
    std::cin >> m;
    graph.ReadSpecialRoads(std::cin, m);

    uint32_t a, b;
    std::cin >> a >> b;
    std::cout << graph.Dijkstra(a, b) << std::endl;
    return 0;
}
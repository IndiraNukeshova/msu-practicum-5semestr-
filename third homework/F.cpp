#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <limits>

const uint64_t INF = std::numeric_limits<uint64_t>::max();

class TGraph {
public:
    TGraph(uint64_t n) : N(n), AdjacencyLists(n) {}

    void ReadFromStream(std::istream& stream, uint64_t k);
    int64_t Dijkstra(uint64_t a, uint64_t b) const;
private:
    uint64_t N;
    std::vector<std::vector<std::pair<uint64_t, uint64_t>>> AdjacencyLists;
};


void TGraph::ReadFromStream(std::istream& stream, uint64_t k) {
    uint64_t u, v, cost;
    for (uint64_t i = 0; i < k; i++) {
        stream >> u >> v >> cost;
        AdjacencyLists[u - 1].emplace_back(v-1, cost);
        AdjacencyLists[v - 1].emplace_back(u-1, cost);
    }
}

int64_t TGraph::Dijkstra(uint64_t a, uint64_t b) const {
    std::vector<uint64_t> distance(N, INF);
    std::set<std::pair<uint64_t, uint64_t>> q;
    distance[a - 1] = 0;
    q.emplace(distance[a - 1], a - 1);
    while (!q.empty()) {
        uint64_t begin = q.begin()->second;
        q.erase(q.begin()); 
        for (auto [to, len] : AdjacencyLists[begin]) {
            if (distance[begin] + len < distance[to]) {
                q.erase(std::make_pair(distance[to], to));
                distance[to] = distance[begin] + len;
                q.insert(std::make_pair(distance[to], to));
            }
        }
    }
    if (distance[b - 1] == INF) {
        return -1;
    } else {
        return distance[b - 1];
    }
}

int main() {
    uint64_t n, k;
    std::cin >> n >> k;
    TGraph graph(n);
    graph.ReadFromStream(std::cin, k);
    uint64_t a, b;
    std::cin >> a >> b;
    std::cout << graph.Dijkstra(a, b) << std::endl;
    return 0;
}
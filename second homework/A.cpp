#include <iostream>
#include <vector>

class TGraph {
public:
    TGraph(uint32_t n) : N(n), AdjacencyMatrix(n, std::vector<int>(n)) {}

    void ReadFromStream(std::istream& stream) {
        for (uint32_t i = 0; i < N; ++i) {
            for (uint32_t j = 0; j < N; ++j) {
                stream >> AdjacencyMatrix[i][j];
            }
        }
    }

    uint32_t GetConnectedComponent(uint32_t vertex) const {
        std::vector<bool> visited(N, false);
        uint32_t componentSize = 0;
        DepthFirstSearch(vertex, visited, componentSize);
        return componentSize;
    }

private:
    void DepthFirstSearch(uint32_t vertex, std::vector<bool>& visited, uint32_t& componentSize) const {
        visited[vertex] = true;
        ++componentSize;

        for (uint32_t i = 0; i < N; ++i) {
            if (AdjacencyMatrix[vertex][i] && !visited[i]) {
                DepthFirstSearch(i, visited, componentSize);
            }
        }
    }

private:
    uint32_t N;
    std::vector<std::vector<int>> AdjacencyMatrix;
};

int main() {
    uint32_t n, s;
    std::cin >> n >> s;

    TGraph graph(n);
    graph.ReadFromStream(std::cin);

    uint32_t componentSize = graph.GetConnectedComponent(s - 1);
    std::cout << componentSize << std::endl;
    return 0;
}
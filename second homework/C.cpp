#include <iostream>
#include <vector>

class TGraph {
public:
    TGraph(int n) : N(n), AdjacencyMatrix(n, std::vector<int>(n)) {}

    void ReadFromStream(std::istream& stream) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                stream >> AdjacencyMatrix[i][j];
            }
        }
    }

    bool HasCycle() const {
        std::vector<bool> visited(N, false);
        std::vector<bool> stack(N, false);

        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                if (DepthFirstSearch(i, visited, stack)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool DepthFirstSearch(int v, std::vector<bool>& visited, std::vector<bool>& stack) const {
        visited[v] = true;
        stack[v] = true;

        for (int i = 0; i < N; ++i) {
            if (AdjacencyMatrix[v][i]) {
                if (!visited[i]) {
                    if (DepthFirstSearch(i, visited, stack)) {
                        return true;
                    }
                } else if (stack[i]) {
                    return true;
                }
            }
        }

        stack[v] = false;
        return false;
    }

private:
    int N;
    std::vector<std::vector<int>> AdjacencyMatrix;
};

int main() {
    int N;
    std::cin >> N;
    TGraph graph(N);
    graph.ReadFromStream(std::cin);

    if (graph.HasCycle()) {
        std::cout << "1\n";
    } else {
        std::cout << "0\n";
    }

    return 0;
}
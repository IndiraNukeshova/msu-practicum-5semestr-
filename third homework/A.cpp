#include <iostream>
#include <vector>
#include <limits>
  
const int INF = std::numeric_limits<int>::max();

class TFloyd {
private:
    std::vector<std::vector<int>> AdjacencyMatrix;
    std::vector<std::vector<int>> ShortestDistances;
    int N;

public:
    TFloyd(int n) : AdjacencyMatrix(n, std::vector<int>(n, INF)), ShortestDistances(n, std::vector<int>(n, INF)), N(n) {}

    void ReadFromStream(std::istream& stream) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                stream >> AdjacencyMatrix[i][j];
                if (i == j) {
                    ShortestDistances[i][j] = 0;
                } else if (AdjacencyMatrix[i][j] != -1) {
                    ShortestDistances[i][j] = AdjacencyMatrix[i][j];
                }
            }
        }
    }

    void FloydAlgorithm() {
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (ShortestDistances[i][k] < INF && ShortestDistances[k][j] < INF) {
                        ShortestDistances[i][j] = std::min(ShortestDistances[i][j], ShortestDistances[i][k] + ShortestDistances[k][j]);
                    }
                }
            }
        }
    }

    void Print(std::ostream& stream) const {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (ShortestDistances[i][j] == INF) {
                    stream << "-1 ";
                } else {
                    stream << ShortestDistances[i][j] << " ";
                }
            }
            stream << std::endl;
        }
    }
};

int main() {
    int n;
    std::cin >> n;

    TFloyd floyd(n);
    floyd.ReadFromStream(std::cin);
    floyd.FloydAlgorithm();
    floyd.Print(std::cout);

    return 0;
}
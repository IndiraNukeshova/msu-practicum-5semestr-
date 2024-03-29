#include <iostream>
#include <vector>

int MaxCost(int N, int M, const std::vector<int>& weights, const std::vector<int>& cost) {
    std::vector<std::vector<int>> matrix(N + 1, std::vector<int>(M + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (weights[i - 1] <= j) {
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i - 1][j - weights[i - 1]] + cost[i - 1]);
            } else {
                matrix[i][j] = matrix[i - 1][j];
            }
        }
    }

    return matrix[N][M];
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> weights(n);
    std::vector<int> cost(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> cost[i];
    }

    int result = MaxCost(n, m, weights, cost);
    std::cout << result << std::endl;

    return 0;
}
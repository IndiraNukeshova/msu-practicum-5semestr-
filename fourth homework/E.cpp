#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> coordinates(n);
    for (int i = 0; i < n; i++) {
        std::cin >> coordinates[i];
    }

    sort(coordinates.begin(), coordinates.end());

    std::vector<int> distance(n+1, 0);
    distance[1] = coordinates[1] - coordinates[0];
    for (int i = 2; i <= n; i++) {
         distance[i] = std::min(distance[i - 1], distance[i - 2]) + (coordinates[i - 1] - coordinates[i - 2]);
    }

    std::cout << distance[n] << std::endl;
    return 0;
}
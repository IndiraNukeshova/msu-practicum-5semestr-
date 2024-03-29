#include <iostream>
#include <vector>
#include <queue>

class TGraph {
public:
    TGraph(int n) : N(n), EdgeList(n) {}

    void AddEdge(int u, int v) {
        EdgeList[u].push_back(v);
        EdgeList[v].push_back(u);
    }

    std::vector<int> BreadthFirstSearch(const std::vector<int>& startVertices) const {
        std::vector<int> distances(N, -1);
        std::queue<int> q;

        for (int v : startVertices) {
            distances[v] = 0;
            q.push(v);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : EdgeList[u]) {
                if (distances[v] == -1) {
                    distances[v] = distances[u] + 1;
                    q.push(v);
                }
            }
        }

        return distances;
    }

private:
    int N;
    std::vector<std::vector<int>> EdgeList;
};

std::vector<int> ReadExits(std::istream& stream) {
    int k;
    stream >> k;
    std::vector<int> exits(k);

    for (int i = 0; i < k; ++i) {
        stream >> exits[i];
        exits[i]--; // Convert to 0-based indexing
    }

    return exits;
}



TGraph ReadFromStream(std::istream& stream, int n) { 
    int m;
    stream >> m;
    TGraph graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        stream >> u >> v;
        u--; v--;
        graph.AddEdge(u, v);
    }

    return graph;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> exits = ReadExits(std::cin);

    TGraph graph = ReadFromStream(std::cin, n);

    std::vector<int> distances = graph.BreadthFirstSearch(exits);

    for (int i = 0; i < n; ++i) {
        std::cout << distances[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
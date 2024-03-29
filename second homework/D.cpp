#include <iostream>
#include <vector>
#include <queue>

class TGraph {
public:
    TGraph(size_t vertices)
        : Vertices(vertices), AdjList(vertices), InDegree(vertices, 0) {}

    void AddEdge(size_t u, size_t v) {
        AdjList[u].push_back(v);
        InDegree[v]++;
    }

    bool TopologicalSort(std::vector<size_t>& result) const {
        TGraph copy(*this);
        std::queue<size_t> q;
        for (size_t i = 0; i < Vertices; ++i) {
            if (copy.InDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            size_t u = q.front();
            q.pop();
            result.push_back(u);

            for (size_t v : copy.AdjList[u]) {
                copy.InDegree[v]--;
                if (copy.InDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return result.size() == Vertices;
    }

    static TGraph ReadFromStream(std::istream& stream, size_t n) {
        size_t m;
        stream >> m;
        TGraph graph(n);

        for (size_t i = 0; i < m; ++i) {
            size_t u, v;
            stream >> u >> v;
            u--;
            v--;
            graph.AddEdge(u, v);
        }

        return graph;
    }

private:
    size_t Vertices;
    std::vector<std::vector<size_t>> AdjList;
    std::vector<size_t> InDegree;
};

void PrintResult(std::ostream& stream, const std::vector<size_t>& result) {
    if (!result.empty()) {
        stream << "Yes\n";
        for (size_t i = 0; i < result.size(); ++i) {
            stream << result[i] + 1 << ' ';
        }
        stream << '\n';
    } else {
        stream << "No\n";
    }
}

int main() {
    size_t n;
    std::cin >> n;

    TGraph graph = TGraph::ReadFromStream(std::cin, n);
    std::vector<size_t> result;
    if (graph.TopologicalSort(result)) {
        PrintResult(std::cout, result);
    } else {
        std::cout << "No\n";
    }

    return 0;
}

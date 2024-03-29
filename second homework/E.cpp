#include <iostream>
#include <vector>
#include <set>

class TGraph {
public:
    TGraph(int n) : Graph(n), ReversedGraph(n) {}

    void AddEdge(int from, int to) {
        Graph[from].push_back(to);
        ReversedGraph[to].push_back(from);
    }

    static TGraph ReadFromStream(std::istream& stream, int n) {
        TGraph graph(n);
        int m;
        stream >> m;

        for (int i = 0; i < m; i++) {
            int a, b;
            stream >> a >> b;
            graph.AddEdge(a - 1, b - 1);
        }

        return graph;
    }

    std::pair<std::vector<int>, int> FindStronglyConnectedComponents() const {
        std::vector<bool> used(Graph.size(), false);
        std::vector<int> stack;
        std::vector<int> color(Graph.size(), -1);

        for (size_t i = 0; i < Graph.size(); i++) {
            if (!used[i]) {
                DFS1(i, used, stack);
            }
        }

        int c = 0;
        for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
            int v = *it;
            if (color[v] == -1) {
                DFS2(v, c, color);
                c++;
            }
        }

        return std::make_pair(color, c);
    }

private:
    void DFS1(int v, std::vector<bool>& used, std::vector<int>& stack) const {
        used[v] = true;
        for (auto to : Graph[v]) {
            if (!used[to]) {
                DFS1(to, used, stack);
            }
        }
        stack.push_back(v);
    }

    void DFS2(int v, int c, std::vector<int>& color) const {
        color[v] = c;
        for (auto to : ReversedGraph[v]) {
            if (color[to] == -1) {
                DFS2(to, c, color);
            }
        }
    }

private:
    std::vector<std::vector<int>> Graph, ReversedGraph;
};

int main() {
    int n;
    std::cin >> n;

    TGraph graph = TGraph::ReadFromStream(std::cin, n);

    auto [colors, numComponents] = graph.FindStronglyConnectedComponents();
    int condensationEdges = numComponents;

    std::cout << condensationEdges << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << colors[i] + 1 << " ";
    }

    return 0;
}
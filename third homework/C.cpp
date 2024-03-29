#include <iostream>
#include <vector>

class TDisjointSetUnion {
public:
    TDisjointSetUnion(uint32_t n) : N(n), Parent(n), Size(n, 1) {
        for (uint32_t i = 0; i < N; i++) {
            Parent[i] = i;
        }
    }

    uint32_t FindSet(uint32_t v) const {
        if (v == Parent[v]) {
            return v;
        } else {
            return Parent[v] = FindSet(Parent[v]);
        }
    }

    void UnionSets(uint32_t a, uint32_t b) {
        a = FindSet(a);
        b = FindSet(b);
        if (a != b) {
            if (Size[a] == Size[b]) {
                Parent[a] = b;
                Size[b] += Size[a];
                Size[a] = Size[b];
            } else {
                if (Size[a] < Size[b]) {
                    std::swap(a, b);
                }
                Parent[b] = a;
                Size[b] += Size[a];
                Size[a] = Size[b];
            }
        }
    } 

    uint32_t SizeOfSet(uint32_t vertex) const {
        return Size[Parent[vertex]];
    }

private:
    uint32_t N;
    mutable std::vector<uint32_t> Parent;
    std::vector<uint32_t> Size;

};


int main() {
    uint32_t n, m;
    std::cin >> n >> m;

    TDisjointSetUnion set(n);
    uint32_t result = 0;

    for (uint32_t i = 0; i < m; i++) {
        uint32_t a, b;
        std::cin >> a >> b;
        result++;
        set.UnionSets(a, b);
        if (set.SizeOfSet(0) == n) {
            break;
        }
    }

    std::cout << result << std::endl;
    return 0;
}
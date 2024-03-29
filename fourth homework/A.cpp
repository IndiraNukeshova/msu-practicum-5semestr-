#include <iostream>
#include <memory>

struct TNode {
    int Elem = 0;
    std::unique_ptr<TNode> Left = nullptr;
    std::unique_ptr<TNode> Right = nullptr;

    TNode(int value) {
        Elem = value;
        Left = nullptr;
        Right = nullptr;
    }
};

class Tree {
public:
    Tree() 
        : Root(nullptr)
    {}

    void Insert(int value);
    int FindHeight() const;

private:
    std::unique_ptr<TNode> Root;
    void Insert(int value, std::unique_ptr<TNode>& leaf);
    int FindHeight(const std::unique_ptr<TNode>& leaf) const;
};

void Tree::Insert(int value) {
    Insert(value, Root);
}

void Tree::Insert(int value, std::unique_ptr<TNode>& leaf) {
    if (leaf == nullptr) {
        leaf.reset(new TNode(value));
        return;
    } else if (value < leaf->Elem) {
        Insert(value, leaf->Left);
    } else if (value > leaf->Elem) {
        Insert(value, leaf->Right);
    }
}

int Tree::FindHeight(const std::unique_ptr<TNode>& leaf) const {
    if (leaf == nullptr) {
        return 0;
    }
    return 1 + std::max(FindHeight(leaf->Left), FindHeight(leaf->Right));
}

int Tree::FindHeight() const {
    return FindHeight(Root);
}

int main() {
    Tree tree;
    int element;
    std::cin >> element;
    while (element != 0) {
        tree.Insert(element);
        std::cin >> element;
    }
    std::cout << tree.FindHeight() << std::endl;
    return 0;
}
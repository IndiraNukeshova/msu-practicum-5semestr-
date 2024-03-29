#include <iostream>
#include <vector>

struct Node {
    int key;
    int priority;
    int size;
    Node* left;
    Node* right;

    Node(int k) 
        : key(k)
        , priority(rand())
        , size(1)
        , left(nullptr)
        , right(nullptr) 
    {}
};

int getSize(Node* node) {
    return node ? node->size : 0;
}

void updateSize(Node* node) {
    if (node) {
        node->size = getSize(node->left) + getSize(node->right) + 1;
    }
}

Node* merge(Node* left, Node* right) {
    if (!left) {
        return right;
    }
    if (!right) {
        return left;
    }
    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        updateSize(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        updateSize(right);
        return right;
    }
}

void split(Node* node, int key, Node*& left, Node*& right, int added = 0) {
    if (!node) {
        left = right = nullptr;
        return;
    }

    int curKey = added + getSize(node->left) + 1;
    if (key < curKey) {
        split(node->left, key, left, node->left, added);
        right = node;
    } else {
        split(node->right, key, node->right, right, curKey);
        left = node;
    }

    updateSize(node);
}

void printOrder(Node* node) {
    if (!node) {
        return;
    }
    printOrder(node->left);
    std::cout << node->key << " ";
    printOrder(node->right);
}

int main() {
    int n, m;
    std::cin >> n >> m;

    Node* root = nullptr;
    for (int i = 1; i <= n; ++i) {
        root = merge(root, new Node(i));
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;

        Node *left, *mid, *right;
        split(root, l - 1, left, mid);
        split(mid, r - l + 1, mid, right);

        root = merge(mid, merge(left, right));
    }

    printOrder(root);

    return 0;
}
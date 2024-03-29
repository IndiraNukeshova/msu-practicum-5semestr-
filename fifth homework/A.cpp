#include <iostream>
#include <vector>

struct TSegments {
    std::vector<std::pair<int, int>> array;

    TSegments(int n)
        : array(4 * n, {0, 0})
    {}
    std::pair<int, int> MakePair(std::pair<int, int> a, std::pair<int, int> b);
    void BuildTree(int *arr, int vertex, int left, int right);
    std::pair<int, int> Maximum(int vertex, int left, int right, int a, int b);
};

std::pair<int, int> TSegments::MakePair(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first == -1) {
        return b;
    } else if (b.first == -1) {
        return a;
    } else if (a.second > b.second) {
        return a;
    } else {
        return b;
    }
}

void TSegments::BuildTree(int *arr, int vertex, int left, int right) {
    if (left == right) {
        array[vertex] = std::make_pair(left, arr[left]);
    } else {
        int mid = (left + right) / 2;
        BuildTree(arr, vertex * 2, left, mid);
        BuildTree(arr, vertex * 2 + 1, mid + 1, right);
        array[vertex] = MakePair(array[vertex * 2], array[vertex * 2 + 1]);
    }
}

std::pair<int, int> TSegments::Maximum(int vertex, int left, int right, int a, int b) {
    if (a > b) {
        return std::make_pair(-1, -1);
    }
    if (a == left && b == right) {
        return array[vertex];
    }
    int mid = (left + right) / 2;
    return MakePair(Maximum(vertex * 2, left, mid, a, std::min(b, mid)),
                    Maximum(vertex * 2 + 1, mid + 1, right, std::max(a, mid + 1), b));
}


int main() {
    int n, m, *arr;
    std::cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    TSegments segments(n);
    segments.BuildTree(arr, 1, 0, n - 1);
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int num1, num2;
        std::cin >> num1 >> num2;
        std::cout << segments.Maximum(1, 0, n - 1, num1 - 1, num2 - 1).first + 1 << ' ';
    }
    delete [] arr;
    std::cout << std::endl;
    return 0;
}
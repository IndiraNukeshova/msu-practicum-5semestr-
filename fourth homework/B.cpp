#include <iostream>
#include <vector>

void Heapify(std::vector<int>& array, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && array[left] > array[largest]) {
        largest = left;
    }
    if (right < n && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(array[i], array[largest]);
        Heapify(array, n, largest);
    }
}

void HeapSort(std::vector<int>& array) {
    for (int i = array.size() / 2 - 1; i >= 0; i--) {
        Heapify(array, array.size(), i);
    }
    for (int i = array.size() - 1; i >= 0; i--) {
        std::swap(array[0], array[i]);
        Heapify(array, i, 0);
    }
}

void PrintArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> array;
    for (int i = 0; i < n; i++) {
        int elem;
        std::cin >> elem;
        array.push_back(elem);
    }
    HeapSort(array);
    PrintArray(array);
    return 0;
}
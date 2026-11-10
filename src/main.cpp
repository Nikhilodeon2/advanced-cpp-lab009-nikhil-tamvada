#include "project/heap.h"

#include <iostream>
#include <vector>

int main() {
    MaxHeap heap;
    for (int value : {12, 4, 9, 18, 1, 7, 5, 3, 15}) {
        heap.push(value);
    }

    std::cout << "Max-heap size: " << heap.size() << '\n';
    std::cout << "Maximum value: " << heap.top() << '\n';
    std::cout << "Contains 7: " << (heap.contains(7) ? "yes" : "no") << '\n';
    std::cout << "Removed maximum: " << heap.pop() << '\n';
    std::cout << "New maximum: " << heap.top() << "\n\n";

    MaxHeap sortable({8, 3, 9, 1, 6, 2, 7, 4});
    const std::vector<int> sorted = sortable.heapSort();
    std::cout << "Sorted values:";
    for (int value : sorted) {
        std::cout << ' ' << value;
    }
    std::cout << '\n';

    return 0;
}

// link - https://takeuforward.org/plus/dsa/problems/implement-min-heap


#include <vector>
#include <algorithm>
#include <climits>

class Solution {
private:
    std::vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void shiftUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            std::swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void shiftDown(int i) {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        int n = heap.size();

        if (left < n && heap[left] < heap[minIndex]) {
            minIndex = left;
        }
        if (right < n && heap[right] < heap[minIndex]) {
            minIndex = right;
        }

        if (i != minIndex) {
            std::swap(heap[i], heap[minIndex]);
            shiftDown(minIndex);
        }
    }

public:
    void initializeHeap() {
        heap.clear();
    }

    void insert(int key) {
        heap.push_back(key);
        shiftUp(heap.size() - 1);
    }

    void changeKey(int index, int new_val) {
        if (index < 0 || index >= heap.size()) {
            return;
        }
        int old_val = heap[index];
        heap[index] = new_val;
        if (new_val < old_val) {
            shiftUp(index);
        } else if (new_val > old_val) {
            shiftDown(index);
        }
    }

    void extractMin() {
        if (heap.empty()) {
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        shiftDown(0);
    }

    bool isEmpty() {
        return heap.empty();
    }

    int getMin() {
        if (heap.empty()) {
            return INT_MIN; // or throw an exception
        }
        return heap[0];
    }

    int heapSize() {
        return heap.size();
    }
};
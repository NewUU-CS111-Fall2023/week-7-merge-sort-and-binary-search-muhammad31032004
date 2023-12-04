#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element {
    int value;
    int row;
    int col;

    Element(int v, int r, int c) : value(v), row(r), col(c) {}

    // Custom comparison function for min-heap
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    // Push the first element of each row into the min-heap
    for (int i = 0; i < n; ++i) {
        minHeap.push(Element(matrix[i][0], i, 0));
    }

    // Extract the kth smallest element
    for (int i = 0; i < k - 1; ++i) {
        Element current = minHeap.top();
        minHeap.pop();

        // Push the next element in the same row
        if (current.col < n - 1) {
            minHeap.push(Element(matrix[current.row][current.col + 1], current.row, current.col + 1));
        }
    }

    return minHeap.top().value;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = kthSmallest(matrix, k);
    cout << result << endl;

    return 0;
}

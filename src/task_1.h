#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMedian(std::vector<int>& arr, int start, int end) {
    vector<int> subarray(arr.begin() + start, arr.begin() + end + 1);
    sort(subarray.begin(), subarray.end());
    int mid = (subarray.size() - 1) / 2;
    return subarray[mid];
}

void solveTestCase() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int k = 0; k < N - 2; ++k) {
        int minMedian = INT_MAX;
        int minMedianIndex = -1;

        for (int i = 1; i < N - 1; i += 2) {
            int median = findMedian(arr, i - 1, i + 1);
            if (median < minMedian) {
                minMedian = median;
                minMedianIndex = i;
            }
        }

        arr.erase(arr.begin() + minMedianIndex);
        N -= 1;
    }

    int result = 0;
    for (int i = 0; i < N; ++i) {
        result += arr[i];
    }

    cout << result << std::endl;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        solveTestCase();
    }

    return 0;
}

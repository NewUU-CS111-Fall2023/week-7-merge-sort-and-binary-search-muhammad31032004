#include <iostream>
#include <vector>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int missingCount = 0;
    int currentNum = 1;
    int i = 0;

    while (missingCount < k) {
        if (i < arr.size() && arr[i] == currentNum) {
            i++;
        } else {
            missingCount++;
        }

        if (missingCount < k) {
            currentNum++;
        }
    }

    return currentNum;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = findKthPositive(arr, k);

    cout << result << endl;

    return 0;
}

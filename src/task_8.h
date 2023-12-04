#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(vector<int>& nums) {
    int n = nums.size();
    int totalSum = (n * (n + 1)) / 2;
    int arraySum = 0;

    for (int num : nums) {
        arraySum += num;
    }

    return totalSum - arraySum;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n - 1); 

    for (int i = 0; i < n - 1; ++i) {
        cin >> nums[i];
    }

    int missingNumber = findMissingNumber(nums);

    cout << "Missing Number: " << missingNumber << endl;

    return 0;
}

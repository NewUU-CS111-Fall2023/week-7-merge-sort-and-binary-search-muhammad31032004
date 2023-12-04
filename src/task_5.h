#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap;
    
    for (int num : nums) {
        frequencyMap[num]++;
    }
    
    vector<pair<int, int>> frequencyVector;
    for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
        frequencyVector.push_back({it->first, it->second});
    }

    sort(frequencyVector.begin(), frequencyVector.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(frequencyVector[i].first);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    vector<int> result = topKFrequent(nums, k);

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}

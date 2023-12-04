#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxBeautifulness(int n, vector<int>& Y) {
    vector<pair<int, int>> diff;

    for (int i = 0; i < n; ++i) {
        diff.push_back({Y[i] - i, i});
    }

    sort(diff.begin(), diff.end());

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        result += abs(diff[i].first - i);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> Y(n);
    for (int i = 0; i < n; ++i) {
        cin >> Y[i];
    }

    long long answer = maxBeautifulness(n, Y);

    cout << answer << endl;

    return 0;
}

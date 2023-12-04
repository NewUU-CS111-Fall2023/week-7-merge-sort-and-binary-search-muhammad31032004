#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int T, N, M;
    cin >> T;
    cin >> N >> M;
    int arr1[N];
    int arr2[M];
    vector<int> vector;
    while (T>0) {
        for (int i=0; i<N; i++) {
            cin >> arr1[i];
        }
        for (int i=0; i<M; i++) {
            cin >> arr2[i];
        }
        for (int i=0; i<N; i++) {
            vector.push_back(arr1[i]);
        }
        for (int i=0; i<M; i++) {
            vector.push_back(arr2[i]);
        }
        for (int i=0; i<vector.size(); i++) {
            for (int j=1; j<vector.size(); j++) {
                if (vector[i]>vector[j]) {
                    int b = vector[i];
                    vector[i] = vector[j];
                    vector[j] = b;
                }
            }
        }
        for (int i=0; i<N+M; i++) {
            cout << vector[i];
        }
        for (int i=0; i<N+M; i++) {
            vector.pop_back();
        }
        T--;
    }
    return 0;
}

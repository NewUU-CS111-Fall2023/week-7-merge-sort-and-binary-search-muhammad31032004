#include <iostream>

using namespace std;

int recursivePow(int x, int n) {
    if (n == 0) {
        return 1;
    }

    int halfPow = recursivePow(x, n / 2);
    int result = halfPow * halfPow;

    if (n % 2 == 1) {
        result *= x;
    }

    return result;
}

int main() {
    int x, n;
    cin >> x >> n;

    int result = recursivePow(x, n);

    cout << result << endl;

    return 0;
}

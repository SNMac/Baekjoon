#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int c;
        cin >> c;
        int q, d, n, p;
        q = c / 25;
        c %= 25;
        d = c / 10;
        c %= 10;
        n = c / 5;
        c %= 5;
        p = c;
        cout << q << ' ' << d << ' ' << n << ' ' << p << '\n';
    }
}

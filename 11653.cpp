#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1)
        return 0;

    int i = 2;
    while(1) {
        if (n == 1)
            break;
        if (n % i == 0) {
            cout << i << endl;
            n /= i;
            i = 2;
        } else
            i++;
    }
}
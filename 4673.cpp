#include <iostream>
#include <cmath>

using namespace std;

void d(int n, bool* selfArr) {
    int* arr = new int[5];
    int temp = n;
    for(int i = 4; i >= 0; i--) {
        arr[i] = temp / (int)pow(10, i);
        temp %= (int)pow(10, i);
    }

    int ret = n;
    for (int i = 0; i < 5; i++)
        ret += arr[i];
    delete[] arr;
    if (ret <= 10000) {
        selfArr[ret - 1] = false;
        d(ret, selfArr);
    } else
        return;
}

int main() {
    bool* self = new bool[10000];
    for (int i = 0; i < 10000; i++)
        self[i] = true;

    for (int i = 0; i < 10000; i++) {
        if (!self[i])
            continue;
        d(i + 1, self);
    }

    for (int i = 0; i < 10000; i++) {
        if (self[i])
            cout << i + 1 << endl;
    }
    delete[] self;
}
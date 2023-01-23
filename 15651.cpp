#include <iostream>

using namespace std;

int n, m;
int arr[8];
bool isUsed[8];

void dfs(int cur_digit) {
    if (cur_digit == m + 1) {
        for (int i = 1; i <= m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        isUsed[arr[cur_digit - 1]] = true;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!isUsed[i]) {
            arr[cur_digit] = i;
            dfs(cur_digit + 1);
            isUsed[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    dfs(1);
}
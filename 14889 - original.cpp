#include <iostream>
#include <vector>
#include <set>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

bool selected[21];
int S[21][21];
int N;
int s_member[10];
vector<int> s_stat;
vector<int> l_stat;
set<int> sl_diff;

void dfs(int count, int index) {
    if (count == N / 2) {
        int s_temp = 0;
        for (int i = 0; i < N / 2 - 1; i++) {  // 다 뽑은 상태
            for (int j = i + 1; j < N / 2; j++) {
                int s1 = s_member[i], s2 = s_member[j];
                s_temp += S[s1][s2] + S[s2][s1];
            }
        }
        s_stat.push_back(s_temp);

        vector<int> l_member;
        for (int i = 1; i <= N; i++) {
            if (!selected[i])
                l_member.push_back(i);
        }
        int l_temp = 0;
        for (int i = 0; i < l_member.size() - 1; i++) {
            for (int j = i + 1; j < l_member.size(); j++) {
                int l1 = l_member[i], l2 = l_member[j];
                l_temp += S[l1][l2] + S[l2][l1];
            }
        }
        l_stat.push_back(l_temp);
        return;
    }

    for (int i = index; i <= N; i++) {
        if (!selected[i]) {
            selected[i] = true;
            s_member[count] = i;
            dfs(count + 1, i);
            selected[i] = false;
        }
    }
}

int main() {
    FAST_IO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> S[i][j];
        }
    }
    dfs(0, 1);
    for (int i = 0; i < s_stat.size(); i++) {
        int diff = s_stat[i] - l_stat[i];
        if (diff < 0)
            diff *= -1;
        sl_diff.insert(diff);
    }
    cout << *sl_diff.begin() << '\n';
}

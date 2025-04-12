#include <bits/stdc++.h>
using namespace std;

int solve_case(const string& s) {
    int n = s.size();
    double best_cost = 1e18;
    int min_deletions = n;

    for (int len = 1; len <= 7; ++len) {
        vector<int> indices(len);
        iota(indices.begin(), indices.end(), 0);

        function<void(int, int)> backtrack = [&](int start, int depth) {
            if (depth == len) {
                string sub = "";
                int digit_sum = 0;
                for (int i = 0; i < len; ++i) {
                    sub += s[indices[i]];
                    digit_sum += s[indices[i]] - '0';
                }
                if (sub[0] == '0' || digit_sum == 0) return;
                long long value = stoll(sub);
                double cost = (double)value / digit_sum;
                int deletions = n - len;
                if (cost < best_cost || (abs(cost - best_cost) < 1e-9 && deletions < min_deletions)) {
                    best_cost = cost;
                    min_deletions = deletions;
                }
                return;
            }
            for (int i = start; i <= n - (len - depth); ++i) {
                indices[depth] = i;
                backtrack(i + 1, depth + 1);
            }
        };

        backtrack(0, 0);
    }

    return min_deletions;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve_case(s) << '\n';
    }

    return 0;
}

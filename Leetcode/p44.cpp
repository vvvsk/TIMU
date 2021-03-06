#include "bits/stdc++.h"

using namespace std;

bool isMatch(const char *s, const char *p) {
    int m = strlen(s);
    int n = strlen(p);
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        if (p[i - 1] == '*') {
            dp[0][i] = dp[0][i - 1];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*' && (dp[i - 1][j] || dp[i][j - 1])) {
                dp[i][j] = true;
            } else {
                if (p[j - 1] == '?' && dp[i - 1][j - 1]) {
                    dp[i][j] = true;
                } else if (p[j - 1] == s[i - 1] && dp[i - 1][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
    }
    return dp[m][n];
}

bool isMatch(const char *s, const char *p) {
    int i = 0, j = 0, i_Star = -1, j_Star = -1;
    int m = strlen(s), n = strlen(p);
    while (i < m) {
        if (j < n && (s[i] == p[j] || p[j] == '?')) {
            i++;
            j++;
        } else if (j < n && p[j] == '*') {
            i_Star = i;
            j_Star = j;
            j++;
        } else if (i_Star >= 0) {
            i_Star++;
            i = i_Star;
            j = j_Star + 1;
        } else {
            return false;
        }
    }
    while (j < n && p[j] == '*') {
        j++;
    }
    return j == n;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// Maximum Number of Non-overlapping Palindrome Substrings
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T& x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T& x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T& x) {
    int f = 1;
    x = 0;
    char s = getchar();
    while (s < '0' || s > '9') {
        if (s == '-')
            f = -1;
        s = getchar();
    }
    while (s <= '9' && s >= '0')
        x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

class Solution {
public:
    int f[2005];
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // STEP 1: palindrome table
        vector<vector<bool>> ok(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
            ok[i][i] = true;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len == 2)
                        ok[i][j] = true;
                    else
                        ok[i][j] = ok[i + 1][j - 1];
                }
            }
        }

        // STEP 2: DP
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1]; // skip

            for (int j = i + k - 1; j < n; j++) {
                if (ok[i][j]) {
                    dp[i] = max(dp[i], 1 + dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
}; 
link -:https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
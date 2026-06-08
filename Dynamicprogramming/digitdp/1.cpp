


class Solution {

public:
    long long dp[105][2][2][2][11];
    const int MOD=1e9+7;
    long long solve(int pos, int tLow, int tHigh, int started, int last,
                    string& L, string& R) {

        if (pos == L.size())
            return started;

        if (dp[pos][tLow][tHigh][started][last] != -1)
            return dp[pos][tLow][tHigh][started][last];

        int low = tLow ? L[pos] - '0' : 0;
        int high = tHigh ? R[pos] - '0' : 9;

        long long ans = 0;

        for (int d = low; d <= high; d++) {

            int newLow = tLow && (d == low);
            int newHigh = tHigh && (d == high);

            if (!started && d == 0) {
                ans = (ans + solve(pos + 1, newLow, newHigh, 0, 0, L, R)) % MOD;
            } else if (!started) {
                ans = (ans + solve(pos + 1, newLow, newHigh, 1, d, L, R)) % MOD;
            } else {
                if (abs(d - last) == 1) {
                    ans = (ans + solve(pos + 1, newLow, newHigh, 1, d, L, R)) %
                          MOD;
                }
            }
        }
        return dp[pos][tLow][tHigh][started][last]=ans;

    }
    int countSteppingNumbers(string low, string high) {
        while (low.size() < high.size())
            low = '0' + low;
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 1, 0, 0, low, high);
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {

        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        const long long NEG = -4e18;

        vector<long long> prev(n + 1, 0);

        for (int k = 1; k <= m; k++) {

            vector<long long> cur = prev;
            deque<int> dq;

            for (int i = 1; i <= n; i++) {

                cur[i] = max(cur[i], cur[i - 1]);

                int add = i - l;

                if (add >= 0) {

                    long long val = prev[add] - pref[add];

                    while (!dq.empty() &&
                           prev[dq.back()] - pref[dq.back()] <= val)
                        dq.pop_back();

                    dq.push_back(add);
                }

                while (!dq.empty() && dq.front() < i - r)
                    dq.pop_front();

                if (!dq.empty()) {
                    cur[i] = max(
                        cur[i],
                        pref[i] +
                        (prev[dq.front()] - pref[dq.front()])
                    );
                }
            }

            prev = move(cur);
        }

        // remove empty selection
        if (prev[n] == 0) {
            long long best = NEG;
            for (int i = 0; i < n; i++) {
                long long s = 0;
                for (int len = l; len <= r && i + len <= n; len++) {
                    s = pref[i + len] - pref[i];
                    best = max(best, s);
                }
            }
            if (best < 0) return best;
        }

        return prev[n];
    }
};

class Solution {
public:
    using ll=long long;
    int smallestUniqueSubarray(vector<int>& nums){
        int n = nums.size();

        const ll base = 911382323;
        const ll mod = 1e9 + 7;

        vector<ll> power(n + 1, 1);
        vector<ll> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            power[i + 1] = (power[i] * base) % mod;
            pref[i + 1] =
                (pref[i] * base + nums[i] + 1007) % mod;
        }

        auto getHash = [&](int l, int r) {

            ll val =
                (pref[r + 1] -
                 (pref[l] * power[r - l + 1]) % mod +
                 mod) % mod;

            return val;
        };

        auto check = [&](int len) {

            map<ll, int> mp;
            for (int i = 0; i + len - 1 < n; i++) {

                ll h = getHash(i, i + len - 1);

                mp[h]++;
            }

            for (auto &it : mp) {
                if (it.second == 1)
                    return true;
            }

            return false;
        };

        int low = 1;
        int high = n;
        int ans = n;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
        
    }
};
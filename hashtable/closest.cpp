class Solution {
public:
    vector<int>solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> result;

        for (int index : queries) {
            int val = nums[index];
            vector<int>& temp = mp[val];

            int m = temp.size();

            if (m == 1) {
                result.push_back(-1);
                continue;
            }

            int pos = lower_bound(temp.begin(), temp.end(), index) - temp.begin();
            int nextIdx = temp[(pos + 1) % m];
            int prevIdx = temp[(pos - 1 + m) % m];
            int d1 = abs(nextIdx - index);
            int d2 = abs(prevIdx - index);

            int ans = min({d1, n - d1, d2, n - d2});

            result.push_back(ans);
        }

        return result;
    }
};
// Created by  on 2024/6/11.
/// https://leetcode.cn/problems/sum-of-distances/description/
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<long long> result(n, 0);
        for (auto v : mp) {
            if (v.second.size() == 1)
                continue;
            vector<int>& res = v.second;
            int k= res.size();
            vector<long long> prefix(res.size(), 0);
            prefix[0] = res[0];

            for (int i = 1; i < k; i++) {
                prefix[i] = prefix[i - 1] + res[i];
            }

            for (int i = 0; i < k; i++) {
                long long left = 0, right = 0;

                if (i > 0) {
                    left = (long long)res[i] * i - prefix[i - 1];
                }

                if (i < k - 1) {
                    right = (prefix[k - 1] - prefix[i]) -
                            (long long)res[i] * (k - i - 1);
                }
                result[res[i]]= left+right;
            }
           
        }
        return result;
    }
};
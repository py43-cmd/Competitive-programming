class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        long long maxi_sum = 0;
        long long sum = 0;
        unordered_map<int, int> mp;
        for (int j = 0; j < n; j++) {
            while (mp.count(nums[j])|| j - i + 1 > k) {
                sum -= nums[i];
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            if (mp.empty() || !mp.count(nums[j])) {
                sum += nums[j];
                mp[nums[j]]++;
            }

            if (mp.size() == k) {
                maxi_sum = max(maxi_sum, sum);
            }
        }
        return maxi_sum;
    }
};
link-:https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/    
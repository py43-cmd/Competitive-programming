
class Solution {
public:
    int dp[100001][2][100];
    int slove(int start, bool canbuy, vector<int>& prices, int count, int n,int k) {
        if (start >= n)
            return 0;
        if (count >= k)
            return 0;
        if (dp[start][canbuy][count] != -1)
            return dp[start][canbuy][count];
        if (canbuy) {
            int take = -prices[start] + slove(start + 1, 0, prices, count, n,k);
            int skip = slove(start + 1, 1, prices, count, n,k);
            return dp[start][canbuy][count] = max(take, skip);
        } else {
            int take =
                prices[start] + slove(start + 1, 1, prices, count + 1, n,k);
            int skip = slove(start + 1, 0, prices, count, n,k);
            return dp[start][canbuy][count] = max(take, skip);
        }
        return dp[start][canbuy][count];
    }
    int maxProfit(int k,vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        int n=prices.size();
        return slove(0,true,prices,0,n ,k);


    }
};
// Best Time to Buy and Sell Stock IV;
// url - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
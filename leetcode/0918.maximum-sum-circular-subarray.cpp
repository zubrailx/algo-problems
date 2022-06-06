class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
      int n = nums.size();
      // one-interval subarrays
      vector<int> dp(n);
      dp[0] = nums[0];
      int ans = nums[0];
      for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i - 1], 0) + nums[i];
        ans = max(ans, dp[i]);
      }

      // max cursum from right to left
      vector<int> currightmx(n);
      int curright = nums[n - 1];
      currightmx[n - 1] = nums[n - 1];
      for (int i = n - 2; i >= 0; --i) {
        curright += nums[i];
        currightmx[i] = max(currightmx[i + 1], curright);
      }

      int curleft = 0;
      for (int i = 0; i < n - 1; ++i) {
        curleft += nums[i];
        ans = max(ans, curleft + currightmx[i + 1]);
      }
      return ans;
    }
};
/*
int another(vector<int>& nums) {
  int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
  for (int& a : A) {
    curMax = max(curMax + a, a);
    maxSum = max(maxSum, curMax);
    curMin = min(curMin + a, a);
    minSum = min(minSum, curMin);
    total += a;
  }
  return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
}
*/

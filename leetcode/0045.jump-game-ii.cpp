// O(n * max_jump)
int o_n_max_jump(vector<int>&nums) {
  int n = nums.size();
  vector<int> dp(n, INT_MAX);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= nums[i] && i + j < n; ++j) {
      dp[i + j] = min(dp[i + j], dp[i] + 1);
    }
  }
  return dp[n - 1];
}

// O(n)
int o_n(vector<int> &nums) {
  int n = nums.size();
  int jumps = 0;
  int cur_end = 0;
  int next_end = 0;
  for (int i = 0; i < n - 1; ++i) {
    next_end = max(next_end, i + nums[i]);
    if (cur_end == i) {
      ++jumps;
      cur_end = next_end;
    }
  }
  return jumps;
}

class Solution {
public:
    int jump(vector<int>& nums) {
      //return o_n_max_jump(nums);
      return o_n(nums);
    }
};

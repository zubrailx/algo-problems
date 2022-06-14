class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
      int ans = INT_MAX;
      int cur = 0;
      for (int left = 0, right = 0; right < nums.size(); ++right) {
        cur += nums[right];
        if (cur >= k) {
          while (cur - nums[left] >= k) {
            cur -= nums[left];
            ++left;
          }
          ans = min(ans, right - left + 1);
        }
      }
      return ans == INT_MAX ? 0 : ans;
    }
};

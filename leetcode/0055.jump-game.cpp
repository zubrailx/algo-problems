class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      int last_pos = 0;
      for (int i = 0; i < n; ++i) {
        if (last_pos < i) return false;
        last_pos = max(last_pos, i + nums[i]);
      }
      return true;
    }
};

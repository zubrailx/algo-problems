class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) { return nums[0]; }
    
    int pprev = 0, prev = 0;
    int tmp;
    for (int i = 0; i < nums.size() - 1; ++i) {
      tmp = max(prev, pprev + nums[i]);
      pprev = prev;
      prev = tmp;
    }
    int mx = prev;
    pprev = 0, prev = 0;
    for (int i = 1; i < nums.size(); ++i) {
      tmp = max(prev, pprev + nums[i]);
      pprev = prev;
      prev = tmp;
    }
    mx = max(mx, prev);
    return mx;
  }
};

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
      vector<int> pd(nums.size(), 0);
      pd[0] = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        pd[i] = pd[i - 1] + nums[i];
      }
      return pd;
    }
};


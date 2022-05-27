class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int left, right, n = nums.size();
      vector<int> result(n);
      left = 0, right = n - 1;
      
      int idx = n - 1;
      while (idx >= 0) {
        if (abs(nums[left]) > abs(nums[right])) {
          result[idx] = pow(nums[left], 2);
          ++left;
        } else {
          result[idx] = pow(nums[right], 2);
          --right;
        }
        --idx;
      }
      return result;
    }
};

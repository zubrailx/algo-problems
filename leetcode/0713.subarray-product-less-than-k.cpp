// interesting... the substrings are those what start from the `right` till the left + 1
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      int cnt = 0;
      int prod = 1;
      for (int left = 0, right = 0; right < nums.size(); ++right) {
        prod *= nums[right];
        while (left <= right && prod >= k) {
          prod /= nums[left];
          ++left;
        }
        cnt += right - left + 1;
      }
      return cnt;
    }
};

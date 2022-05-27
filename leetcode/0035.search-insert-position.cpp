class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int start = 0, end = nums.size() - 1, idx;
      while (start <= end) {
        idx = start + (end - start) / 2;
        if (nums[idx] > target) {
          end = idx - 1;
        } else if (nums[idx] < target) {
          start = idx + 1;
        } else {
          return idx;
        }
      }
      return start;
    }
};

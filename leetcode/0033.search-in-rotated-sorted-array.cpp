// algorithm:
//   find using binary search where is offset
//   just use binary search to find target
//
// another interesting solution:
// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14435/Clever-idea-making-it-simple
class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      // find offset
      int off;
      if (nums[0] <= nums[n - 1]) {
        off = 0;
      } else {
        int l = 0, r = n - 1, i; 
        while (l + 1 != r) {
          i = l + (r - l) / 2;
          if (nums[i] > nums[l]) {
            l = i;
          } else {
            r = i;
          }
        }
        off = r;
      }
      // find offseted target
      int s = off, e = n - 1 + off, i;
      while (s <= e) {
        i = s + (e - s) / 2;
        if (nums[i % n] > target) {
          e = i - 1;
        } else if (nums[i % n] < target) {
          s = i + 1;
        } else {
          return (i % n);
        }
      }
      return -1;
    }
};

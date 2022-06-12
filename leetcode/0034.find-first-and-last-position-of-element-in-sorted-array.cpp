// can be optimized using only 2 binary searches but idc

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int n = nums.size();
      int s = 0, e = nums.size() - 1, i;
      int ret = -1;
      while (s <= e) {
        i = s + (e - s) / 2;
        if (nums[i] > target) {
          e = i - 1;
        } else if (nums[i] < target) {
          s = i + 1;
        } else {
          ret = i;
          break;
        }
      }
      if (ret == -1) {
        vector<int> res(2);
        res[0] = -1;
        res[1] = -1;
        return res;
      }

      vector<int> res(2);
      // find left bound of targrt
      s = -1, e = ret;
      while (s + 1 != e) {
        i = s + (e - s) / 2;
        if (nums[i] != target) {
          s = i;
        } else {
          e = i;
        }
      }
      res[0] = e;
      // find right bound of target
      s = ret, e = n;
      while (s + 1 != e) {
        i = s + (e - s) / 2;
        if (nums[i] != target) {
          e = i;
        } else {
          s = i;
        }
      }
      res[1] = s;
      return res;
    }
};

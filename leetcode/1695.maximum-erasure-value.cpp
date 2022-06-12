// can also be done using set without pointing to i of nums[i] position
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
      int n = nums.size();
      unordered_map<int, int> vp;
      int start = 0;
      int cursum = 0;
      int mxsum = 0;
      for (int i = 0; i < n; ++i) {
        auto it = vp.find(nums[i]);
        if (it != vp.end()) {
          for (; start <= it->second; ++start) {
            cursum -= nums[start];
          }
          vp.erase(it);
        }
        vp.emplace(nums[i], i);
        cursum += nums[i];
        mxsum = max(mxsum, cursum);
      }
      return mxsum;
    }
};

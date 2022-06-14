// first can fix first and second pointer and use set to find third one whose index larger than e
//
// another solution:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> result;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < n - 2; ++i) {
        int ir = n - 1;
        int il = i + 1;
        while (il < ir) {
          int sm = nums[i] + nums[il] + nums[ir];
          if (sm > 0) --ir; 
          else if (sm < 0) ++il;
          else {
            result.push_back({nums[i], nums[il], nums[ir]});
            // restore pointers
            int prev = nums[il];
            while (il < n && nums[il] == prev) ++il;
            prev = nums[ir];
            while (il < ir && nums[ir] == prev) --ir;
          }
        }
        while (i < n - 1 && nums[i] == nums[i + 1]) i++;
      }
      return result;
    }
};

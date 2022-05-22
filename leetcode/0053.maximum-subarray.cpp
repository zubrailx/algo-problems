// broot force: calculate all intervals and find max
// complexity: 
// time:O(n^2)
// memory: O(1)
// this problem is equals to stirng substrs

// dynamic programming
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int mx = nums[0];
      // previous element (cuz in dp we need to store only the previous step)
      int prev = nums[0];
      
      for (int i = 1; i < nums.size(); ++i) {
        prev = nums[i] + max(prev, 0);
        if (prev > mx) {
          mx = prev;
        }
      }
      return mx;
    }
};


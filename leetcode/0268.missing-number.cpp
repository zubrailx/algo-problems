class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n = nums.size();
      int rs = n * (n + 1) / 2;
      int s = 0;
      for (auto num : nums) {
        s += num;
      }
      return rs - s;
    }
};

// also can be solved using xor operation

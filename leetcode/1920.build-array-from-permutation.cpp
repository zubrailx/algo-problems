class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
      vector<int> array(nums.size());
      for (int i = 0; i < nums.size(); ++i) {
        array[i] = nums[nums[i]];
      }
      return array;
    }
};


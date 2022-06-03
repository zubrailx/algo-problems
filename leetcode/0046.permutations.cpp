class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> result;
      recursion(result, 0, nums);
      return result;
    }
  
    void recursion(vector<vector<int>> &result, int idx, vector<int> &nums) {
      if (idx >= nums.size()) {
        result.push_back(nums);
        return;
      }
      for (int i = idx; i < nums.size(); ++i) {
        swap(nums[idx], nums[i]);
        recursion(result, idx + 1, nums);
        swap(nums[idx], nums[i]);
      }
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      return nums[nums.size() - k];
    }
};

// can also be solved using partition (like in quick sort)

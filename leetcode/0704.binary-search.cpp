int less_than_minimum(vector<int> &nums, int target) {
  if (target > nums[nums.size() - 1] || target < nums[0]) { return -1; }
  
  int start, end, idx;

  start = -1; end = nums.size() - 1;
  while (start + 1 != end) {
    idx = start + (end - start) / 2;
    if (target > nums[idx]) {
      start = idx;
    } else {
      end = idx;
    }
  }
  return nums[end] == target ? end : -1;
}

int more_than_maximum(vector<int> &nums, int target) {
  if (target > nums[nums.size() - 1] || target < nums[0]) { return -1; }
  
  int start, end, idx;
  
  start = 0; end = nums.size();
  while (start + 1 != end) {
    idx = start + (end - start) / 2;
    if (target < nums[idx]) {
      end = idx;
    } else {
      start = idx;
    }
  }
  return nums[start] == target ? start : -1;
}

int correct_bounds(vector<int> &nums, int target) {
  int start, end, idx;
  start = 0; end = nums.size() - 1;
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
  return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
      //return less_than_minimum(nums, target);
      //return more_than_maximum(nums, target);
      return correct_bounds(nums, target);
    }
};

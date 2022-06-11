// time limit
class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    unordered_map<int, int> vc;
    return calculate(vc, nums, x, 0, nums.size() - 1);
  }

  int calculate(unordered_map<int,int> &vc, vector<int> &nums, int x, int left, int right) {
    if (x == 0) { return 0; }
    if (x < 0 || left > right) { return -1; }

    int calc_right = 1 + calculate(vc, nums, x - nums[right], left, right - 1);
    int calc_left = 1 + calculate(vc, nums, x - nums[left], left + 1, right);

    if (!calc_right && !calc_left) { return -1; }
    if (!calc_right) { return calc_left; }
    if (!calc_left) { return calc_right; }
    return min(calc_left, calc_right);
  }
};


// upgraded sliding window without size just to care about overflow
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int n = nums.size();
      int left = 0;
      while (left < n && x > 0) {
        x -= nums[left++];
      }
      if (x > 0) { return -1; }
      int result = x == 0 ? left : INT_MAX;
      --left;
      for (int right = n; left >= 0;) {
        x += nums[left--];
        while (x > 0) { 
          x -= nums[--right];
        }
        if (x == 0) { result = min(result, left + 1 + n - right); }
      }
      return result == INT_MAX ? -1 : result;
    }
};

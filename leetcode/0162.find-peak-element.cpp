/*
class Solution {
public:
  int n;
  vector<int> nums;

  int get_val(int i) {
    if (i == -1) { return INT_MIN; }
    if (i == n) { return INT_MIN; }
    return nums[i];
  }

  int get_peak_off(int i) {
    int a = get_val(i - 1);
    int b = get_val(i);
    int c = get_val(i + 1);
    if (b < a) { return -1; }
    if (b < c) { return 1; }
    return 0;
  }

  int findPeakElement(vector<int>& nums) {
    this->nums = nums;
    this->n = nums.size();
    int s = 0, e = n - 1, i;
    while (s <= e) {
      i = s + (e - s) / 2;
      int p = get_peak_off(i);
      if (p == 0) { return i; }
      else if (p > 0) { 
        s = i + 1;
      } else {
        e = i - 1;
      }
    }
    return i;
  }
};
*/

// can be done cuz all elements are unique
class Solution {
public:
  int findPeakElement(const vector<int> &num) {
    int left = 0;
    int right = num.size() - 1;
    
    int idx;
    while (left < right) {
      idx = left + (right - left) / 2;
      if (num[idx] < num[idx + 1]) {
        left = idx + 1;
      } else {
        right = idx;
      }
    }
    return left;
  }
};


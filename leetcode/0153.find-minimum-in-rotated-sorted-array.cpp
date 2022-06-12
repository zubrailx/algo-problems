class Solution {
public:
    int findMin(vector<int>& nums) {
      int n = nums.size();
      if (nums[0] <= nums[n - 1]) {
        return nums[0];
      } else {
        int s = 0, e = n - 1, i;
        while (s + 1 != e) {
          i = s + (e - s) / 2;
          if (nums[i] > nums[s]) {
            s = i;
          } else {
            e = i;
          }
        }
        return nums[e];
      }
    }
};
/*
int findMin(vector<int> &num) {
  int s = 0, end = num.size() - 1;
  while (s < e) {
    // without offset
    if (num[s] < num[e])
      return num[s];
    
    int mid = s + (e - s) / 2;
    
    if (num[mid] >= num[s]) {
      s = mid + 1;
    } else {
      e = mid;
    }
  }
  
  return num[s];
}
*/

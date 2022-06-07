/*
// algorithm using queue 

void print_array(vector<int>& arr) {
  for (auto a : arr) {
    cout << a << " ";
  }
  cout << endl;
}

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int j = 0;
    int i = 0;
    queue<int> queue;
    while (i < m + n) {
      if (!queue.empty()) {
        if (i < m) {  queue.push(nums1[i]); }
        
        if (j >= n || queue.front() <= nums2[j]) {
          nums1[i] = queue.front();
          queue.pop();
        } else {
          nums1[i] = nums2[j];
          ++j;
        }
      }  else if (i < m) {
        if (j < n && nums1[i] > nums2[j]) {
          queue.push(nums1[i]);
          nums1[i] = nums2[j];
          ++j;
        } else {
          // do nothing
        }
      } else {
        nums1[i] = nums2[j];
        ++j;
      }
      ++i;
      //print_array(nums1);
    }
  }
};
*/

// new solution
class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, p = m + n - 1;
    for (; i >= 0 && j >= 0; --p) {
      if (nums1[i] >= nums2[j]) {
        nums1[p] = nums1[i];
        --i;
      } else {
        nums1[p] = nums2[j];
        --j;
      }
    }
    while (i >= 0) {
      nums1[p--] = nums1[i--];
    }
    while (j >= 0) {
      nums1[p--] = nums2[j--];
    }
  }
};


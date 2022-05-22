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


// oh, it could be done from ent the end of array... without queue

// binary search (also can be solved using lineur, but in that case need to store last and last_last elements)
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // first one should be larger
    if (nums1.size() < nums2.size()) 
      nums1.swap(nums2);
    
    // binary search algorithm
    int s1 = nums1.size();
    int s2 = nums2.size();
    
    int start = 0;
    int end = nums2.size();
    int med;
    
    int l1, l2;
    // mx1 -max 1 (left side from l1)
    // mn1 - min 1 (right side from l1)
    int mx1, mn1, mx2, mn2;
    while (start <= end) {
      l2 = (start + end + 1) / 2;
      l1 = (s1 + s2 + 1) / 2 - l2;
      
      cout << l1 << " " << l2 << endl;
      mx1 = l1 == 0 ? INT_MIN : nums1[l1 - 1];
      mn1 = l1 == s1 ? INT_MAX : nums1[l1];
      mx2 = l2 == 0 ? INT_MIN : nums2[l2 - 1];
      mn2 = l2 == s2 ? INT_MAX : nums2[l2];
      
      if (mx1 <= mn2 && mx2 <= mn1) {
        if ((s1 + s2) % 2 == 0) {
          return ((double)max(mx1, mx2) + min(mn1, mn2)) / 2;
        } else {
          return max(mx1, mx2);
        }
      } else if (mx2 > mn1) {
        end = l2 - 1;
      } else {
        start = l2 + 1;
      }
    }
    return INT_MAX;
  }
};

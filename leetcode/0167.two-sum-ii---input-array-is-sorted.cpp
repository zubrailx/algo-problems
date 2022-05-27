// no hashset :(
class Solution {
public:
    vector<int> twoSum(vector<int>& ns, int target) {
    int left = 0, right = ns.size() - 1; 
      while(left != right) {
        if (ns[left] + ns[right] < target) {
          ++left;
        } else if (ns[left] + ns[right] > target) {
          --right;
        } else {
          return vector<int>{left + 1, right + 1};
        }
      }
      return vector<int>();
    }
};

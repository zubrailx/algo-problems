#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      // create vector of indexes
      vector<int> indexes(nums.size());
      for (int i = 0; i < nums.size(); ++i) {
        indexes[i] = i;
      }
      
      // create custom comparator
      auto comp = [&nums](int lsv, int rsv) {
        return nums[lsv] < nums[rsv];
      };
      std::sort(indexes.begin(), indexes.end(), comp);      
      
      // test
      for (int i = 0; i < nums.size(); ++i) {
        cout << nums[indexes[i]] << " ";
      }
      
      int start = 0;
      int end = nums.size() - 1;
      int val;
      while (start != end) {
        val = nums[indexes[start]] + nums[indexes[end]];
        if (val == target) {
          break;
        } else if (val > target) {
          --end;
        } else {
          ++start;
        }
      }
      vector<int> result(2);
      result[0] = indexes[start];
      result[1] = indexes[end];
      return result;
    }
};

// also can be solved using hashtable 


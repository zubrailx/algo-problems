// can store keys as keys and values as key * num_val
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      unordered_map<int, int> points;
      for (auto num : nums) {
        points[num] += num;
      }
      
      vector<int> keys(points.size());
      for (auto [it, i] = tuple{points.begin(), 0}; it != points.end(); ++it, ++i) {
        keys[i] = it->first;
      }
      sort(keys.begin(), keys.end());
      
      // bottom-up
      int two_back = 0, one_back = points[keys[0]];
      int tmp;
      for (int i = 1; i < keys.size(); ++i) {
        tmp = max((keys[i] - keys[i - 1] == 1 ? two_back : one_back) + points[keys[i]], one_back);
        two_back = one_back;
        one_back = tmp;
      }
      return one_back;
    }
};

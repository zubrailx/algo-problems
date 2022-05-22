class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> idk;
      for (auto a : nums) {
        if (idk.find(a) != idk.end()) {
          return true;
        }
        idk.insert(a);
      }
      return false;
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      vector<int> db(n, 0);
      db[0] = nums[0];
      for (int i = 1; i < n; ++i) {
        db[i] = max(db[i - 1], nums[i]);
        for (int j = 0; j < i - 1; ++j) {
          db[i] = max(db[i], db[j] + nums[i]);
        }
      }
      return db[n - 1];
    }
};
// can only store previous value or prev-prev value, no difference

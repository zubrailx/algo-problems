class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int pprev = 0;
      int prev = cost[0];
      for (int i = 1; i < cost.size(); ++i) {
        int tmp = min(prev, pprev) + cost[i];
        pprev = prev;
        prev = tmp;
      }
      return min(prev, pprev);
    }
};

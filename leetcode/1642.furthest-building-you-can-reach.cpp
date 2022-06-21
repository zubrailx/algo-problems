class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int, std::vector<int>, greater<int>> ladders_queue;
    int cur_bricks = 0;
    int i = 1;
    for (; i < heights.size(); ++i) {
      int j = heights[i] - heights[i - 1];
      if (j <= 0) { continue; }

      if (ladders_queue.size() < ladders) {
        ladders_queue.push(j);
        continue;
      }
      if (ladders_queue.empty()) {
        cur_bricks += j;
      } else {
        int top = ladders_queue.top();
        if (top < j) {
          ladders_queue.pop();
          ladders_queue.push(j);
          cur_bricks += top;
        } else {
          cur_bricks += j;
        }
      }
      if (cur_bricks > bricks) { break; }
    }
    return i - 1;
  }
};

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
      sort(courses.begin(), courses.end(), [](vector<int> &lsv, vector<int> &rsv) {
        return lsv[1] < rsv[1];
      });
      priority_queue<int, vector<int>, less<>> durations;
      int ct = 0;
      for (auto & course : courses) {
        if (ct + course[0] <= course[1]) {
          durations.push(course[0]);
          ct += course[0];
        } else {
          if (!durations.empty() && durations.top() > course[0]) {
            ct -= durations.top() - course[0];
            durations.pop();
            durations.push(course[0]);
          }
        }
      }
      return durations.size();
    }
};

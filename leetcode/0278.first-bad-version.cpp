// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      int start, end, idx;
      start = 1; end = n;
      while (start < end) {
        idx = start + (end - start) / 2;
        if (isBadVersion(idx)) {
          end = idx;
        } else {
          start = idx + 1;
        }
      }
      return end;
    }
};

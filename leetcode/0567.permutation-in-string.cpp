int arr[26];

void print_window() {
  for (int i = 0; i < 26; ++i) {
    cout << arr[i] << " ";
  } 
  cout << endl;
}

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if (s1.size() > s2.size()) return false;
      
      memset(arr, 0, sizeof(arr));
      for (auto c : s1) {
        arr[c - 'a'] += 1;
      }
      for (int i = 0; i < s1.size() - 1; ++i) {
        arr[s2[i] - 'a'] -= 1;
      }
      //print_window();
      
      bool found = false;
      for (int i = s1.size() - 1; !found && i < s2.size(); ++i) {
        // add element to the window
        arr[s2[i] - 'a'] -= 1;
        int count = 0;
        for (int j = 0; j < 26; ++j) {
          count += (arr[j] != 0);
        }
        //print_window();
        found = !count;
        // remove element from the window
        arr[s2[i - s1.size() + 1] - 'a'] += 1;
      }
      return found;
    }
};


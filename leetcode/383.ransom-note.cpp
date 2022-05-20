#include <unordered_map>
#include <string>

using namespace std;

// using unordered_map
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      int magazine_arr[26];
      
      unordered_map<char, int> magazine_map;
      for (char c : magazine) {
        auto it = magazine_map.find(c);
        if (it == magazine_map.end()) {
          magazine_map.insert({c, 1});
        } else {
          it->second += 1;
        }    
      }
      for (char c : ransomNote) {
        auto it = magazine_map.find(c);
        if (it == magazine_map.end()) { return false; }
        if (it->second-- == 0) { return false; }
      }
      return true;
    }
};

// using const size array (same speed)
/*
* #include <unordered_map>
* 
* class Solution {
* public:
*     bool canConstruct(string ransomNote, string magazine) {
*       // init with zeroes
*       int magazine_arr[26] = {};
*       for (char c : magazine) {
*         magazine_arr['z' - c] += 1;
*       }
*       
*       for (char c : ransomNote) {
*         if (magazine_arr['z' - c]-- == 0) { return false; } 
*       }
*       return true;
*     }
* };
*/

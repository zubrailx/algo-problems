class Solution {
public:
    vector<string> fizzBuzz(int n) {
      vector<string> fizzbuzz;
      for (int i = 1; i < n + 1; ++i) {
        if (i % 3 == 0 && i % 5 == 0) {
          fizzbuzz.push_back("FizzBuzz");
        } else if (i % 3 == 0) {
          fizzbuzz.push_back("Fizz");   
        } else if (i % 5 == 0) {
          fizzbuzz.push_back("Buzz");
        } else {
          fizzbuzz.push_back(std::to_string(i));
        }
      }
      return fizzbuzz;
    }
};


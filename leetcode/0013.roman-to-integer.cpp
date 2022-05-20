#include <iostream>
#include <string>

using namespace std;

int gifrc(char c) 
{
  switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
  }
  return 0;
}

int solution(string str) {
  long result = 0; 
  for (int i = 0; i < str.length(); ++i) {
    char c;
    c = str[i];
    result += gifrc(c);

    if ((c == 'I' || c == 'X' || c == 'C') && (i < str.length() - 1)) {
      char next;
      next = str[i + 1];
      if (((next == 'V' || next == 'X') && c == 'I') ||
          ((next == 'L' || next == 'C') && c == 'X') ||
          ((next == 'D' || next == 'M') && c == 'C')) {
        result += gifrc(next) - 2 * gifrc(c);
        ++i;
      }      
    }
  }
  return result;
}


int main() 
{
  string str;
  cin >> str;
  std::cout << solution(str) << std::endl;
}


// brute force without recursion

/* maximum amount of each coun can be calculated as (amount / coin_denomination) = k
Let's try to take 0-k coins for each coin (calculated with each denomination) as find minimum
*/

/*
int calculate_registers_equals(const vector<int>& rslt, const vector<int>& cur) {
  int result = 0;
  for (int i = 0; i < cur.size(); ++i) {
    result += rslt[i] == cur[i];
  }
  return result;
}

int get_nominal(const vector<int>& cur, vector<int>& coins) {
  int result = 0;
  for (int i = 0; i < cur.size(); ++i) {
    result += cur[i] * coins[i];
  }
  return result;
}

void print_array(const vector<int>&cur) {
  for (int i = 0; i < cur.size(); ++i) {
    cout << cur[i] << " ";
  }
  cout << endl;
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      if (amount == 0) { return 0; }
      if (amount < 0 || coins.size() == 0) { return -1; }
      
      // calculate maximum count of coins
      vector<int> max_coin_count;
      for (int i = 0; i < coins.size(); ++i) {
        max_coin_count.push_back(amount / coins[i]);
      }
      
      // current coins that we have
      vector<int> current_coin_count;
      for (int i = 0; i < coins.size(); ++i) {
        current_coin_count.push_back(0);
      }
      current_coin_count[0] = -1;
      
      int min_count = 1 << 30;
      // bytewise enumeration for current_coin_count until it equals max_coin_count
      int registers_equals = 0; 
      while (registers_equals != max_coin_count.size()) {
        current_coin_count[0] += 1;
        int over = 0;
        while (current_coin_count[over] > max_coin_count[over]) {
          current_coin_count[over] = 0;
          current_coin_count[over + 1] += 1;
          over += 1;
        }
        
        int nominal = get_nominal(current_coin_count, coins);
        if (nominal == amount) {
          int coin_count = 0;
          for (int i = 0; i < coins.size(); ++i) {
            coin_count += current_coin_count[i];
          }
          if (coin_count < min_count) {
            min_count = coin_count;
          }
        }
        int it = coins.size() - 1 - registers_equals;
        while (it >= 0 && current_coin_count[it] == max_coin_count[it]) {
          ++registers_equals;
          --it;
        }
      }
      return min_count == 1 << 30 ? -1 : min_count;
    }
};
*/

// dynamic programming top-down
class Solution {
public:
  int coinChange(vector<int>& coins, int amount, vector<int>&coin_arr) {
    if (amount < 0) { return -1; }
    if (coin_arr[amount] != -2) { return coin_arr[amount]; }
    // for each coin lets calculate min
    int min_result = 1 << 30;
    int cur_result;
    for (int i = 0; i < coins.size(); ++i) {
      cur_result = coinChange(coins, amount - coins[i], coin_arr);
      if (cur_result != -1 && cur_result < min_result) {
        min_result = cur_result;
      }
    }
    coin_arr[amount] = min_result == 1 << 30 ? -1 : min_result + 1;
    return coin_arr[amount]; 
  } 
  
  int coinChange(vector<int>& coins, int amount) {
    // init array
    vector<int> coin_arr(amount + 1);
    coin_arr[0] = 0;
    for (int i = 1; i < coin_arr.size(); ++i) {
      coin_arr[i] = -2;
    }
    // 0 - amount-1
    return coinChange(coins, amount, coin_arr);
  }
};


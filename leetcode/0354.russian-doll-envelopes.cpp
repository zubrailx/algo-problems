// O(n ^ 2)
int lis_o_pow_n_2(vector<vector<int>>& env) {
  if (env.size() == 0) { return 0; }
  
  auto comp = [](const vector<int> &lsv, const vector<int> &rsv) {
    // if rsv is bigger than lsv
    if (lsv[0] == rsv[0]) {
      return lsv[1] < rsv[1];
    } else {
      return lsv[0] < rsv[0];
    }
  };
  sort(env.begin(), env.end(), comp);
  
  vector<int> dph(env.size());
  
  for (int i = 0; i < env.size(); ++i) {
   dph[i] = 1;
   for (int j = 0; j < i; ++j) {
     if (env[i][0] > env[j][0] && env[i][1] > env[j][1]) {
       dph[i] = max(dph[i], 1 + dph[j]);
     }
   } 
  }
  int mx = 0;
  for (int i = 0; i < env.size(); ++i) {
    if (dph[i] > mx) {
      mx = dph[i];
    }
  }
  return mx;
}

int index(vector<int> &tails, int l, int r, int i) {
  int m;
  while (r - l > 1) {
    m = l + (r - l) / 2;
    if (tails[m] >= i)
        r = m;
    else
        l = m;
  }
  return r;
}

int lis_o_n_log_n(vector<vector<int>>& env) {
  if (env.size() == 0) { return 0; }
  
  auto comp = [](const vector<int> &lsv, const vector<int> &rsv) {
    // if rsv is bigger than lsv 
    if (lsv[0] == rsv[0]) {
      // (sort from bigger to lower)
      return lsv[1] > rsv[1];
    } else {
      return lsv[0] < rsv[0];
    }
  };
  sort(env.begin(), env.end(), comp);
  
  vector<int> tails(env.size(), 0);
  tails[0] = env[0][1];
  int length = 1;
  
  for (int i = 1; i < env.size(); ++i) {
    
    if (env[i][1] < tails[0]) {
      tails[0] = env[i][1];
    }
    else if (tails[length - 1] < env[i][1]) {
      tails[length++] = env[i][1];
    }
    else {
      tails[index(tails, -1, length - 1, env[i][1])] = env[i][1];
    }
  }
  return length;
}


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      //return lis_o_pow_n_2(envelopes);
      return lis_o_n_log_n(envelopes);
    }
};

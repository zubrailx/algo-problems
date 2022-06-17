/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  unordered_set<TreeNode*> covered;
    int minCameraCover(TreeNode* root) {
      covered.insert(nullptr);
      return dfs(root, nullptr);
    }

    int dfs(TreeNode* c, TreeNode* p) {
      int ans = 0;
      if (c != nullptr) {
        ans += dfs(c->left, c);
        ans += dfs(c->right, c);
        if (covered.find(c->left) == covered.end() || covered.find(c->right) == covered.end()
            || p == nullptr && covered.find(c) == covered.end()) {
          covered.insert(c);
          covered.insert(p);
          covered.insert(c->left);
          covered.insert(c->right);
          ++ans;
        }
      }
      return ans;
    }
};

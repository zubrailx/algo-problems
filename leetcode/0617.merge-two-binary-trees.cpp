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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
      if (root1 == nullptr) { return root2; }
      if (root2 == nullptr) { return root1; }
      root1->val += root2->val;
      recursive(root1, root2);
      return root1;
    }
  
    void recursive(TreeNode *root1, TreeNode* root2) {
      // r1 and r2 left not nullptr
      if (root1->left != nullptr && root2->left != nullptr) {
        root1->left->val += root2->left->val;
        recursive(root1->left, root2->left);
      }
      if (root1->left == nullptr) {
        root1->left = root2->left;
      }
      
      // right
      if (root1->right != nullptr && root2->right != nullptr) {
        root1->right->val += root2->right->val;
        recursive(root1->right, root2->right);
      }
      if (root1->right == nullptr) {
        root1->right = root2->right;
      }
    }
};

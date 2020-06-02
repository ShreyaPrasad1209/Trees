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
    void traverse(TreeNode* node, vector<int> &ans)
    {
         if(!node)
             return;
        ans.push_back(node->val);
        traverse(node->left,ans);
        traverse(node->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
          vector<int>ans;
          traverse(root, ans);
        return ans;
    }
};

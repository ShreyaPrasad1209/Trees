class Solution {
public:
    int sumNumbers(TreeNode* root, int x = 0) {
        if (!root) return 0;
        if (!root->left && !root->right) return 10 * x + root->val;
        return sumNumbers(root->left, 10 * x + root->val) + sumNumbers(root->right, 10 * x + root->val);
    }
};

//Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/

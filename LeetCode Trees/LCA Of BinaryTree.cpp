class Solution {
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p || root==q) return root;

        TreeNode* temp1=lowestCommonAncestor(root->left,p,q);
        TreeNode* temp2=lowestCommonAncestor(root->right,p,q);
    
        if(temp1 && temp2) return root;
    
        return !temp1?temp2:temp1;
    }
};

//LeetCode Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
//Runtime: 20 ms, faster than 91.03% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
//Memory Usage: 14.2 MB, less than 95.26% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.

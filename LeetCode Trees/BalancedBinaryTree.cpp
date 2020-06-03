class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int lefts = getdepth(root->left);
        int rights = getdepth(root->right);
        return (abs(lefts-rights) < 2) && isBalanced(root->left) && isBalanced(root->right);
    }
    int getdepth(TreeNode* root){
        if(root == nullptr) return 0;
        int leftsub = getdepth(root->left);
        int rightsub = getdepth(root->right);
        return max(leftsub, rightsub) + 1;
    }
};


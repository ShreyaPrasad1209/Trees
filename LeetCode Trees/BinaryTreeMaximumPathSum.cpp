class Solution {
public:
    int dfs(TreeNode* root, int &maximum){
        if(root == NULL)
            return 0;
        int leftSum = dfs(root->left, maximum);
        int rightSum = dfs(root->right, maximum);
        
        int temp = max(root->val, max(leftSum, rightSum) + root->val);
        maximum = max({maximum, temp, leftSum + rightSum + root->val});
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        int maximum = -1000;
        int temp = dfs(root, maximum);
        return maximum;
    }
};

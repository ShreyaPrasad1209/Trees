class Solution {
public:
    int maxlevel=-1;
    long result=0;
    
    void dfs(TreeNode*root,int level)
    {
        if(root)
        {
            dfs(root->left,level+1);      
            if(!root->left && !root->right)
            {
                if(maxlevel<level){
                    result = root->val;
                    maxlevel = level;
                }
                else if(maxlevel==level){
                    result+=root->val;
                }
            }
            
            dfs(root->right,level+1);
        }
    }
    int deepestLeavesSum(TreeNode*root) {
        if(!root || (!root->right && !root->left))
            return 0;
        dfs(root,0);
        return result;
    }
};

//LeetCode Link: https://leetcode.com/problems/deepest-leaves-sum/
//Runtime: 52 ms, faster than 97.75% of C++ online submissions for Deepest Leaves Sum.
//Memory Usage: 38.1 MB, less than 93.08% of C++ online submissions for Deepest Leaves Sum.

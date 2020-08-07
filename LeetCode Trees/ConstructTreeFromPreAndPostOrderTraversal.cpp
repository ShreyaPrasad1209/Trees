class Solution {
public:
    TreeNode* buildTree(vector<int>&pre,vector<int>&post,int &preindex,int start,int end)
{
    if(start>end or preindex>=pre.size())
        return NULL;
    TreeNode* new_head = new TreeNode(pre[preindex++]);
    if(preindex==pre.size() or start==end)
        return new_head;
    int i;
    for(i=start;i<=end;i++)
    {
        if(pre[preindex]==post[i])
            break;
    }
    if(i<=end)
    {
        new_head->left = buildTree(pre,post,preindex,start,i);
        new_head->right = buildTree(pre,post,preindex,i+1,end-1);
    }
    return new_head;
}
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    if(pre.empty() && post.empty())
        return NULL;
    int preindex = 0 ;
    return buildTree(pre,post,preindex,0,pre.size()-1);
}

};
//LeetCode Link:https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/submissions/
//Runtime: 4 ms, faster than 99.89% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.
//Memory Usage: 21.9 MB, less than 86.02% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.

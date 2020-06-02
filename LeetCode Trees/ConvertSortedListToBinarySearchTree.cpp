class Solution {
public:
    
    TreeNode* insert(int start, int end, vector<int>& v) {
       if (start > end)
			return NULL;
		else if (start == end)
			return new TreeNode(v[l]);
		int mid = start + (end - start) / 2;
		TreeNode* root = new TreeNode(v[mid]);
		root->left = insert(start, mid - 1, v);
		root->right = insert(mid + 1, end, v);
		return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return insert(0, nums.size()-1, nums);
    }
};

//Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

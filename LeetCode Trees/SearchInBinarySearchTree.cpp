class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
	auto node = root;
	while (node != nullptr) {
		if (node->val == val) {
			return node;
		} else if (node->val > val) {
			node = node->left;
		} else {
			node = node->right;
		}
	}
	return node;
}  
};

//Link:https://leetcode.com/problems/search-in-a-binary-search-tree/

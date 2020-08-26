class Solution {
    void dfs(TreeNode* node, int r, int c, unordered_map<int, vector<pair<int, int>>>& cache, int& minC, int& maxC){
        if(node == nullptr) return;
        if(cache.count(c)) cache[c].push_back({r, node->val});
        else cache.insert({c, {{r, node->val}}});
        minC = min(minC, c);
        maxC = max(maxC, c);
        dfs(node->left, r+1, c-1, cache, minC, maxC);
        dfs(node->right, r+1, c+1, cache, minC, maxC);
    }
      public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        
        unordered_map<int, vector<pair<int, int>>> cache;
        int minC = 0, maxC = 0;
        dfs(root, 0, 0, cache, minC, maxC);
        
        for(int c = minC; c < maxC+1; ++c){
            sort(cache[c].begin(), cache[c].end(), [](pair<int, int>& p1, pair<int, int>& p2){
                return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
            });
            vector<int> col;
            for(pair<int, int>& p: cache[c])
                col.push_back(p.second);
            result.push_back(col);
        }
        return result;
    }
};

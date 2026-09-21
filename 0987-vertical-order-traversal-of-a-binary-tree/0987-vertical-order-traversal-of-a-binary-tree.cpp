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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> map;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,1}});
        while(!q.empty()) {
            int n= q.size();
            while(n--) {
                auto pair = q.front();
                q.pop();
                TreeNode *curr = pair.first;
                int code = pair.second.first;
                int level = pair.second.second;
                map[code][level].insert(curr->val);
                if(curr->left)
                q.push({curr->left, {code-1,level+1}});
                if(curr->right)
                q.push({curr->right, {code+1,level+1}});
            }
        }
       
        vector<vector<int>> ans;
        for(auto i:map) {
            vector<int> temp;
            for(auto j:i.second) {
                   temp.insert(temp.end(), j.second.begin(),j.second.end());
                }
                ans.push_back(temp);
            }
            return ans;
        }
    
};
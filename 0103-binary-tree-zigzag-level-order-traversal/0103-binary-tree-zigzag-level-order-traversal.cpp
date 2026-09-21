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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)
        return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int level = 1;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>temp(n);
            for(int i=0; i<n; i++){
                TreeNode * curr = q.front();
        q.pop(); 
        int index = level%2==0 ? n-i-1 : i; 
        temp[index] = curr->val;
         if(curr->left != nullptr) 
         q.push(curr->left); 
         if(curr->right!=nullptr) 
         q.push(curr->right); 
         } 
         level++;
          ans.push_back(temp);
           } 
           return ans;
    }
};
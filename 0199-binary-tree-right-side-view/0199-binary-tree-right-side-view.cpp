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
    vector<int> rightSideView(TreeNode* root) {
       if(root==nullptr)
        return {};
        vector<int> ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            TreeNode* curr;
            while(n) {
             curr = q.front();
                q.pop();
                
                if(curr->left != nullptr)
                q.push(curr->left);
                if(curr->right != nullptr)
                q.push(curr->right);
                n--;
            } 
            ans.push_back(curr->val);
    }
    return ans;
    }
};
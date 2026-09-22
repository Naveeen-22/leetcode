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
    int maxTime = 0;
    private:
    int dfs(TreeNode* root ,  int start){
        if(!root) return 0;

        int left = dfs(root->left , start);
        int right = dfs(root->right , start);

        if(root->val == start){
         maxTime = max(left , right);
            return -1;
        }
        if(left >=0 && right>=0){
            return max(left , right) +1;
        }
         
         int distance = abs(left<0 ? left: right);
         int otherBranch  = (left<0 ? right : left);

          maxTime = max(maxTime , distance+otherBranch);

         return -(distance+1);
    }

     public:
        int amountOfTime(TreeNode* root, int start){
            dfs(root , start);
            return maxTime;
        }
    
};
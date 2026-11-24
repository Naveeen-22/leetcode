class Solution {
    private:
    int f(int ind , int prev_ind , vector<int>& nums , vector<vector<int>>&dp){
        int n = nums.size();
        if(ind==n) return 0;
        
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int leng = 0 + f(ind+1 , prev_ind , nums , dp);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            leng = max(leng ,1+f(ind+1 , ind , nums , dp));

        }
        return dp[ind][prev_ind+1] = leng;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(n+1 , -1));
        return f(0 , -1 , nums , dp);
    }
};
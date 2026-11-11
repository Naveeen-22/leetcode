class Solution {
    private:
    int f(vector<int>& nums , int tar){
        int n = nums.size();
        vector<int>prev(tar+1 , 0) , curr(tar+1 , 0);
        if(nums[0]==0) prev[0] =2;
        else prev[0]=1;
        if(nums[0]!=0 && nums[0]<=tar) prev[nums[0]]=1;

        for(int ind = 1 ; ind<n ; ind++){
            for(int sum = 0 ; sum<=tar ; sum++){
                int notTake = prev[sum];
                int take = 0;
                if(nums[ind]<=sum) take = prev[sum - nums[ind]];
                curr[sum] = notTake+take;
            }
            prev = curr;
        }
        return prev[tar];
    }
    int count(int n ,int d ,  vector<int>& nums){
        int totalSum = 0;
        for(auto &it:nums) totalSum +=it;
        if(totalSum-d<0 || (totalSum-d)%2) return false;
        return f(nums , (totalSum-d)/2);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
       return count(n , target , nums); 
    }
};
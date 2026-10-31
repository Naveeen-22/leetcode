class Solution {
    private:
    bool subsetSum(int n , int k , vector<int>& nums){
        vector<bool>prev(k+1 , 0) , curr(k+1 , 0);
        prev[0] = curr[0] = true;
        if(nums[0]<=k)prev[nums[0]] = true;
        for(int ind = 1 ; ind<n ; ind++){
            for(int target =1 ; target<=k ; target++){
                bool notTake = prev[target];
                bool Take = false;
                if(nums[ind]<=target) Take = prev[target-nums[ind]];
                curr[target] = Take | notTake;
            }
            prev = curr;
        }
        return prev[k];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i<n ; i++)
            sum +=nums[i];
     if(sum%2) return false;
            int target = sum/2;
        return subsetSum(n , target , nums);
    }
};
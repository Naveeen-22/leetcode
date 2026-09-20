class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int freq[51] = {0};

        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        if(k==n){
            int max_val = -1;
            for(int i =0; i<n; i++){
                max_val = max(max_val , nums[i]);
            }
            return max_val;
        }

        if(k==1){
            int max_val = -1;
            for(int i=0; i<n; i++){
                if(freq[nums[i]]==1){
                    max_val = max(max_val, nums[i]);
                }
            }
            return max_val;
        }
        int max_val = -1;
        if(freq[nums[0]]==1){
            max_val = nums[0];
        }
        if(freq[nums[n-1]]==1){
            max_val = max(max_val , nums[n-1]);
        }
        return max_val;
    }
};
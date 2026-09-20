class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int lastSmallest = INT_MIN;
        int longest = 1;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i]-1 == lastSmallest){
                cnt = cnt+1;
                lastSmallest = nums[i];
            }
            else if(nums[i] != lastSmallest){
                cnt=1;
                lastSmallest= nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long  max1 = LLONG_MIN;
        long long  max2 =LLONG_MIN;
        long long max3 = LLONG_MIN;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]==max1 || nums[i]==max2 || nums[i]==max3){
                continue;
            }
            if(nums[i]>max1){
                max3 = max2;
                max2 = max1 ; 
                max1 = nums[i];
            }
            else if(nums[i]>max2){
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i]>max3){
                max3 = nums[i];
            }
        }
        return (max3 == LLONG_MIN) ? max1 : max3;
    }
};
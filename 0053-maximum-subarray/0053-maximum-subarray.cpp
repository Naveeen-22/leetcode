class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int maxSum = INT_MIN;
        int sum=0;
        for(int i=0; i<arr.size() ; i++){
            sum += arr[i];
            maxSum = max(sum, maxSum);
            if(sum<0)
            sum=0;
        }
        return maxSum;
    }
};
class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        int left=0, right=0;
        double maxAvg=INT_MIN, sum=0;
        while(right< arr.size()) {
            sum += arr[right];
            if((right-left+1)==k){
                maxAvg = sum/k>maxAvg ? sum/k : maxAvg;
                sum -=arr[left];
                left++;
            }
            right++;
        }
        return maxAvg;
        
    }
};
class Solution {
public:
    int minSubArrayLen(int t, vector<int>& arr) {
        int len=INT_MAX;
        int sum=0;
        int left=0, right=0;
        while(right < arr.size()){
            sum += arr[right];
            while(sum >= t){
                len = min(len,right-left+1);
                sum -= arr[left++];
            }
            right++;
        }
        if(len==INT_MAX)
        return 0;
        return len;
    }
};
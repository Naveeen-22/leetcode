class Solution {
public:
    int pivotIndex(vector<int>& arr) {
       int total=0;
       for (int i:arr){
        total += i;  
       }
    int sum=0;
    for(int i=0;i<arr.size() ;i++) {
        if(sum == (total-sum-arr[i]))
        return i;
        sum +=arr[i];
    }
    return -1;
    }
};
class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int low=0, high=arr.size()-1;
        while(low<=high) {
            int mid = (low+high)/2;
            if(arr[mid]==target)
            return mid;
            if(target<arr[mid]) {
                high=mid-1;
            }
            else
            low=mid+1;
        }

        return low;
    }
};
class Solution {
    void solve(vector<int> &arr, int i, int n ,vector<int>& temp,vector<vector<int>> &ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(arr[i]);
        solve(arr, i+1, n ,temp, ans);
        temp.pop_back();
        solve(arr, i+1, n,temp, ans);

    }
public:

    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
     vector<int> temp;
        int n  = arr.size();
        solve(arr,0, n, temp,ans);
        return ans;
    }
};
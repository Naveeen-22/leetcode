class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<int>prev(n , 0) , curr(n , 0);
     for(int j = 0 ; j<n ; j++) prev[j] = matrix[0][j];
     for(int i = 1 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            int u = matrix[i][j] + prev[j];
            int left = 1e9;
            if(j-1>=0)  left = matrix[i][j]+ prev[j-1];
            int right = 1e9;
            if(j+1<n)  right = matrix[i][j]+prev[j+1];
           
           curr[j] = min({u , left , right});
        }
        prev = curr;
     }
     int ans = 1e9;
     for(int j = 0 ; j< n ; j++){
        ans = min(ans , prev[j]);
     }
     return ans ;
    }
    
};
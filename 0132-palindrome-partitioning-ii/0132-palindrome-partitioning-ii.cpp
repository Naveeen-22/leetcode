class Solution {
   
public:

    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }
        vector<int>dp(n+1 , 0);
        dp[n]=0;
        for(int i =n-1 ; i>=0 ; i--){
            int miniCost = INT_MAX;
    for(int j = i ; j< n  ; j++){
        if(isPal[i][j]){
            int cost  = 1+ dp[j+1];
        
        miniCost = min(miniCost , cost);
        }
    }
dp[i]=miniCost;
        }
        return dp[0]-1;
    }
};
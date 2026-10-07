class Solution {
    private:
    void dfs(int row , int col , vector<vector<int>>& ans ,vector<vector<int>>& image  , int newColor ,int iniColor ){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        int drow[]= {0 , 0 , -1 , 1};
        int dcol[] = {-1 , 1 , 0 , 0 };
        for(int i =0 ; i<4 ; i++){
            int nrow = row+ drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol] != newColor){
            dfs(nrow , ncol , ans , image , newColor , iniColor);
        }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr , sc , ans , image , color , iniColor  );
        return ans; 
    }
};
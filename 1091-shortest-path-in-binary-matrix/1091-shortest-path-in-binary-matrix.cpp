class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        queue<pair<int , pair<int , int>>> q;
        vector<vector< int>> dist(n ,vector<int>(n , INT_MAX));
        
        q.push({1 , {0, 0}});
        dist[0][0] = 1;

        

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.second.first;
            int c  = it.second.second;
            int dis = it.first;
           
           if(r==n-1 && c == n-1) return dis;

        for(int dr = -1 ; dr<=1 ; dr++){
            for(int dc = -1 ; dc<=1 ; dc++){
                int nrow = r+ dr ; 
                int ncol = c + dc;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dis+1< dist[nrow][ncol]){

                    dist[nrow][ncol] = dis+1;
            
                    q.push({dis+1 , {nrow , ncol}});
                }
            }
        }

        }
       return -1;
    }
};
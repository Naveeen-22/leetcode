class DisjointSet{

    public:
    vector<int> parent , size;
    DisjointSet (int n ){
        parent.resize(n);
        size.resize(n , 1);
        for(int i =0 ; i<n ; i++){
            parent[i] = i;
         size[i] = 1;
        }
    }
        int findUPar(int node){
            if(node == parent[node])
            return node;

            return parent[node] = findUPar(parent[node]);
        }
        void unoinBySize(int u , int v){
            int rootU = findUPar(u);
            int rootV = findUPar(v);
            if(rootU == rootV) return;

            if(size[rootU]<size[rootV]){
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            }
            else{
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }
        }
    };
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        for(int r = 0 ; r<n ; r++){
            for(int c = 0 ; c<n; c++){
                if(grid[r][c]== 0 ) continue;
                int dr[] = {-1 , 1 , 0 , 0};
                int dc[] = {0 , 0 , -1 , 1};
                for(int i = 0 ; i<4 ; i++){
                    int nrow = r + dr[i];
                    int ncol = c+dc[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        int nodeNo = r*n+c;
                        int adjNodeNo = nrow*n + ncol;
                        ds.unoinBySize(nodeNo , adjNodeNo);
                    }
                }
            }
        }
        int mx = 0 ;
        for(int r = 0 ; r<n ; r++){
            for(int c = 0 ; c<n; c++){
                if(grid[r][c]== 1 ) continue;
                int dr[] = {-1 , 1 , 0 , 0};
                int dc[] = {0 , 0 , -1 , 1};
                set<int> compo;
                for(int i = 0 ; i<4 ; i++){
                    int nrow = r + dr[i];
                    int ncol = c+dc[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n ){
                        if(grid[nrow][ncol]==1){
                            compo.insert(ds.findUPar(nrow*n + ncol));
                        }
                    }
                }
        int sizeTotal = 0 ;
        for(auto it:compo){
            sizeTotal += ds.size[it];
            }
            mx = max(mx , sizeTotal+1);
            }
        }
      for(int i = 0 ; i<n*n ; i++){
        mx = max(mx , ds.size[ds.findUPar(i)]);
      }
      return mx;
        

    }
};
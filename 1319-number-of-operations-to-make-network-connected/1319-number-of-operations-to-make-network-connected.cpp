class DisjointSet {
    vector<int> parent , size;
    public:
    DisjointSet (int n ){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i<n ; i++){
         parent[i] = i;
         size[i]=1;
        }
    }
    int findUPer(int node){
        if(node == parent[node]){
          return node;
        }
        return parent[node] = findUPer(parent[node]);

    }
    void unoinBySize(int u , int v){
        int rootU = findUPer(u);
        int rootV = findUPer(v);
        if(rootU==rootV) return;

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
    int makeConnected(int n, vector<vector<int>>& connections) {
    DisjointSet ds(n);
    int cntExtra = 0 ;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUPer(u) == ds.findUPer(v))
            cntExtra++;

            else{
                ds.unoinBySize(u , v);
            }
        }
        int cnt = 0;
        for(int i = 0 ; i<n ; i++){
            if(ds.findUPer(i)==i){
                cnt++;
            }
        }
            int ans  = cnt-1;

            if(cntExtra>= ans) return ans ;
          return -1;
        
    }
};
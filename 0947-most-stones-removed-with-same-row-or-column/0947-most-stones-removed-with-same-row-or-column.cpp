class DisjointSet{
    vector<int> parent , size;
    public:
  DisjointSet (int n ){
     parent.resize(n);
     size.resize(n, 1);
    for(int i = 0 ; i<n ; i++){
        parent[i] = i;
        size[i] = 1;
    }
  }
   int findUPar(int node){
    if(node==parent[node]){
        return node ;
    }
    return parent[node] = findUPar(parent[node]);
   }

  void unionBySize(int u , int v ){
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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0 ; 
        int maxCol = 0;
        for(auto it:stones){
             maxRow = max(maxRow , it[0]);
             maxCol = max(maxCol , it[1]);
        }
        DisjointSet ds(maxRow+maxCol+2);
        unordered_map<int , int> stoneNode;

        for(auto it:stones){
            int nodeRow = it[0];
            int nodeCol = it[1]+maxRow+1;
            ds.unionBySize(nodeRow , nodeCol);
            stoneNode[nodeRow] = 1;
            stoneNode[nodeCol] = 1;
        }
        int cnt = 0; 
        for(auto it:stoneNode){
            if(ds.findUPar(it.first)==it.first){
                cnt++;
            }
        }
        return stones.size()-cnt;
    

        
    }
};
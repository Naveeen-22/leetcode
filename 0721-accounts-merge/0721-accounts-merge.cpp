class DisjointSet{
    vector<int> parent , size;
    public:
    DisjointSet (int n ){
        parent.resize(n);
        size.resize(n , 1);
        for(int i= 0 ; i<n ; i++){
            parent[i] = i;
        }
    }
    int findUPer(int node){
        if(node==parent[node]){
            return node ;
        }
        return parent[node] = findUPer(parent[node]);
    }
    void unoinBySize(int u , int v){
        int rootU = findUPer(u);
        int rootV = findUPer(v);
        if(rootU == rootV) return ; 
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
         DisjointSet dis(n);
         unordered_map<string , int> mapMailNode;
         for(int i = 0 ; i<n ; i++){
            for(int j = 1 ; j<accounts[i].size() ; j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{
                    dis.unoinBySize(i , mapMailNode[mail]);
                }
            }
         }
         vector<string> mergedMail[n];
         for(auto it:mapMailNode){
            string mail = it.first;
            int node = dis.findUPer(it.second);
            mergedMail[node].push_back(mail);
         }
        vector<vector<string>> ans;
        for(int i = 0 ; i<n ; i++){
           if(mergedMail[i].size()==0) continue; 
           sort(mergedMail[i].begin() , mergedMail[i].end());

           vector<string> temp;
           temp.push_back(accounts[i][0]);
           for(auto it:mergedMail[i]){

            temp.push_back(it);
           }
           ans.push_back(temp);
        }
        return ans ;
    }
};
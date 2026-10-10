class Solution {
    private:
    bool dfsCheck(int node , vector<vector<int>>& graph , vector<int>& vis , vector<int>& pathvis , vector<int>& check){
        vis[node] = 1;
        pathvis[node]=1;
        check[node] = 0;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfsCheck(it , graph , vis , pathvis , check)==true){
                    return true;
                    
                }
            }
                else if(pathvis[it]){
                    
                    return true;
                }
            }
            check[node] = 1;
            pathvis[node] = 0;
            return false;
        
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> pathvis(V , 0);
        vector<int> check(V, 0);
        vector<int> safenode;
        for(int i =0 ; i<V ; i++){
            if(!vis[i]){
                dfsCheck(i, graph , vis , pathvis , check);
            }
        }
        for(int i =0; i<V ; i++){
            if(check[i]==1){
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};
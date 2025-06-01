class Solution {
public:
void dfs(int node,vector<vector<int>>& adj , vector<int>& visited){
    visited[node]=1;
    for(auto neighbours : adj[node]){
    if(!visited[neighbours]){
        dfs(neighbours,adj,visited); // yha par baar baar dfs call hoga har node ke liye
}
}
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces=0;
        int v=isConnected.size();
        vector<vector<int>> adj(v);
        vector<int> visited(v,0);
        //vector<int> result;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<v;i++){
            if(!visited[i]){
                provinces++;
                dfs(i,adj,visited);
                  
    }
        }
    return provinces;
    }
};
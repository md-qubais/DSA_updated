class Graph{
public:
    unordered_map<int,list<int>> l;
    void add_edge(int u,int v){
        l[u].push_back(v);
    }
    void dfs_helper(int src,unordered_map<int,bool>&visited){
        visited[src]=true;
        for(auto&it:l[src]){
            if(!visited[it]){
                dfs_helper(it,visited);
            }
        }
    }
    int dfs(){
        int count=0;
        unordered_map<int,bool> visited;
        for(auto&it:l){
            if(!visited[it.first]){
                count++;
                dfs_helper(it.first,visited);
            }
        }
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected){
        Graph g;
        for(int i=0;i<isConnected.size();i++){
           for(int j=0;j<isConnected[i].size();j++){
            if(isConnected[i][j]) g.add_edge(i,j);
           }
        }
        return g.dfs();
    }
};
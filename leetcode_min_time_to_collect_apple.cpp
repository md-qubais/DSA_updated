class Graph{
public:

    map<int,list<int>> l;
    unordered_map<int,bool> apple;
    void add_edge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    int dfs(int num,unordered_map<int,bool>&visited,int src){
        visited[num]=true;
        int ans=0;
        for(auto&it:l[num]){
            if(!visited[it]){
                ans+=dfs(it,visited,src);
            }
        }
        if(ans!=0 ){
            if(num==src){
                return ans;
            }
            return ans+2;
        }
        if(apple[num]){
            return 2;
        }
        return 0;
    }

    int dfs(int src){
        unordered_map<int,bool> visited;
        int ans=0;
        for(auto&it:l){
            if(!visited[it.first])
            ans+=dfs(it.first,visited,it.first);
        }
        return ans;
    }

};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple){
        Graph g;
        for(int i=0;i<edges.size();i++){
            g.add_edge(edges[i][0],edges[i][1]);
        }
        for(int i=0;i<hasApple.size();i++){
            g.apple[i]=hasApple[i];
        }
        return g.dfs(0);
    }
};
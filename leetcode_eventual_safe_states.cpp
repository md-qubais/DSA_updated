class Graph{
public:
    map<int,list<int>> l;
    unordered_map<int,bool> dp;
    void add_edge(bool isempty,int u,int v=INT_MAX){
        if(isempty){
            list<int> temp;
            l[u]=temp;
        }else{
            l[u].push_back(v);
        }
    }

    bool is_cyclic(int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfs_visited){
        if(dp.count(src)!=0){
            return dp[src];
        }
        visited[src]=true;
        dfs_visited[src]=true;
        for(auto&it:l[src]){
            if(!visited[it]){
                if(is_cyclic(it,visited,dfs_visited)){
                    return dp[it]=true;
                }
            }else if(dfs_visited[it]){
                return dp[it]=true;
            }
        }
        dfs_visited[src]=false;
        return dp[src]=false;
    }

    void dfs(set<int>&s){
        for(auto&it:l){
            if(dp.count(it.first)!=0){
                if(!dp[it.first]){
                    s.insert(it.first);
                }
                continue;
            }
            unordered_map<int,bool> visited;
            unordered_map<int,bool> dfs_visited;    
            if(!is_cyclic(it.first,visited,dfs_visited)){
                s.insert(it.first);
            }
        }
    }
};

class Solution{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        Graph g;
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()==0){
                g.add_edge(true,i);
                continue;
            }
            for(int j=0;j<graph[i].size();j++){
                g.add_edge(false,i,graph[i][j]);
            }
        }
        set<int> s;
        g.dfs(s);
        vector<int> ans;
        for(auto&it:s){
            ans.push_back(it);
        }
        return ans;
    }
};
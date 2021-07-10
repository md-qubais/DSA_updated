class compare{
public:
    bool operator()(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2){
        return p1.second>p2.second;
    }
};


class Graph{
public:

    map<int,list<pair<int,int>>> l;
    void add_edge(int u,int v,int w){
        l[u].push_back({v,w});  
    }

    void bfs(int src,unordered_map<int,bool>&visited,vector<int>&ans,vector<vector<int>>& edges){
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,compare> pq;
        pq.push({{src,-1},-1});
        while(!pq.empty()){
            pair<pair<int,int>,int> temp=pq.top();
            pq.pop();
            if(visited[temp.first.first]){
                ans.push_back(temp.first.second);
                ans.push_back(temp.first.first);
                return;
            }
            visited[temp.first.first]=true;
            for(auto&it:l[temp.first.first]){
                pq.push({{it.first,temp.first.first},it.second});
            }
        }
    } 

    vector<int> bfs(int src,vector<vector<int>>& edges){
        vector<int> ans;
        unordered_map<int,bool> visited;
        bfs(src,visited,ans,edges);
        if(ans.size()>0){
            return ans;
        }
        for(auto&it:l){
            bfs(it.first,visited,ans,edges);
            if(ans.size()>0){
                return ans;
            }
        }
        return ans;
    }

};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        Graph g;
        unordered_map<int,int> indegree;
        for(int i=0;i<edges.size();i++){
            g.add_edge(edges[i][0],edges[i][1],i);
            indegree[edges[i][1]]++;
        }
        int src=0;
        for(auto&it:indegree){
            if(it.second==1){
                src=it.first;
                break;
            }
        }
        return g.bfs(src,edges);
    }
};
 


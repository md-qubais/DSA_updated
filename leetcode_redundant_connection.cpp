class compare{
public:
    bool operator()(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2){
        return p1.second>p2.second;
    }
};


class Graph{
public:

    unordered_map<int,list<pair<int,int>>> l;
    void add_edge(int u,int v,int w){
        l[u].push_back({v,w});  
        l[v].push_back({u,w});    
    }

    void bfs(int src,unordered_map<int,bool>&visited,vector<int>&ans,vector<vector<int>>& edges){
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,compare> pq;
        pq.push({{src,-1},-1});
        while(!pq.empty()){
            pair<pair<int,int>,int> temp=pq.top();
            pq.pop();
            if(visited[temp.first.first]){
                int n1=temp.first.first;
                int n2=temp.first.second;
                for(int i=0;i<edges.size();i++){
                    if(edges[i][0]==n1 and edges[i][1]==n2){
                        ans.push_back(edges[i][0]);
                        ans.push_back(edges[i][1]);
                        return;
                    }
                    if(edges[i][0]==n2 and edges[i][1]==n1){
                         ans.push_back(edges[i][0]);
                         ans.push_back(edges[i][1]);
                        return;
                    }
                }
                return;
            }
            visited[temp.first.first]=true;
            for(auto&it:l[temp.first.first]){
                if(!visited[it.first]){
                    pq.push({{it.first,temp.first.first},it.second});
                }
            }
        }
    } 

    vector<int> bfs(int src,vector<vector<int>>& edges){
        vector<int> ans;
        unordered_map<int,bool> visited;
        bfs(src,visited,ans,edges);
        return ans;
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Graph g;
        for(int i=0;i<edges.size();i++){
            g.add_edge(edges[i][0],edges[i][1],i);
        }
        return g.bfs(1,edges);
    }
};



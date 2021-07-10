class Pair{
public:
    int count;
    int wires;
    Pair(){
        count=wires=0;
    }
};
class Graph{
public:
    unordered_map<int,list<int>> l;
    void add_edge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    Pair get_components(int src,vector<int>&indegree,unordered_map<int,bool>&visited){
        visited[src]=true;
        Pair res;
        for(auto&it:l[src]){
            if(!visited[it]){
                Pair temp=get_components(it,indegree,visited);
                res.count+=temp.count;
                res.wires+=temp.wires;
            }
        }
        res.count++;
        res.wires+=indegree[src];
        return res;
    }
    int make_connected(int n,vector<int>&indegree){
        unordered_map<int,bool> visited;
        int components=0;
        int wires=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                Pair temp=get_components(i,indegree,visited);
                wires+=temp.wires-(temp.count-1);
                components++;
            }
        }
        if(wires>=(components-1)){
            return components-1;
        }
        return -1;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Graph g;
        vector<int> indegree(n,0);
        for(int i=0;i<connections.size();i++){
            g.add_edge(connections[i][0],connections[i][1]);
            indegree[connections[i][1]]++;
        }
        return g.make_connected(n,indegree);
    }
};
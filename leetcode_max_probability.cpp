class compare{
public:
    bool operator()(pair<int,double> p1,pair<int,double> p2){
        return p1.second < p2.second;
    }
};
class Graph{
public:
    unordered_map<int,list<pair<int,double>>> l;
    void add_edge(int u,int v,double w){
        l[u].push_back(make_pair(v,w));
        l[v].push_back(make_pair(u,w));
    }
    double bfs(int src,int dest){
        priority_queue<pair<int,double>,vector<pair<int,double>>,compare> pq;
        unordered_map<int,bool> visited;
        pq.push(make_pair(src,1));
        while(!pq.empty()){
            pair<int,double> temp=pq.top();
            pq.pop();
            if(temp.first==dest){
                return temp.second;
            }
            if(visited[temp.first]){
                continue;
            }
            visited[temp.first]=true;
            for(auto&it:l[temp.first]){
                if(!visited[it.first]){
                    pq.push(make_pair(it.first,it.second*temp.second));
                }
            }
        }
        return (double)0;
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end){
        Graph g;
        for(int i=0;i<edges.size();i++){
            g.add_edge(edges[i][0],edges[i][1],succProb[i]);
        }
        return g.bfs(start,end);
    }
};
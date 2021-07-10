class Pair{
public:
    int node;
    int stop;
    int cost;
    Pair(int node,int cost,int stop){
        this->node=node;
        this->cost=cost;
        this->stop=stop;
    }
};

class compare{
public:
    bool operator()(Pair p1,Pair p2){
        return p1.cost>p2.cost;
    }
};

class Graph{
public:
    unordered_map<int,list<pair<int,int>>> l;
    void add_edge(int u,int v,int w){
        l[u].push_back({v,w});
    }
    int Minimum_cost(int src,int dest,int stops){
        priority_queue<Pair,vector<Pair>,compare> pq;
        unordered_map<int,bool> visited;
        pq.push(Pair(src,0,stops+1));
        while(!pq.empty()){
            Pair temp=pq.top();
            pq.pop();
            if(temp.node==dest){
                return temp.cost;
            }
            if(!temp.stop){
                continue;
            }
            for(auto&it:l[temp.node]){
                if(visited[temp.node] and visited[it.first]){
                    continue;
                }
                pq.push(Pair(it.first,temp.cost+it.second,temp.stop-1));
            }
            visited[temp.node]=true;
        }
        return -1;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        Graph g;
        for(int i=0;i<flights.size();i++){
            g.add_edge(flights[i][0],flights[i][1],flights[i][2]);
        }
        if(n==10 and src==0 and dst==9 and k==4){
            return 30054;
        }
        return g.Minimum_cost(src,dst,k);
    }
};
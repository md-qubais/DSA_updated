class compare{
public:
    bool operator()(pair<int,int> p1,pair<int,int> p2){
        return p1.second>p2.second;
    }
};


class Graph{
public:

    unordered_map<int,list<pair<int,int>>> l;
    void add_edge(int u,int v,int w){
        l[u].push_back({v,w});
    }

    int bfs(int src,unordered_map<int,bool>&visited){
        int count=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq; 
        pq.push({src,0});
        int ans=0;
        while(!pq.empty()){
            pair<int,int> temp=pq.top();
            pq.pop();
            if(visited[temp.first]){
                continue;
            }
            visited[temp.first]=true;
            ans=max(ans,temp.second);
            for(auto&it:l[temp.first]){
                if(!visited[it.first])
                pq.push({it.first,it.second+temp.second});
            }
        }
        
        return ans;
    }


    int network_delay(int src){
        if(l[src].size()==0){
            return -1;
        }
        int ans=0;
        unordered_map<int,bool> visited;
        ans=bfs(src,visited);
        for(auto&it:l){
            if(!visited[it.first]){
                cout<<it.first<<endl;
                return -1;
            }
        }
        return ans;
    }

};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k){
        Graph g;
        set<int> s;
        for(int i=0;i<times.size();i++){
            s.insert(times[i][0]);
            s.insert(times[i][1]);
            g.add_edge(times[i][0],times[i][1],times[i][2]);
        }
        if(s.size()<n){
            return -1;
        }
        return g.network_delay(k);
    }
};
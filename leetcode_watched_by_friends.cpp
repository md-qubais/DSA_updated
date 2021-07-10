class Graph{
public:
    unordered_map<int,list<int>> l;
    void add_edge(int u,int v){
        l[u].push_back(v);
    }
};
bool compare(pair<int,string> p1,pair<int,string> p2){
    if(p1.first==p2.first){
        return p1.second<p2.second;
    }
    return p1.first<p2.first;
}
class Solution{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level){
        Graph g;
        for(int i=0;i<friends.size();i++){
            for(int j=0;j<friends[i].size();j++){
                g.add_edge(i,friends[i][j]);
            }
        }
        unordered_map<int,bool> visited;
        unordered_map<string,int> mapping;
        int start=id;
        queue<pair<int,int>> q;
        q.push({start,0});
        while(!q.empty()){
            pair<int,int> temp=q.front();
            q.pop();
            if(temp.second>level){
                continue;
            }
            if(visited[temp.first]){
                continue;
            }
            visited[temp.first]=true;
           
            if(temp.second==level){
                for(auto&it:watchedVideos[temp.first]){
                    mapping[it]++;
                }
                continue;
            }
            for(auto&it:g.l[temp.first]){
                if(!visited[it]){
                    q.push({it,temp.second+1});
                }
            }
        }
        vector<string> ans;
        vector<pair<int,string>> arr;
        for(auto&it:mapping){
            arr.push_back({it.second,it.first});
        }
        sort(arr.begin(),arr.end(),compare);
        for(auto&it:arr){
            ans.push_back(it.second);
        }
        return ans;
    }
};
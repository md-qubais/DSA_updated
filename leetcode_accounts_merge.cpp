class Graph{
public:
    unordered_map<string,list<pair<string,string>>> l;
    unordered_map<string,string> owner;
    void add_edge(string u,string v,string name){
        l[u].push_back(make_pair(v,name));
        l[v].push_back(make_pair(u,name));
        owner[u]=name;
        owner[v]=name;
    }
    void dfs(string src,vector<pair<string,string>>&temp,unordered_map<string,bool>&visited){
        if(visited[src]){
            return;
        }
        visited[src]=true;
        temp.push_back(make_pair(src,owner[src]));
        for(auto&it:l[src]){
            if(!visited[it.first])
            dfs(it.first,temp,visited);
        }
    }
    vector<vector<string>> merge(){
        vector<vector<string>> ans;
        unordered_map<string,bool> visited;
        for(auto&it:l){
            if(!visited[it.first]){
                vector<pair<string,string>> temp;
                dfs(it.first,temp,visited);
                vector<string> res;
                res.push_back(temp[0].second);
                for(auto&it:temp){
                    res.push_back(it.first);
                }
                sort(res.begin()+1,res.end());
                ans.push_back(res);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
        Graph g;
        for(int i=0;i<accounts.size();i++){
            string name=accounts[i][0];
            string mapping=accounts[i][1];
            g.add_edge(mapping,mapping,name);
            for(int j=2;j<accounts[i].size();j++){
                g.add_edge(mapping,accounts[i][j],name);
            }
        }
        return g.merge();
    }
};
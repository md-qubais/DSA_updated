/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Graph{
public:
    
    unordered_map<int,list<Employee*>> l;
    
    void add_edge(int id,Employee*u){
        l[id].push_back(u);
    }
    
    int dfs(int id,unordered_map<int,bool>&visited){
        visited[id]=true;
        int ans=0;
        for(auto&it:l[id]){
            if(!visited[it->id]){
                ans+=it->importance;
                ans+=dfs(it->id,visited);
            }
        }
        return ans;
    }
    
    int get_sum(int id,Employee*emp){
        int ans=emp->importance;
        unordered_map<int,bool> visited;
        return ans+dfs(id,visited);
    }

};

class Solution{
public:
    
    int getImportance(vector<Employee*> employees, int id){
        Graph g;
        unordered_map<int,Employee*> mapping;
        for(auto&it:employees){
            mapping[it->id]=it;
        }
        for(auto&it:employees){
            int num=it->id;
            for(auto&i:it->subordinates){
                Employee*temp=mapping[i];
                g.add_edge(num,temp);
            }
        }
        return g.get_sum(id,mapping[id]);
    }

};
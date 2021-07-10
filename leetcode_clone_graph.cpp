/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* src,unordered_map<int,bool>&visited,unordered_map<int,Node*>&mapping){
        visited[src->val]=true;
        mapping[src->val]=new Node(src->val);
        for(auto&it:src->neighbors){
            if(!visited[it->val]){
                dfs(it,visited,mapping);
            }
        }
    }
    Node* cloneGraph(Node* node){
        if(!node){
            return nullptr;
        }
        unordered_map<int,Node*> mapping;
        unordered_map<int,bool> visited;
        dfs(node,visited,mapping);
        Node*root=mapping[node->val];
        queue<Node*> q;
        visited.clear();
        q.push(node); 
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(visited[temp->val]){
                continue;
            }
            visited[temp->val]=true;
            Node* m=mapping[temp->val];
            for(auto&it:temp->neighbors){
                m->neighbors.push_back(mapping[it->val]);
                q.push(it);
            }
        }
        return root;
    }
};
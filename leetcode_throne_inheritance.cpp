class Node{
public:
    string val;
    Node*left,*right;
    Node(string val){
        this->val=val;
        left=right=nullptr;
    }
};


class ThroneInheritance {
public:
    unordered_map<string,Node*> mapping;
    Node*root;
    string king;
    ThroneInheritance(string kingName) {
        root=new Node(kingName);
        mapping[kingName]=root;
        king=kingName;
    }

    void birth(string parentName, string childName) {
        Node*n=new Node(childName);
        mapping[childName]=n;
        //if its the first born child of the parent then insert that child
        // on the left of that parent
        if(!mapping[parentName]->left){
            mapping[parentName]->left=n;
        }
        //if its not the first born child of the parent then insert that child
        //at the right most of the first child of that parent
        else{
            Node*temp=mapping[parentName]->left;
            while(temp->right){
                temp=temp->right;
            }
            temp->right=n;
        }
    }
    
    void death(string name) {
        mapping.erase(name);
    }

    void preorder(Node*root,vector<string>&ans){
        if(!root) return;
        if(mapping[root->val]){
            ans.push_back(root->val);
        }
        preorder(root->left,ans);
        preorder(root->right,ans);
    }


    vector<string> getInheritanceOrder() {
        vector<string> ans;
        preorder(root,ans);
        return ans;
    }
};

class TreeNode{
public:
    int val;
    TreeNode*left,*right;
    TreeNode(int val){
        this->val;
        left=right=nullptr;
    }
};

//bst has a property that lesser than root goes to left
//and greater than root goes to right
bool find(TreeNode*root,int val){
    while(root){
        if(root->val==val){
            return true;
        }
        if(root->val<val){
            root=root->right;
        }else{
            root=root->left;
        }
    }
    return false;
}

vector<int> node_to_root_path(TreeNode*root,int val){
    bool found=false;
    vector<int> ans;
    while(root){
        if(root==val){
            ans.push_back(val);
            found=true;
            break;
        }
        ans.push_back(root->val);
        if(root->val>val){
            root=root->right;
        }else{
            root=root->left;
        }
    }
    if(!found){
        ans.clear();
        return ans;
    }
    return ans;
}


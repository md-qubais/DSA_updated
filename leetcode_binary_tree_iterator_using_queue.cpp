class BSTIterator {
public:
    deque<TreeNode*> q;
    BSTIterator(TreeNode* root){
        while(root){
            q.push_back(root);
            root=root->left;
        }
    }
    
    int next(){
        TreeNode*temp=q.back();
        int num=temp->val;
        q.pop_back();
        
        if(temp->right) {
            q.push_back(temp->right);
        }else{
            return num;
        }
        temp=q.back();
        while(temp){
            if(temp->left) q.push_back(temp->left);
            temp=temp->left;
        }
        return num;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

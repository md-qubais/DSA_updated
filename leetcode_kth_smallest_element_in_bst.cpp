class Solution{
public:
    void all_left(TreeNode*root,stack<TreeNode*>&st){
        if(!root){
            return;
        }
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    int kthSmallest(TreeNode* root, int k){
        stack<TreeNode*> st;
        all_left(root,st);
        while(!st.empty()){
            TreeNode*temp=st.top();
            st.pop();
            k--;
            if(k==0){
                return temp->val;
            }
            all_left(temp->right,st);
        }
        return -1;
    }
};
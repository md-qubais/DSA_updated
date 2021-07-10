class Solution {
public:
    TreeNode* recover(TreeNode*root,int left=INT_MIN,int right=INT_MAX){
        if(!root){
            return root;
        }
        if(left>root->val or right<root->val){
            return root;
        }
        TreeNode*left_tree=recover(root->left,left,root->val);
        if(left_tree){
            //check here
            int val=left_tree->val;
            if(val>root->val){
                //swapping
                swap(left_tree->val,root->val);
                return root;
            }
        }
        TreeNode*right_tree=recover(root->right,root->val,right);
        if(right_tree){
            //check here
            int val=right_tree->val;
            if(val<root->val){
                //swapping
                swap(root->val,right_tree->val);
                return root;
            }
        }
        return nullptr;
    }
    void recoverTree(TreeNode* root){      
        recover(root);
    }
};

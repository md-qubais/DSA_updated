class Solution{
public:
    TreeNode* sufficientSubset(TreeNode*root,int limit,int sum){
        if(!root){
            return nullptr;
        }
        if(root->left){
            root->left=sufficientSubset(root->left,limit,sum+root->left->val);
        }
        if(root->right){
            root->right=sufficientSubset(root->right,limit,sum+root->right->val);
        }
        if(!root->left and !root->right and sum<){

        }
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit){
        return sufficientSubset(root,limit,root->val);
    }
};
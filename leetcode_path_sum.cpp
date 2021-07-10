class Solution{
public:
    int ans=0;
    void mila_kiya(TreeNode*root,int targetSum){
        if(!root) return;
        if(targetSum-root->val==0){
            ans++;
        }
        mila_kiya(root->left,targetSum-root->val);
        mila_kiya(root->right,targetSum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum){
        if(!root){
            return ans;
        }
        mila_kiya(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return ans;
    }
};
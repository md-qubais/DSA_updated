
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return nullptr;
        }
        if(root==p or root==q){
            return root;
        }
        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);
        if(left and right){
            return root;
        }
        if(left){
            return left;
        }
        if(right){
            return right;
        }
        return nullptr;
    }
};
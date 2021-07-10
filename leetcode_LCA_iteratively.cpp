class Solution{
public:
    //leetcode iterative lca
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(root==p or root==q){
                return root;
            }
            if(root->val>p->val and root->val>q->val){
                root=root->left;
            }else if(root->val<p->val and root->val<q->val){
                root=root->right;
            }
            else{
                return root;
            }
        }
        return nullptr;
    }
};

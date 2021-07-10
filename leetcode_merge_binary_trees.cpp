class Solution{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2){
        if(!root1 and !root2){
            return nullptr;
        }
        TreeNode*root=nullptr;
        if(root1 and root2){
            root=new TreeNode(root1->val+root2->val);
            root->left=mergeTrees(root1->left,root2->left);
            root->right=mergeTrees(root1->right,root2->right);
            return root;
        }
        if(root1){
            root=new TreeNode(root1->val);
            root->left=mergeTrees(root1->left,root2);
            root->right=mergeTrees(root1->right,root2);
            return root;
        }
        root=new TreeNode(root2->val);
        root->left=mergeTrees(root1,root2->left);
        root->right=mergeTrees(root1,root2->right);
        return root;
    }
};
class Pair{
public:
    bool isleaf;
    int num;
    Pair(){
        this->num=0;
        this->isleaf=true;
    }
};
class Solution {
public:
    int ans=0;
    Pair distribute(TreeNode*root){
        Pair p;
        if(!root){
            return p;
        }
        Pair left=distribute(root->left);
        Pair right=distribute(root->right);
        if(left.isleaf and right.isleaf){
            if(root->val==0){
                p.num=1;
                ans++;
            }else if(root->val>1){
                int num=root->val-1;
                num=-num;
                p.num=num;
                ans+=root->val-1;
            }
            return p;
        }
    }
    int distributeCoins(TreeNode* root) {
        distribute(root);
        return ans;
    }
};
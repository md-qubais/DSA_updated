
class Solution {
public:
    
    int sum(TreeNode*root,int x=-1){
        if(!root){
            return 0;
        }
        if(root->val==x){
            return 0;
        }
        return 1+sum(root->left,x)+sum(root->right,x);
    }

    int left_sum(TreeNode*root,int x=-1){
        if(!root){
            return 0;
        }
        if(root->val==x){
            return sum(root->left,x);
        }
        return left_sum(root->left,x)+left_sum(root->right,x);
    }

    int right_sum(TreeNode*root,int x){
        if(!root){
            return 0;
        }
        if(root->val==x){
            return sum(root->right,x);
        }
        return right_sum(root->left,x)+right_sum(root->right,x);
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int parent_sum=sum(root,x);
        int left=left_sum(root,x);
        int right=right_sum(root,x);
        if(parent_sum>(left+right+1)){
            return true;
        }
        if(left>(parent_sum+right+1)){
            return true;
        }
        if(right>(parent_sum+left+1)){
            return true;
        }
        return false;
    }

};
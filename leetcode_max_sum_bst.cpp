class Pair{
public:
    int min;
    int max;
    bool isBst;
    int sum;
    Pair(){
        this->min=INT_MAX;
        this->max=INT_MIN;
        this->sum=0;
        this->isBst=true;
    }
    Pair(int min,int max,int sum,bool isBst){
        this->min=min;
        this->max=max;
        this->sum=sum;
        this->isBst=isBst;    
    }
};


class Solution {
public:
    int res=0;
    Pair max_sum(TreeNode*root){
        if(!root){
            return Pair();
        }
        if(!root->left and !root->right){
            res=max(res,root->val);
            return Pair(root->val,root->val,root->val,true);
        }
        Pair left=max_sum(root->left);
        Pair right=max_sum(root->right);
        if(left.isBst and right.isBst){
            if(root->val>left.max and root->val<right.min){
                Pair ans;
                ans.min=min(root->val,left.min);
                ans.max=max(root->val,right.max);
                ans.sum=right.sum+left.sum+root->val;
                res=max(res,ans.sum);
                return ans;
            }
        }
        Pair ans=left.sum>right.sum?left:right;
        ans.isBst=false;
        return ans;
    }
    int maxSumBST(TreeNode* root) {
        if(!root){
            return 0;
        }
        max_sum(root);
        return res>0?res:0;
    }
};
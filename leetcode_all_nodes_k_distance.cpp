class Pair{
public:
    TreeNode*block;
    int k;
    Pair(){
        this->block=nullptr;
    }
};
class Solution {
public:
    void kdown(TreeNode*root,TreeNode*block,int k,vector<int>&ans){
        if(!root) return;
        if(block and root==block){
            return;
        }
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        kdown(root->left,block,k-1,ans);
        kdown(root->right,block,k-1,ans);
    }
    Pair kdistance(TreeNode*root,TreeNode* target,int k,vector<int>&ans){
        Pair path;
        if(!root){
            return path;
        }
        if(root==target){
            kdown(root,nullptr,k,ans);
            path.block=root;
            path.k=k-1;
            return path;
        }
        Pair left=kdistance(root->left,target,k,ans);
        if(left.block!=nullptr){
            kdown(root,left.block,left.k,ans);
            path.block=root;
            path.k=left.k-1;
            return path;
        }
        Pair right=kdistance(root->right,target,k,ans);
        if(right.block!=nullptr){
            kdown(root,right.block,right.k,ans);
            path.block=root;
            path.k=right.k-1;
            return path;
        }
        return  path;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
        vector<int> ans;
        kdistance(root,target,k,ans);
        return ans;
    }
};
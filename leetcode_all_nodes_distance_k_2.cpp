class Solution {
public:
    //without using Pair class
    void kdown(TreeNode*root,TreeNode*block,int k,vector<int>&ans){
        if(!root){
            return;
        }
        if(root==block){
            return;
        }
        if(k<0){
            return;
        }
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        kdown(root->left,block,k-1,ans);
        kdown(root->right,block,k-1,ans);
        return;
    }
    int K_distance(TreeNode*root,TreeNode*target,int k,vector<int>&ans){
        if(!root){
            return -1;
        }
        if(root==target){
            kdown(root,nullptr,k,ans);
            return 1;
        }
        int left=K_distance(root->left,target,k,ans);
        if(left!=-1){
            cout<<left<<endl;
            kdown(root,root->left,k-left,ans);
            return left+1;
        }
        int right=K_distance(root->right,target,k,ans);
        if(right!=-1){
            kdown(root,root->right,k-right,ans);
            return right+1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
        vector<int> ans;
        K_distance(root,target,k,ans);
        return ans;
    }
};
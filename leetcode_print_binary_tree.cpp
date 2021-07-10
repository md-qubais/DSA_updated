class Solution {
public:
    int height(TreeNode*root){
        if(!root){
            return -1;
        }
        return 1+max(height(root->left),height(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int rows=height(root);
        int cols=(1<<(rows+1))-1;
        vector<vector<string>> ans(rows+1);
        for(int i=0;i<rows+1;i++){
            vector<string> temp(cols);
            ans[i]=temp;
        }
        ans[0][(c-1)/2]=to_string(root->val);
        return ans;
    }
};
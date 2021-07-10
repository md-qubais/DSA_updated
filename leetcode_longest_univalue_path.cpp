class Solution {
public:
    int longestUnivaluePath(TreeNode* root){
        Pair ans=path(root);
        return ans.val;
    }
};
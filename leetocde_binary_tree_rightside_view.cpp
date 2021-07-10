class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            res.push_back(q.front()->val);
            while(size--){
                TreeNode*t=q.front();
                q.pop();
                if(t->right) q.push(t->right);
                if(t->left) q.push(t->left);
            }
        }
        return res;
    }
};
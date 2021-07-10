class Solution{
public:
    //flop idea and this answer is not accepted
    int widthOfBinaryTree(TreeNode* root){
        deque<pair<TreeNode*,int>> q;
        q.push_back({root,1});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            ans=max(ans,q.back().second-q.front().second+1);
            while(size--){
                pair<TreeNode*,int> temp=q.front();
                q.pop_front();
                if(temp.first->left){
                    q.push_back({temp.first->left,temp.second*2});
                }
                if(temp.first->right){
                    q.push_back({temp.first->right,temp.second*2+1});
                }
            }
        }
        return ans;
    }
};
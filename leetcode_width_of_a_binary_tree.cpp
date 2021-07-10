class Solution {
public:

    int max_level(TreeNode*root){
        if(!root){
            return -1;
        }
        return 1+max(max_level(root->left),max_level(root->right));
    }

    int widthOfBinaryTree(TreeNode* root){
        int level=max_level(root);
        int ans=0;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        while(!q.empty()){
            if(q.front().first>level){
                break;
            }
            int size=q.size();
            vector<TreeNode*> arr;
            while(size--){
                pair<int,TreeNode*> temp=q.front();
                q.pop();
                arr.push_back(temp.second);
                if(!temp.second){
                    q.push({temp.first+1,NULL});
                    q.push({temp.first+1,NULL});
                    continue;
                }
                q.push({temp.first+1,temp.second->left});
                q.push({temp.first+1,temp.second->right});
            }   
            int i=0;
            int j=arr.size()-1;
            while(i<arr.size() and !arr[i]){
                i++;
            }
            while(j>=0 and !arr[j]){
                j--;
            }
            if(i<=j){
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
    
};
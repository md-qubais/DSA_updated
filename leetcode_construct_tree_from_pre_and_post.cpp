
class Solution {
public:
    TreeNode* construct(vector<int>& pre, vector<int>& post,int&i,int s,int e){
        if(i>=pre.size()){
            return nullptr;
        }
        if(s==e){
            return new TreeNode(pre[i++]);
        }
        if(s>e){
            return nullptr;
        }
        TreeNode*root=new TreeNode(pre[i++]);
        if(i==pre.size()){
            return root;
        }
        if(i==pre.size()){
            return root;
        }
        int index=-1;
        for(int j=s;j<=e;j++){
            if(pre[i]==post[j]){
                index=j;
                break;
            }
        }
        if(index==-1){
            return root;
        }
        root->left=construct(pre,post,i,s,index);
        root->right=construct(pre,post,i,index+1,e-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post){
        int i=0;
        return construct(pre,post,i,0,post.size()-1);
    }
};
class Solution{
public:
    TreeNode*first=NULL;
    TreeNode*second=NULL;
    TreeNode*prev=NULL;
    void recoverTree(TreeNode* root,TreeNode*&next){
        if(!root){
            return;
        }
        recoverTree(root->left,next);
        if(prev){
            if(prev->val>root->val and !first){
                first=prev;
            }else if(first and prev->val>root->val){
                second=root;
            }
        }
        if(!next){
            if(first) next=root;
        }
        if(first and second){
            swap(first->val,second->val);
            first=NULL;
            second=NULL;
            prev=NULL;
            return;
        }
        prev=root;
        recoverTree(root->right,next);
    }
    void recoverTree(TreeNode*root){
        TreeNode*next=NULL;
        recoverTree(root,next);
        if(first and next){
            swap(first->val,next->val);
        }
        return;
    }
};

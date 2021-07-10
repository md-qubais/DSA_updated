class Solution {
public:
    int get_height(TreeNode*root){
        if(!root){
            return 0;
        }
        return max(get_height(root->left),get_height(root->right))+1;
    }
    int balance_Factor(TreeNode*root){
        return get_height(root->left)-get_height(root->right);
    }

    TreeNode* right_rotation(TreeNode*root){
        TreeNode*B=root->left;
        TreeNode*B_right=B->right;
        B->right=root;
        root->left=B_right;
        return B;
    }
    TreeNode* left_rotation(TreeNode*root){
        TreeNode*B=root->right;
        TreeNode*B_left=B->left;
        B->left=root;
        root->right=B_left;
        return B;
    }

    TreeNode* balanceBST(TreeNode* root){
        if(!root){
            return nullptr;
        }
        root->left=balanceBST(root->left);
        root->right=balanceBST(root->right);
        int bf=balance_Factor(root);
        //left
        if(bf==2){
            int sub_bf=balance_Factor(root->left);
            //left - left
            if(sub_bf==1){
                root=right_rotation(root);
            }
            //left - right
            else if(sub_bf==-1){
                root->left=left_rotation(root->left);
                root=right_rotation(root);
            }else{
                root=right_rotation(root);
            }
        }else if(bf>2){
            root=right_rotation(root);
        }
        //right
        else if(bf==-2){
            int sub_bf=balance_Factor(root->right);
            //right - right
            if(sub_bf==-1){
                root=left_rotation(root);
            }
            //right - left
            else if(sub_bf==1){
                root->right=right_rotation(root->right);
                root=left_rotation(root);
            }else{
                root=left_rotation(root);
            }
        }else if(bf<-2){
            root=left_rotation(root);
        }
        return root;
    }
};
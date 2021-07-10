
class Solution{
public: 
    Node* bToDLL_helper(Node *root){
        if(!root){
            return nullptr;
        }
        Node*left=bToDLL_helper(root->left);
        Node*right=bToDLL_helper(root->right);
        if(!left and !right){
            return root;
        }
        if(left and right){
            while(right->left){
                right=right->left;
            }
            while(left->right){
                left=left->right;
            }
            left->right=root;
            root->left=left;
            root->right=right;
            right->left=root;
            while(root->right){
                root=root->right;
            }
            return root;
        }

        if(left){
            left->right=root;
            root->left=left;
            return root;
        }

        if(right){
            root->right=right;
            root->right->left=root;
            root=root->right;
            return root;
        }
        return root;
    }


    Node* bToDLL(Node*root){
        root=bToDLL_helper(root);
        while(root->left){
            root=root->left;
        }
        return root;
    }
};

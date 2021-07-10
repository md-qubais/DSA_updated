
class Solution{
public: 
    Node*head=nullptr;
    Node*tail=head;
    Node* bToDLL_helper(Node*root){
        if(!root){
            return nullptr;
        }
        Node*left=bToDLL_helper(root->left);
        if(!head){
            head=tail=root;
        }else{
            tail->right=root;
            root->left=tail;
            tail=tail->right;
        }
        Node*right=bToDLL_helper(root->right);
    }
    Node * bToDLL(Node *root){
        if(!root){
            return root;
        }
        bToDLL_helper(root);
        Node*ans=head->right;
        head->left=nullptr;
        return ans;
    }
};
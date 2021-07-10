class Solution{
public:     
    void insert_all_left(Node*root,list<Node*>&st){
        while(root){
            st.push_back(root);
            root=root->left;
        }
    }
    Node * bToDLL(Node *root){
        Node*head=nullptr;
        Node*tail=nullptr;
        list<Node*> st;
        insert_all_left(root,st);
        while(st.size()>0){
            Node*temp=st.back();
            st.pop_back();
            if(temp->right){
                insert_all_left(temp->right,st);
            }
            if(!head){
                head=tail=temp;
            }else{
                tail->right=temp;
                temp->left=tail;
                tail=tail->right;
            }
        }
        return head;
    }
};

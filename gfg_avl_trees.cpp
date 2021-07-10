#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define pb push_back
#define p push
#define fori(n) for(int i=0;i<n;i++)
#define ford(n) for(int i=n-1;i>=0;i--)
#define fl(x,n) for(int i=x;i<n;i++)
#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int data){
      this->data=data;
      left=right=nullptr;
      height=1;
    }
};
  int height(Node*root){
    if(!root){
      return 0;
    }
    return root->height;
  }
  void update(Node*root){
    root->height=max(height(root->left),height(root->right))+1;
  }
  Node* right_rotation(Node*root){
    Node*B=root->left;
    Node*B_right=B->right;
    B->right=root;
    root->left=B_right;
    update(root);
    update(B);
    return B;
  }
  Node* left_rotation(Node*root){
    Node*B=root->right;
    Node*B_left=B->left;
    B->left=root;
    root->right=B_left;
    update(root);
    update(B);
    return B;
  }
  int balanceFactor(Node*root){
    return height(root->left)-height(root->right);
  }
  Node* insertToAVL(Node* node, int data){
    if(!node){
      return new Node(data);
    }
    if(node->data==data){
      return node;
    }
    if(node->data>data){
      node->left=insertToAVL(node->left,data);
    }else{
      node->right=insertToAVL(node->right,data);
    }
    node->height=max(height(node->left),height(node->right))+1;
    int bf_upper=balanceFactor(node);
    //left
    if(bf_upper==2){
      int bf_lower=balanceFactor(node->left);
      //left - left
      if(bf_lower==1){
        node=right_rotation(node);
      }//left - right
      else if(bf_lower==-1){
        node->left=left_rotation(node->left);
        node=right_rotation(node);
      }
    }//right
    else if(bf_upper==-2){
      int bf_lower=balanceFactor(node->right);
      //right - right 
      if(bf_lower==-1){
        node=left_rotation(node);
      }//right - left
      else if(bf_lower==1){
        node->right=right_rotation(node->right);
        node=left_rotation(node);
      }
    }
    return node;
  }


void inorder(Node*root){
  if(!root){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}


void display(Node *root)
{
    if (root == nullptr)
        return;

    string str = "";
    str += ((root->left != nullptr ? to_string(root->left->data) : "."));
    str += (" -> " + to_string(root->data) + " <- ");
    str += ((root->right != nullptr ? to_string(root->right->data) : "."));
    cout << str << endl;

    display(root->left);
    display(root->right);
}

int32_t main(){
  qubais_judge;
  IOS;
  int n;
  cin>>n;
  Node*root=nullptr;
  while(n--){
    int num;
    cin>>num;
    root=insertToAVL(root,num);
  }
  display(root);
  return 0;
}



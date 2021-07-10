#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

int i;
TreeNode*buildTree(vector<int> &postorder, vector<int> &inorder,int s,int e){
    if(i<0 or s>e){
        return nullptr;
    }
    int mid=-1;
    for(int k=s;k<=e;k++){
        if(inorder[k]==postorder[i]){
            mid=k;
            break;
        }
    }
    TreeNode*root=new TreeNode(postorder[i--]);
    root->right=buildTree(postorder,inorder,mid+1,e);
    root->left=buildTree(postorder,inorder,s,mid-1);
    return root;

}

TreeNode *buildTree(vector<int> &postorder, vector<int> &inorder){
    i=postorder.size()-1;
    return buildTree(postorder,inorder,0,inorder.size()-1);
}

// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> post(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(post,in);
    display(root);
}

int main()
{
    solve();
    return 0;
}
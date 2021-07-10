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
int i=0;
TreeNode*buildTree(vector<int> &preorder, vector<int> &inorder,int s,int e){
    if(i==preorder.size() or s>e){
        return nullptr;
    }
    int mid=-1;
    for(int k=s;k<=e;k++){
        if(inorder[k]==preorder[i]){
            mid=k;
            break;
        }
    }
    TreeNode*root=new TreeNode(preorder[i++]);
    root->left=buildTree(preorder,inorder,s,mid-1);
    root->right=buildTree(preorder,inorder,mid+1,e);
    return root;

}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return buildTree(preorder,inorder,0,inorder.size()-1);
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
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(pre, in);
    display(root);
}

int main()
{
    solve();
    return 0;
}
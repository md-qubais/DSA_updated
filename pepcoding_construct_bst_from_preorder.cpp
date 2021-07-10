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
TreeNode* bstFromPreorder(vector<int>&preorder,int left,int right){
    if(i>=preorder.size()){
        return nullptr;
    }
    if(preorder[i]<left or preorder[i]>right){
        return nullptr;
    }
    TreeNode*root=new TreeNode(preorder[i++]);
    root->left=bstFromPreorder(preorder,left,root->val);
    root->right=bstFromPreorder(preorder,root->val,right);
    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder){
    return bstFromPreorder(preorder,INT_MIN,INT_MAX);
}

// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return ;

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

    TreeNode *root = bstFromPreorder(pre);
    display(root);
}

int32_t main(){
    qubais_judge;
    IOS;
    solve();
    return 0;
}
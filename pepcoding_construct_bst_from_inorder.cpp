
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

TreeNode* constructFromInOrder(vector<int>&in,int s,int e){
    if(s>e){
        return nullptr;
    }
    if(s==e){
        return new TreeNode(in[s]);
    }
    int mid=(s+e)/2;
    TreeNode*root=new TreeNode(in[mid]);
    root->left=constructFromInOrder(in,s,mid-1);
    root->right=constructFromInOrder(in,mid+1,e);
    return root;
}

TreeNode *constructFromInOrder(vector<int> &in){
    return constructFromInOrder(in,0,in.size()-1);
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
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = constructFromInOrder(in);
    display(root);
}
int32_t main(){
    qubais_judge;
    IOS;
    solve();
    return 0;
}
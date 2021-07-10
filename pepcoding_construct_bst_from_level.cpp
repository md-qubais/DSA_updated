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

class levelPair
{
public:
    TreeNode *par = nullptr;
    int lb = -(int)1e8;
    int rb = (int)1e8;

    levelPair()
    {
    }

    levelPair(TreeNode *par, int lb, int rb)
    {
        this->par = par;
        this->lb = lb;
        this->rb = rb;
    }
};

TreeNode *constructBSTFromLevelOrder(vector<int> &arr){
    TreeNode*root=new TreeNode(arr[0]);
    int i=1;
    queue<pair<TreeNode*,pair<int,int>>> q;
    q.push({root,{INT_MIN,INT_MAX}});
    while(!q.empty()){
        pair<TreeNode*,pair<int,int>> temp=q.front();
        q.pop();
        if(i>=arr.size()){
            break;
        }
        if(temp.second.first<=arr[i] and temp.first->val>=arr[i]){
            TreeNode*n=new TreeNode(arr[i++]);
            temp.first->left=n;
            q.push({n,{temp.second.first,temp.first->val}});
        }
        if(i>=arr.size()){
            break;
        }
        if(temp.first->val<=arr[i] and temp.second.second>=arr[i]){
            TreeNode*n=new TreeNode(arr[i++]);
            temp.first->right=n;
            q.push({n,{temp.first->val,temp.second.second}});
        }
        

    }
    return root;
}

/*
int idx = 0;
    queue<levelPair *> que;
    que.push(new levelPair());
    TreeNode *root = nullptr;

    while (que.size() != 0 && idx < arr.size())
    {
        levelPair *pair = que.front();
        que.pop();
        lb->intmin;
        rb->intmax;

        if (arr[idx] < pair->lb || arr[idx] > pair->rb)
            continue;

        TreeNode *node = new TreeNode(arr[idx++]);
        if (pair->par == nullptr)
            root = node;
        else
        {
            if (node->val < pair->par->val)
                pair->par->left = node;
            else
                pair->par->right = node;
        }

        que.push(new levelPair(node, pair->lb, node->val));
        que.push(new levelPair(node, node->val, pair->rb));
    }
    return root;
*/




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

    TreeNode *root = constructBSTFromLevelOrder(pre);
    display(root);
}
int32_t main(){
    qubais_judge;
    IOS;
    solve();
    return 0;
}




#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TreeNode
{
public:
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;

  TreeNode(int val)
  {
    this->val = val;
  }
};
class BSTIterator{
public:
	stack<pair<TreeNode*,int>> s;
    BSTIterator(TreeNode* root){
    	s.push({root,0});
    	while(s.top().second==1){
    		TreeNode*temp=s.top().first;
    		int n=s.top().second;
    		if(n==0){
    			s.top().second++;
    			if(temp->left){
    				s.push({temp->left,0});
    			}
    		}
    	}
    }

    int next(){
    	while(s.top().second!=1){
    		TreeNode*temp=s.top().first;
    		int n=s.top().second;
    		if(n==0){
    			s.top().second++;
    			if(temp->left){
    				s.push({temp->left,0});
    			}
    		}
    	}

    	TreeNode*temp=s.top().first;
        int num=s.top().first->val;
    	s.pop();
        if(temp->right){
    		s.push({temp->right,0});
    	}
    	return num;
    }

    bool hasNext(){
    	if(s.size()>=1){
    		return true;
    	}
    	return false;
    }
};

// input_Section_====================================================================

void display(TreeNode* node)
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

TreeNode* buildTree(vector<int>& inOrder, int si, int ei)
{
  if (si > ei)
    return nullptr;

  int mid = (si + ei) / 2;
  TreeNode* node = new TreeNode(inOrder[mid]);

  node->left = buildTree(inOrder, si, mid - 1);
  node->right = buildTree(inOrder, mid + 1, ei);

  return node;
}

TreeNode* constructFromInOrder(vector<int>& in)
{
  int n = in.size();
  return buildTree(in, 0, n - 1);
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

  TreeNode* root = constructFromInOrder(in);
  BSTIterator itr(root);
  while (itr.hasNext())
  {
    cout << (itr.next()) << endl;
  }
}

int main()
{
  solve();
  return 0;
}
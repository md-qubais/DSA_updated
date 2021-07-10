#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define fori(n) for(int i=0;i<n;i++)
#define ford(n) for(int i=n-1;i>=0;i--)
#define fl(x,n) for(int i=x;i<n;i++)
#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;

class node{
public:
	int data;
	node*right,*left;
	node(){
	}
	node(int data){
		this->data=data;
		this->right=this->left=NULL;
	}
};

node* buildtree(vector<int>&arr,int&i){
	if(arr[i]==-1){
		i++;
		return NULL;
	}
	node*root=new node(arr[i++]);
	root->left=buildtree(arr,i);
	root->right=buildtree(arr,i);
	return root;
}

void preorder(node*root){
	if(!root){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void display(node*root){
	if(!root){
		return;
	}
	if(root->left){
		cout<<root->left->data;
	}else{
		cout<<"NULL";
	}
	cout<<" <-- ";
	cout<<root->data;
	cout<<" --> ";
	if(root->right){
		cout<<root->right->data;
	}else{
		cout<<"NULL";
	}
	cout<<endl;
	display(root->left);
	display(root->right);
}

int size(node*root){
	if(!root) return 0;
	return 1+size(root->left)+size(root->right);
}

int sum(node*root){
	if(!root) return 0;
	return root->data+sum(root->left)+sum(root->right);
}

int Max(node*root){
	if(!root) return INT_MIN;
	return max(root->data,max(Max(root->left),Max(root->right)));
}

int height(node*root){
	if(!root) return -1;
	return 1+max(height(root->left),height(root->right));
}
void level_order_new_line(node*root){
	if(root==NULL){
		return ;
	}
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node*temp=q.front();
		q.pop();
		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}else{
			cout<<temp->data<<" ";
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
}

void print_k_levels(node*root,int k){
	if(!root){
		return;
	}
	if(k==0){
		cout<<root->data<<endl;
		return;
	}
	print_k_levels(root->left,k-1);
	print_k_levels(root->right,k-1);
}

string pre_order="";
string in_order="";
string post_order="";
void iterative_pre_post_in(node*root){
	if(!root) return;
	stack<pair<node*,int>> st;
	st.push(make_pair(root,0));
	while(!st.empty()){
		pair<node*,int> p=st.top();
		st.pop();
		if(p.first==NULL) continue;
		if(p.second==0){
			pre_order+=to_string(p.first->data)+" ";
			p.second++;
			st.push(p);
			st.push(make_pair(p.first->left,0));
		}else if(p.second==1){
			in_order+=to_string(p.first->data)+" ";
			p.second++;
			st.push(p);
			st.push(make_pair(p.first->right,0));
		}else{
			post_order+=to_string(p.first->data)+" ";
		}
	}
}


/*
vector<node*> node_to_root_path(node*root,int data){
	vector<node*> path;
	if(!root) return path;
	if(root->data==data){
		path.push_back(root);
		return path;
	}
	vector<node*> left=node_to_root_path(root->left,data);
	if(left.size()>0){
		left.push_back(root);
		return left;
	}
	vector<node*>right=node_to_root_path(root->right,data);
	if(right.size()>0){
		right.push_back(root);
		return right;
	}
	return path;
}


/*

void node_to_root_path(node*root,int data,vector<node*>&res){
	if(!root) return;
	if(root->data==data){
		res.push_back(root);
		return;
	}
	node_to_root_path(root->left,data,res);
	if(res.size()>0){
		res.push_back(root);
		return;
	}
	node_to_root_path(root->right,data,res);
	if(res.size()>0){
		res.push_back(root);
		return;
	}
	return;
}
*/

bool node_to_root_path(node*root,int data,vector<node*>&ans){
	if(!root){
		return false;
	}
	if(root->data==data){
		ans.push_back(root);
		return true;
	}
	bool res=node_to_root_path(root->left,data,ans) or node_to_root_path(root->right,data,ans);
	if(res){
		ans.push_back(root);
		return true;
	}
	return false;
}

list<list<int>> node_to_all_leaf_path(node*root){
	list<list<int>> path;
	if(!root){
		return path;
	}
	list<list<int>> left=node_to_all_leaf_path(root->left);
	list<list<int>> right=node_to_all_leaf_path(root->right);
	if(left.size()==0 and right.size()==0){
		list<int> temp;
		temp.push_back(root->data);
		path.push_back(temp);
	}
	for(auto&it:left){
		it.push_front(root->data);
		path.push_back(it);
	}
	for(auto&it:right){
		it.push_front(root->data);
		path.push_back(it);
	}
	return path;
}

int single_child_parent(node*root){
	if(!root) return 0;
	if((!root->left and root->right) or (!root->right and root->left)){
		if(root->right){
			return 1+single_child_parent(root->right);
		}
		if(root->left){
			return 1+single_child_parent(root->left);
		}
	}
	int left=single_child_parent(root->left);
	int right=single_child_parent(root->right);
	return left+right;
}

void print_single_child_nodes(node*root){
	if(!root) return;
	if((!root->left and root->right) or (!root->right and root->left)){
		cout<<root->data<<" ";
	}
	print_single_child_nodes(root->left);
	print_single_child_nodes(root->right);
}



void level_order(node*root){
	queue<node*> q;
	q.push(root);
	vector<vector<int>> ans;
	while(!q.empty()){
		int size=q.size();
		vector<int> temp;
		while(size--){
			node*t=q.front();
			q.pop();
			temp.push_back(t->data);
			if(t->left) q.push(t->left);
			if(t->right) q.push(t->right);
		}
		ans.push_back(temp);
	}


	//for accessing any view we can just call
	//the zeroth 0th index or oth col of every row
	//either it is left view or right view we will get the 
	//exact same answer
	//for left view we only just have to push the left child first 
	//and than right child
	//for right view we only just have to push the right child first
	//and than left child

	//left view
	/*
	for(int i=0;i<ans.size();i++){
		cout<<ans[i][0]<<endl;
	}*/


	//right view
	for(int i=0;i<ans.size();i++){
		cout<<ans[i][ans[i].size()-1]<<endl;
	}
}

void widthOfShadow(node*root,int level,vector<int>&MinMax){
	if(!root){
		return ;
	}
	MinMax[0]=min(MinMax[0],level);
	MinMax[1]=max(MinMax[1],level);
	widthOfShadow(root->left,level-1,MinMax);
	widthOfShadow(root->right,level+1,MinMax);
}

vector<vector<int>> vertical_level(node*root){
	vector<int> MinMax(2);
	widthOfShadow(root,0,MinMax);
	vector<vector<int>> ans(MinMax[1]-MinMax[0]+1);
	queue<pair<int,node*>> q;
	q.push({-MinMax[0],root});
	while(!q.empty()){
		pair<int,node*> temp=q.front();
		q.pop();
		ans[temp.first].push_back(temp.second->data);
		if(temp.second->left) q.push({temp.first-1,temp.second->left});
		if(temp.second->right) q.push({temp.first+1,temp.second->right});
	}


	//the last value of the every row is the bottom view
	//Bottom view of the binary tree
	//and the first value of every row is the top view
	//top view of the binary tree
	return ans;
}

void diagonal_order_helper(node*root,int level,vector<vector<int>>&ans){
	if(!root){
		return;
	}
	if(ans.size()==level){
		vector<int> temp;
		ans.push_back(temp);
	}
	ans[level].push_back(root->data);
	diagonal_order_helper(root->right,level+1,ans);
	diagonal_order_helper(root->left,level,ans);
}

vector<vector<int>> diagonal_order(node*root){
	vector<vector<int>> ans;
	diagonal_order_helper(root,0,ans);
	return ans;
}




int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(s=="n"){
			arr[i]=-1;
		}else{
			stringstream num(s);
			int n;
			num>>n;
			arr[i]=n;
		}
	}
	int i=0;
	node* root=buildtree(arr,i);
	vector<vector<int>> ans=diagonal_order(root);
	for(int i=0;i<ans.size();i++){
		cout<<i<<" -> ";
		for(auto&it:ans[i]){
			cout<<it<<" ";
		}
		cout<<endl;
	}
	return 0;
}

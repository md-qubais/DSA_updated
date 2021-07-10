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

class node{
public:
	int data;
	node*left,*right;
	node(int val){
		this->data=val;
		left=right=nullptr;
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

void catch_fire(node*root,int time,node*block,vector<vector<int>>&ans){
	if(!root){
		return;
	}
	if(root==block){
		return;
	}
	if(ans.size()==time){
		vector<int> temp;
		ans.push_back(temp);
	}
	ans[time].push_back(root->data);
	catch_fire(root->left,time+1,block,ans);
	catch_fire(root->right,time+1,block,ans);
}

int burning_tree(node*root,int target,vector<vector<int>>&ans){
	if(!root) return -1;
	if(root->data==target){
		catch_fire(root,0,nullptr,ans);
		return 1;
	}
	int left=burning_tree(root->left,target,ans);
	if(left!=-1){
		catch_fire(root,left,root->left,ans);
		return left+1;
	}
	int right=burning_tree(root->right,target,ans);
	if(right!=-1){
		catch_fire(root,right,root->right,ans);
		return right+1;
	}
	return -1;
}


vector<vector<int>> burning_tree(node*root,int target){
	vector<vector<int>> ans;
	burning_tree(root,target,ans);
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
	node*root=buildtree(arr,i);
	vector<vector<int>> ans=burning_tree(root,14);
	for(auto&it:ans){
		for(auto&itr:it){
			cout<<itr<<" ";
		}
		cout<<endl;
	}
	return 0;
}
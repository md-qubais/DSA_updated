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
	/*
	for(int i=0;i<ans.size();i++){
		cout<<ans[i][ans[i].size()-1]<<endl;
	}*/
	for(int i=0;i<ans.size();i++){
		cout<<i<<"=> ";
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
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


	//the last value of the every row of vertical order
	//traversal is the bottom view
	//Bottom view of the binary tree


	//and the first value of every row of vertical order 
	//traversal is the top view
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
	diagonal_order_helper(root->left,level+1,ans);
	diagonal_order_helper(root->right,level,ans);

}


//this method is dfs for figuring out the 
//diagonal order traversal for both clock wise
//and anti clock
//the another bfs method is saved in another
//file named pepcoding_diagonals_orders 
//in here there is the program for bfs for diagonal order
vector<vector<int>> diagonal_order(node*root){
	vector<vector<int>> ans;
	diagonal_order_helper(root,0,ans);


	//and for upper diagonal orders view
	//than if we see from leftup diagonal
	//ouput the first element of every row of diagonal
	
	//and for lower diagonal orders view
	//than if we see from rightdown diagonal
	//output the last element of every row of diagonal
	return ans;
}

class List{
public:
	int val;
	List*prev,*next;
	List(int val){
		this->val=val;
		prev=next=NULL;
	}
};
List*head=new List(0);

void vertical_order_sum(node*root,List*head){
	if(!root){
		return;
	}
	head->val+=root->data;
	if(!head->prev and root->left){
		List*n=new List(0);
		head->prev=n;
		n->next=head;
	}
	vertical_order_sum(root->left,head->prev);
	if(!head->next and root->right){
		List*n=new List(0);
		head->next=n;
		n->prev=head;
	}
	vertical_order_sum(root->right,head->next);
}


void vertical_order_sum(node*root){
	vertical_order_sum(root,head);
	while(head->prev){
		head=head->prev;
	}
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	head=new List(0);
}


void diagonal_order_sum(node*root,List*head){
	if(!root){
		return ;
	}
	head->val+=root->data;
	diagonal_order_sum(root->right,head);
	if(!head->prev and root->left){
		List*n=new List(0);
		head->prev=n;
		n->next=head;
	}
	diagonal_order_sum(root->left,head->prev);
}


void diagonal_order_sum(node*root){
	diagonal_order_sum(root,head);
	while(head->prev){
		head=head->prev;
	}
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
}


/*
//from postorder
//but the answer must be inorder
node* bToDLL(node *root){
	if(!root){
		return nullptr;
	}
	node*left=bToDLL(root->left);
	node*right=bToDLL(root->right);
	if(!left and !right){
		return root;
	}
	if(left and right){
		while(right->left){
			right=right->left;
		}
		while(left->right){
			left=left->right;
		}
		left->right=root;
		root->left=left;
            root->right=right;
            right->left=root;
            while(root->right){
                root=root->right;
            }
            return root;
        }

        if(left){
            left->right=root;
            root->left=left;
            return root;
        }

        if(right){
            root->right=right;
            root->right->left=root;
            return root;
        }
        return root;
    }
*/


void print_ll(node*root){
	node*temp=root;
	while(root->left){
		root=root->left;
	}
	cout<<"forward"<<endl;
	while(root){
		cout<<root->data<<" ";
		temp=root;
		root=root->right;
	}
	cout<<endl;
	cout<<"backward"<<endl;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->left;
	}
}





void insert_all_left(node*root,list<node*>&st){
	while(root){
		st.push_back(root);
		root=root->left;
	}
}
node * bToDLL(node *root){
	node*head=nullptr;
	node*tail=nullptr;
	list<node*> st;
	insert_all_left(root,st);
	while(st.size()>0){
		node*temp=st.back();
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
            tail->right=nullptr;
        }
    }
    return head;
}

node *midNode(node *head){
	if(!head or !head->right){
		return head;
	}
	node*slow=head,*fast=head;
	while(fast->right and fast->right->right){
		fast=fast->right->right;
		slow=slow->right;
	}
    return slow;
}



node *mergeTwoLists(node *l1, node *l2){
    node *ans=NULL;
    node *tail=NULL;
    while(l1 and l2){
        if(l1->data<l2->data){
            if(ans==NULL){
                ans=tail=l1;
                l1=l1->right;
            }else{
                tail->right=l1;
                l1->left=tail;
                tail=l1;
                l1=l1->right;
            }
        }else{
            if(ans==NULL){
                ans=tail=l2;
                l2=l2->right;
            }else{
                tail->right=l2;
                l2->left=tail;
                tail=l2;
                l2=l2->right;
            }
        }
    }
    if(ans==NULL){
        if(l1){
        	ans=tail=l1;

        }else if(l2){
        	ans=tail=l2;
        }
    }else{
    	if(l1){
    		tail->right=l1;
    		l1->left=tail;
    	}else if(l2){
    		tail->right=l2;
    		l2->left=tail;
    	}
    }
    return ans;
}



//here we have to sort the double linkedlist 
//left and right as prev and next
node* sortdll(node*root){
	if(!root or !root->right){
		return root;
	}
	node*mid_node=midNode(root);
	node*nhead=mid_node->right;
	mid_node->right=nullptr;
	nhead->left=nullptr;
	return mergeTwoLists(sortdll(root),sortdll(nhead));
}



//here we get sorted doubly linkedlist
//and we have to make it as bst
//balanced bst
void convert_bst_inorder(node*root){
	if(!root){
		return;
	}
	convert_bst_inorder(root->left);
	cout<<root->data<<" ";
	convert_bst_inorder(root->right);
	return;
}


node* convert_bst(node*root){
	if(!root or (!root->left and !root->right)){
		return root;
	}
	node*mid_node=midNode(root);
	node*left=mid_node->left;
	node*right=mid_node->right;
	if(left){
		left->right=nullptr;
	}
	if(right){
		right->left=nullptr;
	}
	mid_node->left=mid_node->right=nullptr;
	if(mid_node!=root){
		mid_node->left=convert_bst(root);
	}
	mid_node->right=convert_bst(right);
	return mid_node;
}


/*
node* convert_bst(node* head) {
        if (head == nullptr || head->right == nullptr)
            return head;

        node* root = midNode(head);
        node* leftDLLHead = head;
        node* rightDLLHead = root->right;

        root->left->right = root->right->left = nullptr;
        root->left = root->right = nullptr;

        root->left = convert_bst(leftDLLHead);
        root->right = convert_bst(rightDLLHead);

        return root;
    }
*/


void SortedDLLToBST(node*root){
	root=bToDLL(root);
	root=sortdll(root);
	root=convert_bst(root);
	convert_bst_inorder(root);
}


class Pairing{
public:
	node*root;
	int start;
	int end;
	int mid;
	Pairing(node*root,int start,int mid,int end){
		this->mid=mid;
		this->root=root;
		this->start=start;
		this->end=end;
	}
};

node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n){

	queue<Pairing*> q;
	int i=0;
	node*root=new node(levelOrder[i]);
	int mid=-1;
	for(int j=iStart;j<=iEnd;j++){
		if(levelOrder[i]==inorder[j]){
			mid=j;
			 break;
		}
	}
	i++;
	q.push(new Pairing(root,iStart,mid,iEnd));
	while(!q.empty()){
		Pairing *p=q.front();
		q.pop();
		if(i==n){
			continue;
		}
		if(p->mid==-1){
			continue;
		}
		//left
		if(p->start<=p->mid-1){
			node*temp=new node(levelOrder[i]);
			p->root->left=temp;
			int mid=-1;
			for(int j=p->start;j<=p->mid-1;j++){
				if(levelOrder[i]==inorder[j]){
					mid=j;
					break;
				}
			}
			q.push(new Pairing(temp,p->start,mid,p->mid-1));
			i++;
		}
		if(i==n){
			continue;
		}
		//right
		if(p->mid+1<=p->end){
			node*temp=new node(levelOrder[i]);
			p->root->right=temp;
			int mid=-1;
			for(int j=p->mid+1;j<=p->end;j++){
				if(levelOrder[i]==inorder[j]){
					mid=j;
					break;
				}
			}
			q.push(new Pairing(temp,p->mid+1,mid,p->end));
			i++;
		}
	}
	return root;
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
	int inorder[]={3 ,1 ,4, 0, 5, 2, 6 };
	int level[]={0 ,1 ,2 ,3 ,4 ,5 ,6 };
	node*root=buildTree(inorder,level,0,6,7);
	preorder(root);
	return 0;
}
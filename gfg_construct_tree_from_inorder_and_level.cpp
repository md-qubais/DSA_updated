
class Pairing{
public:
	Node*root;
	int start;
	int end;
	int mid;
	Pairing(Node*root,int start,int mid,int end){
		this->mid=mid;
		this->root=root;
		this->start=start;
		this->end=end;
	}
};

void preorder(Node*root){
    if(!root) return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n){
	queue<Pairing*> q;
	int i=0;
	Node*root=new Node(levelOrder[i]);
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
			Node*temp=new Node(levelOrder[i]);
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
			Node*temp=new Node(levelOrder[i]);
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

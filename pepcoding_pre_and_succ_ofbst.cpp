//actaully this is the code for the binary tree
//rather than bst
class Pair_tree{
public:
	TreeNode* pre=nullptr;
	TreeNode* succ=nullptr;
	Pair_tree(){

	}
};

void pre_and_succ(TreeNode*root,Pair_tree&ans,TreeNode*target,TreeNode*prev=nullptr){
	if(!root){
		return;
	}
	if(ans.pre and ans.succ){
		return;
	}
	pre_and_succ(root->left,ans,target,root);
	if(root==target and prev!=nullptr and !ans.pre){
		ans.pre=prev;
	}
	if(prev==target and root!=nullptr and !ans.succ){
		ans.succ=curr;
	}
	pre_and_succ(root->right,ans,target,root);
}


//here below is the code for bst from gfg

//i dont have to do anything i just have to go to that value
Node* left_rightMost(Node*root){
	if(!root->left){
		return nullptr;
	}
	root=root->left;
	while(root->right){
		root=root->right;
	}
	return root;
}
Node* right_leftMost(Node*root){
	if(!root->right){
		return nullptr;
	}
	root=root->right;
	while(root->left){
		root=root->right;
	}
	return root;
}
//this below is the code if that element is present in the
//tree
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
	pre=nullptr;
	suc=nullptr;
	while(root){
		if(root->key==key){
			Node*temp1=left_rightMost(root);
			Node*temp2=right_leftMost(root);
			if(temp1){
				pre=temp1;
			}
			if(temp2){
				suc=temp2;
			}
			if(pre){
				cout<<pre->key<<" ";
			}else{
				cout<<-1<<" ";
			}
			if(suc){
				cout<<suc->key<<endl;
			}else{
				cout<<-1<<endl;
			}
			return;
		}else if(root->key>key){
			suc=root;
			root=root->left;
		}else{
			pre=root;
			root=root->right;
		}
	}
}


Node* left_rightMost(Node*root){
	if(!root->left){
		return nullptr;
	}
	root=root->left;
	while(root->right){
		root=root->right;
	}
	return root;
}
Node* right_leftMost(Node*root){
	if(!root->right){
		return nullptr;
	}
	root=root->right;
	while(root->left){
		root=root->right;
	}
	return root;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
	pre=nullptr;
	suc=nullptr;
	while(root){
		if(root->key==key){
			Node*temp1=left_rightMost(root);
			Node*temp2=right_leftMost(root);
			if(temp1){
				pre=temp1;
			}
			if(temp2){
				suc=temp2;
			}
			if(pre){
				cout<<pre->key<<" ";
			}else{
				cout<<-1<<" ";
			}
			if(suc){
				cout<<suc->key<<endl;
			}else{
				cout<<-1<<endl;
			}
			return;
		}else if(root->key>key){
			suc=root;
			root=root->left;
		}else{
			pre=root;
			root=root->right;
		}
	}
			if(pre){
				cout<<pre->key<<" ";
			}else{
				cout<<-1<<" ";
			}
			if(suc){
				cout<<suc->key<<endl;
			}else{
				cout<<-1<<endl;
			}
	
}





//below is for both if the key is present or not
Node* left_rightMost(Node*root){
	if(!root->left){
		return nullptr;
	}
	root=root->left;
	while(root->right){
		root=root->right;
	}
	return root;
}
Node* right_leftMost(Node*root){
	if(!root->right){
		return nullptr;
	}
	root=root->right;
	while(root->left){
		root=root->right;
	}
	return root;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
	pre=nullptr;
	suc=nullptr;
	while(root){
		if(root->key==key){
			Node*temp1=left_rightMost(root);
			Node*temp2=right_leftMost(root);
			if(temp1){
				pre=temp1;
			}
			if(temp2){
				suc=temp2;
			}
			return;
		}else if(root->key>key){
			suc=root;
			root=root->left;
		}else{
			pre=root;
			root=root->right;
		}
	}
	
}




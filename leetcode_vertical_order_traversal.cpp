//time complexity nlogn heap or priority queue takes on average
//and space complexity is 2^h ==> 2^logn which we consider
//to care O(n)

class Node{
public:
    TreeNode*root;
    int level;
    Node(TreeNode*root,int level){
        this->root=root;
        this->level=level;
    }
};

class compare{
public:
    bool operator()(Node* p1,Node* p2){
        if(p1->level==p2->level){
            return p1->root->val>p2->root->val;
        }
        return p1->level>p2->level;
    }
};

class Solution {
public:
    void widthOfShadow(TreeNode*root,int level,vector<int>&MinMax){
        if(!root){
            return ;
        }
        MinMax[0]=min(MinMax[0],level);
        MinMax[1]=max(MinMax[1],level);
        widthOfShadow(root->left,level-1,MinMax);
        widthOfShadow(root->right,level+1,MinMax);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root){
        //pair.first is the level of the node
        //pair.second is the node value of the node
        priority_queue<Node*,vector<Node*>,compare> parent,child;
        vector<int> MinMax(2);
        MinMax[0]=INT_MAX;
        MinMax[1]=INT_MIN;
        widthOfShadow(root,0,MinMax);
        vector<vector<int>> ans(MinMax[1]-MinMax[0]+1);
        parent.push(new Node(root,-MinMax[0]));
        while(!parent.empty()){
            int size=parent.size();
            while(size--){
                Node*temp=parent.top();
                parent.pop();
                ans[temp->level].push_back(temp->root->val);
                if(temp->root->left){
                    child.push(new Node(temp->root->left,temp->level-1));
                }
                if(temp->root->right){
                    child.push(new Node(temp->root->right,temp->level+1));
                }
            }
            swap(parent,child);
        }
        return ans;
    }

};
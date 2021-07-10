class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<TreeNode*,bool> mark;
    bool is_same(TreeNode*root1,TreeNode*root2){
        if(!root1 and !root2){
            return true;
        }
        if(!root1 or !root2){
            return false;
        }
        if(root1->val!=root2->val){
            return false;
        }
        if(is_same(root1->left,root2->left) and is_same(root1->right,root2->right)){
            return true;
        }
        return false;
    }

    bool find(TreeNode*root1,TreeNode*root2){
        if(mark[root2]){
            return false;
        }
        if(!root2){
            return false;
        }
        if(root1==root2){
            return false;
        }
        if(root1->val==root2->val){
            return is_same(root1,root2);
        }
        if(find(root1,root2->left)){
            return true;
        }
        if(find(root1,root2->right)){
            return true;
        }
        return false;
    }
    
    void findDuplicateSubtrees(TreeNode* root,TreeNode*start){
        if(!root){
            return;
        }
        if(find(root,start)){
            ans.push_back(root);
        }
        if(start!=root){
            mark[root]=true;
        }
        findDuplicateSubtrees(root->left,start);
        findDuplicateSubtrees(root->right,start);
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root){
        findDuplicateSubtrees(root,root);
        return ans;
    }

};
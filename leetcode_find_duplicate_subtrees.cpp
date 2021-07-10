class Solution{
public:
    unordered_map<string,TreeNode*> mapping;
    unordered_map<string,TreeNode*> s;
    string find_duplicate(TreeNode*root){
        if(!root){
            return "";
        }
        string left=find_duplicate(root->left);
        string right=find_duplicate(root->right);
        string temp="";
        if(left.size()==0){
            temp+="left ";
        }else{
            temp+=left+" ";
        }
        temp+=to_string(root->val)+" ";
        if(right.size()==0){
            temp+="right ";
        }else{
            temp+=right+" ";
        }
        if(mapping[temp]){
            s[temp]=root;
        }else{
            mapping[temp]=root;
        }
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        find_duplicate(root);
        vector<TreeNode*>ans;
        for(auto&it:s){
            ans.push_back(it.second);
        }
        return ans;
    }
};
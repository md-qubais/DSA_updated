class Solution{
public:
    string smallestFromLeaf(TreeNode* root,string path=""){
        if(!root){
            return "";
        }
        char ch='a';
        string to_append="";
        to_append+=(char)ch+(root->val);
        if(!root->left and !root->right){
            return to_append+path;
        }
        string left=smallestFromLeaf(root->left,to_append+path);
        string right=smallestFromLeaf(root->right,to_append+path);
        if(left.length()>0 and right.length()==0){
            return left;
        }
        if(right.length()>0 and left.length()==0){
            return right;
        }
        return left<right?left:right;
    } 
};
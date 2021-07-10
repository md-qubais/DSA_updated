class Solution{
public:
int ans=0;
void catch_fire(Node*root,int time,Node*block){
    if(!root){
        return;
    }
    if(root==block){
        return;
    }
    ans=max(ans,time);
    catch_fire(root->left,time+1,block);
    catch_fire(root->right,time+1,block);
}

int burning_tree(Node*root,int target){
    if(!root) return -1;
    if(root->data==target){
        catch_fire(root,0,nullptr);
        return 1;
    }
    int left=burning_tree(root->left,target);
    if(left!=-1){
        catch_fire(root,left,root->left);
        return left+1;
    }
    int right=burning_tree(root->right,target);
    if(right!=-1){
        catch_fire(root,right,root->right);
        return right+1;
    }
    return -1;
}

    int minTime(Node* root, int target){
        burning_tree(root,target);
        return ans;
    }
};

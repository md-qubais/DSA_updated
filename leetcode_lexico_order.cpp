class Solution {
public:
    void order(int i,int n,vector<int>&ans){
        if(i>n){
            return;
        }
        ans.push_back(i);
        for(int j=0;j<=9;j++){
            order(i*10+j,n,ans);
        }
    }
    
    vector<int> lexicalOrder(int n){
        vector<int> ans;
        for(int i=1;i<=9;i++){
            if(i>n){
                return ans;
            }
            order(i,n,ans);
        }
        return ans;
    }
};
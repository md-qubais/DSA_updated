class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2){
        int num1=0;
        int num2=0;
        int mul=0;
        for(int i=arr1.size()-1;i>=0;i--){
            if(arr1[i]!=0) num1+=pow(-2,mul);
            mul++;
        }
        mul=0;
        for(int i=arr2.size()-1;i>=0;i--){
            if(arr2[i]!=0) num2+=pow(-2,mul);
            mul++;
        }
        vector<int> ans;
        int n=num1+num2;
        while(n>1){
            ans.push_back(n%2);
            n=n/2;
        }
        if(n==1){
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0){
            ans.push_back(0);
        }
        return ans;
    }
};
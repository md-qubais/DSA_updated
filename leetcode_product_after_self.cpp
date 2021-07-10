class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        vector<int> ans(nums.size());
        ans[0]=nums[0];
        int prod=ans[0];
        ans[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            ans[i]=prod;
            prod*=nums[i];
        }
        prod=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(i==0){
                ans[i]=prod;
                continue;
            }
            ans[i]*=prod;
            prod*=nums[i];
        }
        return ans;
    }
};
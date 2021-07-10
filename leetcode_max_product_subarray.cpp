class Solution{
public:
    int maxProduct(vector<int>& nums){
        int ans=INT_MIN;
        int curr=nums[0];
        for(int i=1;i<nums.size();i++){
            if(curr*nums[i]<=0){
                ans=max(ans,curr);
                curr=nums[i];
            }else{
                curr*=nums[i];
            }
        }
        return max(ans,curr);
    }
};
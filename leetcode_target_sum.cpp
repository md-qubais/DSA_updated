class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target,int sum=0,int i=0){
        if(i==nums.size()){
            if(sum==target){
                return 1;
            }
            return 0;
        }
        int op1=findTargetSumWays(nums,target,sum+(nums[i]),i+1);
        int op2=findTargetSumWays(nums,target,sum+(-nums[i]),i+1);
        return op1+op2;
    }
};
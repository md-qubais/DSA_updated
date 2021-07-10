class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k){
        vector<int> prod(nums.size());
        prod[0]=nums[0];
        int count=0;
        for(int i=1;i<nums.size();i++){
            prod[i]=nums[i]*prod[i-1];
        }
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(i==0){
                    if(prod[j]<k){
                        count++;
                    }
                }else{
                    if((prod[j]/prod[i-1])<k){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
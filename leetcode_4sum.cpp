class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4){
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1 and nums[j]==nums[j-1]){
                    continue;
                }
                int s=j+1;
                int e=nums.size()-1;
                while(s<e){
                    if(s>j+1 and nums[s]==nums[s-1]){
                        s++;
                        continue;
                    }
                    if(e<nums.size()-1 and nums[e]==nums[e+1]){
                        e--;
                        continue;
                    }
                    int num=nums[i]+nums[j]+nums[s]+nums[e];
                    if(num==target){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[s]);
                        temp.push_back(nums[e]);
                        ans.push_back(temp);
                        s++;
                        e--;
                    }else if(num<target){
                        s++;
                    }else{
                        e--;
                    }
                }
            }
        }
        return ans;
    }
};
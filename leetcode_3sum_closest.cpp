class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(),nums.end());
        bool b=false;
        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            int s=i+1;
            int e=nums.size()-1;
            while(s<e){
                int sum=nums[i]+nums[s]+nums[e];
                if(!b){
                    b=true;
                    ans=sum;
                }else{
                    if(abs(target-ans)>abs(target-sum)){
                        ans=sum;
                    }
                }
                //we are moving forward to target
                //what if we find the sum is equals to target
                if(sum<target){
                    s++;
                }else{
                    e--;
                }
            }
        }
        return ans;
    }
};
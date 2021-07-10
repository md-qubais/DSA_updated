class Solution{
public:
    int tupleSameProduct(vector<int>& nums){
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int product=nums[i]*nums[j];
                ans+=8*m[product];
                m[product]++;
            }
        }
        return ans;
    }
};
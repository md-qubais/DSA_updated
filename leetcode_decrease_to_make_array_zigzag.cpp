class Solution{
public:
    int movesToMakeZigzag(vector<int>& nums){
        if(nums.size()==1 or nums.size()==0){
            return 0;
        }
        vector<int> odd=nums;
        int ans=INT_MAX;
        int curr=0;
        for(int i=0;i<odd.size();i++){
            if(i%2!=0){
                if(i==odd.size()-1){
                    if(odd[i]>=odd[i-1]){
                        while(odd[i]>=odd[i-1]){
                            odd[i]--;
                            curr++;
                        }
                    }
                }else{
                    if(odd[i-1]<=odd[i] or odd[i]>=odd[i+1]){
                        int num=min(odd[i],min(odd[i-1],odd[i+1]));
                        while(odd[i]>=num){
                            curr++;
                            odd[i]--;
                        }
                    }
                }
            }
        }
        vector<int> even=nums;
        ans=min(ans,curr);
        curr=0;
        for(int i=0;i<even.size();i++){
            if(i%2==0){
                if(i==0){
                    if(even[i]>=even[i+1]){
                        while(even[i]>=even[i+1]){
                            even[i]--;
                            curr++;
                        }
                    }
                }else if(i==even.size()-1){
                    if(even[i]>=even[i-1]){
                        while(even[i]>=even[i-1]){
                            curr++;
                            even[i]--;
                        }
                    }
                }
                else{
                    if(even[i-1]<=even[i] or even[i]>=even[i+1]){
                        int num=min(even[i],min(even[i-1],even[i+1]));
                        while(even[i]>=num){
                            even[i]--;
                            curr++;
                        }
                    }
                }
            }
        }
        ans=min(ans,curr);
        return ans;
    }
};
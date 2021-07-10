class Solution{
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold){
        int sum=0;
        int i=0;
        int ans=0;
        while(i<k){
            sum+=arr[i++];
        }
        if((sum/k)>=threshold){
            ans++;
        }
        for(int j=0;i<arr.size();i++,j++){
            sum-=arr[j];
            sum+=arr[i];
            if((sum/k)>=threshold){
                ans++;
            }
        }
        return ans;
    }
};
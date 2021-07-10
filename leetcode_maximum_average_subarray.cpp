class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k){
        double ans=INT_MIN;
        int i=0;
        int sum=0;
        while(i<k){
            sum+=arr[i++];
        }
        ans=max(ans,(double)sum/(double)(k));
        for(int j=0;i<arr.size();j++,i++){
            sum-=arr[j];
            sum+=arr[i];
            ans=max(ans,(double)sum/(double)(k));    
        }
        return ans;
    }
};
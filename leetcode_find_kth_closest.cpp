class Solution{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x){
        vector<int> ans;
        if(x<arr[0]){
            ans.resize(k);
            for(int i=0;i<k;i++){
                ans[i]=arr[i];
            }
            return ans;
        }
        if(x>arr[arr.size()-1]){
            ans.resize(k);
            int j=arr.size()-1;
            int i=0;
            while(i<k){
                ans[i++]=arr[j--];
            }
            return ans;
        }
        int a=-1;
        int b=arr.size();
        int i=0;
        int j=arr.size()-1;
        while(i<=j){
            if(arr[i]<x){
                a=i;
            }
            if(arr[j]>=x){
                b=j;
            }
            i++;
            j--;
        }
        int count=0;
        while(a>=0 and b<=arr.size()-1){
            if((abs(arr[a]-arr[b])<abs(arr[b]-x)) or ( abs(arr[a]-x)==abs(arr[b]-x) and arr[a]<arr[b] )){
                ans.push_back(arr[a--]);
            }else{
                ans.push_back(arr[b++]);
            }
            count++;
            if(count==k){
                sort(ans.begin(),ans.end());
                return ans;
            }
        }
        if(count==k){
            sort(ans.begin(),ans.end());
            return ans;
        }
        while(a>=0){
            ans.push_back(arr[a--]);
            if(count==k){
                sort(ans.begin(),ans.end());
                return ans;
            }
        }
        while(b<=arr.size()-1){
            ans.push_back(arr[b++]);
            if(count==k){
                sort(ans.begin(),ans.end());
                return ans;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
class Pair{
public:
    int val;
    int x;
    Pair(int val,int x){
        this->val=val;
        this->x=x;
    }
};
class compare{
public:
    bool operator()(Pair a,Pair b){
        if((abs(a.val-a.x)<abs(b.val-b.x)) or ( abs(a.val-a.x)==abs(b.val-b.x) and a.val<b.val) ){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x){ 
        priority_queue<Pair,vector<Pair>,compare> pq;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            pq.push(Pair(arr[i],x));
            while(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().val);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks){
        vector<pair<int,pair<int,int>>> arr;
        for(int i=0;i<tasks.size();i++){
            //index starting_time and Processing_time
            arr.push_back({i,{arr[i][0],arr[i][1]}});
        }
    }
};
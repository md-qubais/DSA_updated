class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right){
        vector<pair<int,int>> arr;
        for(int i=0;i<ranges.size();i++){
            arr.push_back({ranges[i][0],ranges[i][1]});
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i].second>=left and arr[i].first<=left){
                left=arr[i].second+1;
            }
        }
        if(left<=right){
            return false;
        }
        return true;
    }
};
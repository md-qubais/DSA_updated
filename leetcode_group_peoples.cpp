class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes){
        unordered_map<int,vector<int>> mapping;
        for(int i=0;i<groupSizes.size();i++){
            mapping[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto&it:mapping){
            int size=it.first;
            int curr_size=0;
            vector<int> temp;
            for(auto&i:it.second){
                temp.push_back(i);
                curr_size++;
                if(curr_size==size){
                    ans.push_back(temp);
                    curr_size=0;
                    temp.clear();
                }
            }
        }
        return ans;
    }
};



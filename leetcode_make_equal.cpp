class Solution {
public:
    bool makeEqual(vector<string>& words){
        unordered_map<char,int> count;
        int n=words.size();
        for(auto&it:words){
            for(auto&i:it){
                count[i]++;
            }
        }
        for(auto&it:count){
            if(it.second%n!=0){
                return false;
            }
        }
        return true;
    } 
};
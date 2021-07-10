class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s){
        unordered_map<string,int> count;
        vector<string> ans;
        if(s.length()<10){
            return ans;
        }
        int i=0;
        string temp="";
        while(i<10){
            temp+=s[i++];
        }
        count[temp]++;
        for(;i<s.length();i++){
            temp=temp.substr(1);
            temp+=s[i];
            count[temp]++;
        }
        for(auto&it:count){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }



        return ans;
    }
};
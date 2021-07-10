class Solution {
public:
    bool is_subsequences(string s1,string s2){
        int left=0;
        int right=0;
        while(left<s1.length() and right<s2.length()){
            if(s1[left]==s2[right]){
                left++;
                right++;
                continue;
            }
            right++;
        }
        if(left<s1.length()){
            return false;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int> mapping;
        for(auto&it:words){
            mapping[it]++;
        }
        int ans=0;
        for(auto&it:mapping){
            if(is_subsequences(it.first,s)){
                ans+=it.second;
            }
        }
        return ans;
    }
};
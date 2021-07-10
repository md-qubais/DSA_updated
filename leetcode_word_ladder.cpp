class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        queue<pair<string,int>> q;
        unordered_map<string,bool> mapping;
        for(auto&it:wordList){
            mapping[it]=true;
        }
        q.push({beginWord,1});
        while(!q.empty()){
            pair<string,int> temp=q.front();
            q.pop();
            if(temp.first==endWord){
                return temp.second;
            }
            for(int i=0;i<temp.first.length();i++){
                char change=temp.first[i];
                for(int j=0;j<=25;j++){
                    char ch='a'+j;
                    if(temp.first[i]==ch){
                        continue;
                    }
                    temp.first[i]=ch;
                    if(mapping[temp.first]){
                        mapping[temp.first]=false;
                        string str=temp.first;
                        q.push({str,temp.second+1});
                    }
                }
                temp.first[i]=change;
            }
        }
        return 0;
    }
};
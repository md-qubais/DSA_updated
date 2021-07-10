class Solution {
public:

    deque<vector<string>> ladderLength(string beginWord, string endWord, vector<string>& wordList){
        deque<vector<string>> ans;
        queue<pair<string,pair<int,vector<string>>>> q;
        unordered_map<string,bool> mapping;
        for(auto&it:wordList){
            mapping[it]=true;
        }
        vector<string> temp;
        temp.push_back(beginWord);
        q.push({beginWord,{1,temp}});
        while(!q.empty()){
            pair<string,pair<int,vector<string>>> temp=q.front();
            q.pop();
            mapping[temp.first]=false;
            if(temp.first==endWord){
                if(ans.empty()){
                    ans.push_back(temp.second.second);
                }
                else{
                    int size=temp.second.second.size();
                    while(!ans.empty() and ans.back().size()>size){
                        ans.pop_back();
                    }
                    if(ans.empty()){
                        ans.push_back(temp.second.second);
                    }else if(ans.back().size()==size){
                        ans.push_back(temp.second.second);
                    }
                }
                continue;
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
                        string str=temp.first;
                        vector<string> arr=temp.second.second;
                        arr.push_back(str);
                        q.push({str,{temp.second.first+1,arr}});
                    }
                }
                temp.first[i]=change;
            }
        }
        return ans;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
        deque<vector<string>> arr=ladderLength(beginWord,endWord,wordList);
        vector<vector<string>> ans;
        for(auto&it:arr){
            ans.push_back(it);
        }
        return ans;
    }
};
class Solution {
public:
    //A C G T
    int minMutation(string start, string end, vector<string>& bank){
        queue<pair<string,int>> q;
        unordered_map<string,bool> mapping;
        for(auto&it:bank){
            mapping[it]=true;
        }
        char arr[]={'A','C','G','T'};
        q.push({start,0});
        while(!q.empty()){
            pair<string,int> temp=q.front();
            q.pop();
            mapping[temp.first]=false;
            if(temp.first==end){
                return temp.second;
            }
            string str=temp.first;
            for(int i=0;i<str.length();i++){
                char change=str[i];
                for(int j=0;j<4;j++){
                    if(str[i]==arr[j]){
                        continue;
                    }
                    str[i]=arr[j];
                    if(mapping[str]){
                        q.push({str,temp.second+1});
                    }
                }
                str[i]=change;
            }
        }
        return -1;
    }
};
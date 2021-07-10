class Solution{
public:
    int openLock(vector<string>& deadends, string target){
        queue<pair<string,int>> q;
        unordered_map<string,bool> stop;
        for(auto&it:deadends){
            stop[it]=true;
        }
        unordered_map<string,bool> visited;
        q.push(make_pair("0000",0));
        while(!q.empty()){
            pair<string,int> temp=q.front();
            q.pop();
            if(temp.first==target){
                return temp.second;
            }
            if(visited[temp.first] or stop[temp.first]){
                continue;
            }
            visited[temp.first]=true;
            string s=temp.first;
            for(int i=0;i<s.length();i++){
                char replace=s[i];
                int num=s[i]-'0';
                num=(num+1)%10;
                s[i]=num+'0';
                if(!visited[s] and !stop[s]){
                    q.push(make_pair(s,temp.second+1));
                }
                s[i]=replace;
            }
            for(int i=0;i<s.length();i++){
                char replace=s[i];
                int num=s[i]-'0';
                num--;
                if(num<0){
                    num+=10;
                }   
                s[i]=num+'0';
                if(!visited[s] and !stop[s]){
                    q.push(make_pair(s,temp.second+1));
                }
                s[i]=replace;
            }
        }
        return -1;
    }
};
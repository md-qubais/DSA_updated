class compare{
public:
    bool operator()(pair<int,int> p1,pair<int,int> p2){
        if(p1.second==p2.second){
            return p1.first>p2.first;
        }
        return p1.second>p2.second;
    }
};
class Solution{
public:
    int snakesAndLadders(vector<vector<int>>& board){
        map<int,int> arr;
        int count=0;
        int num=1;
        for(int i=board.size()-1;i>=0;i--){
            if(count==0){
                for(int j=0;j<board[i].size();j++){
                    if(board[i][j]==-1){
                        arr[num]=num;
                    }else arr[num]=board[i][j];
                    num++;
                }
                count=1;
            }else{
                for(int j=board[i].size()-1;j>=0;j--){
                    if(board[i][j]==-1){
                        arr[num]=num;
                    }else arr[num]=board[i][j];
                    num++;
                }
                count=0;
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> q;
        unordered_map<int,bool> visited;
        int n=board.size()*board.size();
        q.push({1,0});
        while(!q.empty()){
            pair<int,int> temp=q.top();
            q.pop();
            while(temp.first!=arr[temp.first]){
                temp.first=arr[temp.first];
            }
            if(visited[temp.first]){
                continue;
            }
            cout<<temp.first<<" "<<temp.second<<endl;
            if(temp.first==(n*n)){
                cout<<temp.second<<endl;
            }
            visited[temp.first]=true;
            for(int i=1;i<=6;i++){
                if(!visited[temp.first+i] and temp.first+i<=(n*n)){
                    q.push({temp.first+i,temp.second+1});
                }
            }
        }
        return -1;
    }
};
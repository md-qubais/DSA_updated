class Pair{
public:
    int time;
    int row;
    int col;
    Pair(int time,int row,int col){
        this->time  = time;
        this->row = row;
        this->col = col;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        bool visited[1000][1000]={false};
        queue<Pair> q;
        int count=0;
        int rotten_count=0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j  < grid[i].size() ; j++){
                if(grid[i][j]==2){
                    rotten_count++;
                    q.push(Pair(0,i,j));
                }
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        if(rotten_count==0 and count==0){
            return rotten_count;
        }
        int ans = -1;
        while(q.size()>0){
            Pair p = q.front();
            q.pop();
            int row = p.row;
            int col = p.col;
            if(visited[row][col]){
                continue;
            }
            
            visited[row][col] = true;
            int time = p.time;
            ans = max(ans,time);
            if(row - 1 >= 0 and  grid[row-1][col]!=2 and grid[row-1][col]!=0){
                grid[row-1][col]=2;
                q.push(Pair(time+1,row-1,col)),count--;
            }
            if(col - 1 >= 0 and  grid[row][col-1]!=2 and grid[row][col-1]!=0){
                grid[row][col-1]=2;
                q.push(Pair(time+1,row,col-1)),count--;
            }
            if(col + 1 < grid[row].size() and  grid[row][col+1]!=2 and grid[row][col+1]!=0){
                grid[row][col+1]=2;
                q.push(Pair(time+1,row,col+1)),count--;
            }
            if(row + 1 < grid.size() and  grid[row+1][col]!=2 and grid[row+1][col]!=0){
                grid[row+1][col]=2;
                q.push(Pair(time+1,row+1,col)),count--;
            }
        }
        if(count>0){
            return -1;
        }
        return ans;
    }
};
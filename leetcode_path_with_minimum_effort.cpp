class Pair{
public:
    int rows;
    int cols;
    int diff;
    Pair(){
    }
    Pair(int rows,int cols,int diff){
        this->rows=rows;
        this->cols=cols;
        this->diff=diff;
    }
};
class compare{
public:
    bool operator()(Pair p1,Pair p2){
        return p1.diff>p2.diff;
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<Pair,vector<Pair>,compare> pq;
        if(heights.size()==1 and heights[0].size()==1){
            return 0;
        }
        int ans=0;
        if(heights[0].size()>1) pq.push(Pair(0,1,abs(heights[0][0]-heights[0][1])));
        if(heights.size()>1) pq.push(Pair(1,0,abs(heights[0][0]-heights[1][0])));
        bool visited[1000][1000]={false};
        while(!pq.empty()){
            Pair temp=pq.top();
            pq.pop();
            if(visited[temp.rows][temp.cols]){
                continue;
            }
            ans=max(ans,temp.diff);
            if(temp.rows==heights.size()-1 and temp.cols==heights[0].size()-1){
                return ans;
            }
            visited[temp.rows][temp.cols]=true;
            int row_dir[]={1,-1,0,0};
            int col_dir[]={0,0,1,-1};
            for(int k=0;k<4;k++){
                int row=temp.rows+row_dir[k];
                int col=temp.cols+col_dir[k];
                if(row<0 or col<0 or row>=heights.size() or col>=heights[0].size() or visited[row][col]){
                    continue;
                }
                pq.push(Pair(row,col,abs(heights[temp.rows][temp.cols]-heights[row][col])));
            }
        }
        return ans;
    }
};
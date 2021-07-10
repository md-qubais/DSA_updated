//lintcode.com/problem/number-of-distinct-islands/description
//https://leetcode.com/problems/number-of-distinct-islands/

class Solution{
public:
    string get_directions(vector<vector<int>>&grid,int i,int j,bool visited[1000][1000],string path=""){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[i].size() or visited[i][j] or grid[i][j]==0){
            return "";
        }
        visited[i][j]=true;
        string ans="";
        ans+=get_directions(grid,i+1,j,visited,path+" down ");
        ans+=get_directions(grid,i,j+1,visited,path+" right ");
        ans+=get_directions(grid,i-1,j,visited,path+" up ");
        ans+=get_directions(grid,i,j-1,visited,path+" left ");
        return ans+path;
    }
    int numberofDistinctIslands(vector<vector<int>> &grid){
        set<string> s;
        bool visited[1000][1000]={false};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(!visited[i][j] and grid[i][j]){
                    string temp=get_directions(grid,i,j,visited);
                    s.insert(temp);
                }
            }
        }
        return s.size();
    }
};


//this above solution gets accepted
//on lintcode and you must submit it on leetcode






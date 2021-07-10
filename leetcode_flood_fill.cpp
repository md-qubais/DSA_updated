int rows[]={1,-1,0,0};
int cols[]={0,0,1,-1};
class Solution {
public:
    bool visited[1000][1000];
    void perform_floodfill(vector<vector<int>>& image, int sr, int sc, int newColor,int target){
        if(sr<0 or sc<0 or sr>=image.size() or sc>=image[sr].size()){
            return;
        }
        if(visited[sr][sc]){
            return ;
        }
        if(image[sr][sc]!=target){
            return;
        }
        image[sr][sc]=newColor;
        visited[sr][sc]=true;
        for(int k=0;k<4;k++){
            perform_floodfill(image,sr+rows[k],sc+cols[k],newColor,target);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        int num=image[sr][sc];
        perform_floodfill(image,sr,sc,newColor,num);
        return image;
    }
};
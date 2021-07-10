class Solution {
public:
    
    void get_perfect_square(int n,vector<int>&arr){
        for(int i=1;i*i<=n;i++){
            arr.push_back(i*i);
        }

    }
    
    int numSquares(int n){
        vector<int> perfect_square;
        get_perfect_square(n,perfect_square);
        //first indicates the sum
        //and second indicates the steps for performing that sum
        queue<pair<int,int>> q;
        for(auto&it:perfect_square){
            q.push({it,1});
        }
        while(!q.empty()){
            pair<int,int> temp=q.front();
            q.pop();
            if(temp.first==n){
                return temp.second;
            }
            for(auto&it:perfect_square){
                int num=it+temp.first;
                if(num>n){
                    continue;
                }
                q.push({num,temp.second+1});
            }
        }   
        return -1;
    }

};
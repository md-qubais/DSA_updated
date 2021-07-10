class Solution {
public:
    int totalFruit(vector<int>& tree){
        int distinct=0;
        unordered_map<int,int> count;
        int i=0;
        int j=0;
        int ans=0;
        while(i<tree.size() and j<tree.size()){
            count[tree[j]]++;
            if(count[tree[j]]==1){
                distinct++;
            }
            if(distinct>2){
                ans=max(ans,j-i);
                while(distinct>2){
                    count[tree[i]]--;
                    if(count[tree[i]]==0){
                        distinct--;
                    }
                    i++;
                }
            }
            j++;
        }
        if(distinct<=2){
            ans=max(ans,j-i);
        }
        return ans;
    }
};
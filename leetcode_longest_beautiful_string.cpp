class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int i=0;
        int j=1;
        int count=1;
        int ans=0;
        char ch=word[0];
        while(j<word.length()){
            if(ch==word[j]){
                j++;
                continue;
            }
            if(ch<word[j]){
                ch=word[j];
                j++;
                count++;
            }else{
                if(count==5){
                    ans=max(ans,j-i);
                }
                i=j;
                j++;
                ch=word[i];
                count=1;
            }
        }
        if(count==5){
            ans=max(ans,j-i);
        }
        return ans;
    }
};
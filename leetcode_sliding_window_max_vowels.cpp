class Solution {
public:
    
    bool is_vowel(char ch){
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u'){
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k){
        int i=0;
        int ans=0;
        int count=0;
        while(i<k){
            if(is_vowel(s[i])){
                count++;
            }
            i++;
        }
        ans=max(ans,count);
        for(int j=0;i<s.length();j++,i++){
            if(is_vowel(s[j])){
                count--;
            }
            if(is_vowel(s[i])){
                count++;
            }
            ans=max(ans,count);
        }
        return max(ans,count);
    }
    
};
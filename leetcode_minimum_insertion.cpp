class Solution {
public:
    int minInsertions(string s){
        stack<char> st;
        int ans=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
                st.push(s[i]);
                continue;
            }
            if(s[i]==')'){
                if(!st.empty() and st.top()==')' and count>0){
                    while(!st.empty() and st.top()!='('){
                        st.pop();
                    }
                    st.pop();
                    count--;
                }else{
                    st.push(s[i]);
                }
            }
        }
        int cs=0;
        while(!st.empty()){
            if(st.top()==')'){
                cs++;
            }
            st.pop();
        }
        //opening is greater than closing
        //add closing to answer
        if(count>=cs){
            int num=count*2;
            num-=cs;
            ans+=num;
        }
        //closing is greater than opening
        //add closing to answer
        else{
            if(cs%2!=0){
                cs++;
            }
            int num=cs/2;
            num-=count;
            ans+=num;
        }
        return ans;
    }
};
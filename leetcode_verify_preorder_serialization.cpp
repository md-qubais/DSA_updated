class Solution{
public:
    bool isValidSerialization(string preorder){
        if(preorder.length()==1){
            if(preorder[0]=='#'){
                return true;
            }
            return false;
        }
        stack<pair<string,int>> s;
        preorder+=",";
        string temp="";
        bool b=false;
        for(int i=0;i<preorder.length();i++){
            if(preorder[i]!=',' and preorder[i]!='#') temp+=preorder[i];
            if(preorder[i]==','){
                if(b and s.empty() and temp.length()>0){
                    return false;
                }
                if(temp.length()>0){
                    b=true;
                    s.push({temp,0});
                }
                temp="";
                continue;
            }
            if(preorder[i]=='#'){
                if(s.empty()){
                    return false;
                }
                pair<string,int> p=s.top();
                s.pop();
                p.second++;
                s.push(p);
                while(!s.empty() and s.top().second==2){
                    s.pop();
                    if(!s.empty()){
                        pair<string,int> temp=s.top();
                        s.pop();
                        temp.second++;
                        s.push(temp);
                    }
                }
            }
        }

        if(s.empty()){
            return true;
        }
        return false;
    }
};
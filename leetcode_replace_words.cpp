class node{
public:
    char ch;
    bool isTerminal;
    string word;
    unordered_map<char,node*> child;
    node(char ch){
        this->ch=ch;
        isTerminal=false;
    }

};

class Trie{
public:
    node*root;  
    Trie(){
        root=new node('\0');
    }
    
    void insert(string str){
        node*temp=root;
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(temp->child[ch]!=0){
                temp=temp->child[ch];
            }else{
                temp->child[ch]=new node(ch);
                temp=temp->child[ch];
            }
        }
        temp->isTerminal=true;
        temp->word=str;
    }
    string replacement(string str){
        node*temp=root;
        int i=0;
        for(;i<str.length();i++){
            char ch=str[i];
            if(temp->child[ch]!=0){
                temp=temp->child[ch];
            }else{
                break;
            }
            if(temp->isTerminal){
                break;
            }
        }
        if(!temp->isTerminal){
            return str;
        }
        return temp->word;
    }
};
class Solution {
public:
    Trie t;
    string replaceWords(vector<string>& dictionary, string sentence){
        for(int i=0;i<dictionary.size();i++){
            t.insert(dictionary[i]);
        }
        string ans="";
        vector<string> tk;
        sentence+=" ";
        string temp="";
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==' '){
                if(temp.length()>0){
                    tk.push_back(temp);
                }
                temp="";
                continue;
            }
            temp+=sentence[i];
        }
        for(int i=0;i<tk.size();i++){
            ans+=t.replacement(tk[i]);
            ans+=" ";
        }
        while(ans[0]==' '){
            ans=ans.substr(1);
        }
        reverse(ans.begin(),ans.end());
        while(ans[0]==' '){
            ans=ans.substr(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
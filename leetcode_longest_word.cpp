class Node{
public:
    char ch;
    unordered_map<char,Node*> childs;
    bool is_terminal;
    Node(char ch){
        this->is_terminal=false;
        this->ch=ch;
    }
};
class Trie{
public:
    Node*root;
    Trie(){
        root=new Node('\0');
    }
    void insert(string word){
        Node*temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->childs[word[i]]){
                temp=temp->childs[word[i]];
            }else{
                Node*n=new Node(word[i]);
                temp->childs[word[i]]=n;
                temp=temp->childs[word[i]];
            }
        }
        temp->is_terminal=true;
    }
    bool is_prefix(string word){
        Node*temp=root;
        for(int i=0;i<word.length();i++){
            temp=temp->childs[word[i]];
            if(!temp->is_terminal){
                return false;
            }
        }
        if(!temp->is_terminal){
            return false;
        }
        return true;
    }
    string longest_word(vector<string>&words){
        string ans="";
        for(auto&it:words){
            if(is_prefix(it)){
                if(ans.length()<it.length()){
                    ans=it;
                }else if(ans.length()==it.length()){
                    ans=min(ans,it);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie*t=new Trie();
        for(auto&it:words){
            t->insert(it);
        }
        return t->longest_word(words);
    }
};
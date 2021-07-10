class listNode{
public:
    int app_state;
    int key;
    listNode*prev;
    listNode*next;
    listNode(int app_state,int key){
        this->app_state=app_state;
        this->key=key;
        prev=next=NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,listNode*> mapping;
    listNode*head,*tail;
    int capacity;
    int len=0;
    
    void make_recent(listNode*n){
        if(tail==n){

        }else if(!n->prev){
            head=head->next;
            head->prev=NULL;
            tail->next=n;
            n->prev=tail;
            tail=n;
            tail->next=NULL;
        }else{
            n->prev->next=n->next;
            n->next->prev=n->prev;
            tail->next=n;
            n->prev=tail;
            tail=n;
            tail->next=NULL;
        }
    }

    void add_node(int key,int value){
        if(!head){
            head=new listNode(value,key);
            tail=head;
            mapping[key]=tail;
        }else{
            listNode*n=new listNode(value,key);
            tail->next=n;
            n->prev=tail;
            tail=n;
            mapping[key]=tail;
        }
    }


    LRUCache(int capacity) {
        this->capacity=capacity;
        head=tail=NULL;
    }

    int get(int key){
        if(mapping.count(key)==0){
            return -1;
        }
        listNode*n=mapping[key];
        make_recent(n);
        return n->app_state;
    }
    
    void put(int key, int value){
        if(mapping.count(key)!=0){
            listNode*n=mapping[key];
            n->app_state=value;
            make_recent(n);
        }else{
            len++;
            add_node(key,value);
        }
        //if it is exceeding over the capacity
        if(len>capacity){
            mapping.erase(head->key);
            head=head->next;
            head->prev=NULL;
            len--;
        }
    }
};

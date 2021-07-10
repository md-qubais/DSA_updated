class listNode{
  public:
    int key;
    int val;
    listNode* prev;
    listNode* next;
    listNode(int key,int val){
        this->key = key;
        this->val = val;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int,listNode*> m;
    listNode* head;
    listNode* tail;
    int size;
    LRUCache(int capacity) {
       this->capacity = capacity;
       this->size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if(m[key]!=NULL){
            if(size>1 and m[key]!=tail)
            put(key,m[key]->val);
            return m[key]->val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        listNode* node;
        if(m[key]!=NULL){
            node = m[key];
            listNode* prev = node->prev;
            listNode* next = node->next;
            if(prev){
                prev->next = next;
            }
            if(next){
                next->prev = prev;
            }
            if(m[key]==head){
                head = next;
            }
            node->next = NULL;
            node->prev = NULL;
            node->val = value;
        }else{
            node = new listNode(key,value);
            m[key] = node;
            size++;
        }
        
        if(head == NULL){
            head = tail = node;
            node->prev = NULL;
            node->next = NULL;
        }else{
            tail->next = node;
            node->prev = tail;
            node->next = NULL;
            tail = node;
        }
        if(size>capacity){
            m[head->key] = NULL;
            listNode* newHead = head->next;
            head->next = NULL;
            newHead -> prev = NULL;
            head = newHead;
            size--;
        }
        
    }
}
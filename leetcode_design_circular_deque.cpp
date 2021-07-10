class Deque{
public:
    int val;
    Deque*prev;
    Deque*next;
    Deque(int val){
        this->val=val;
        prev=next=nullptr;
    }
};
class MyCircularDeque {
public:
    int curr=0;
    Deque*head,*tail;
    int k;
    MyCircularDeque(int k) {
        this->k=k;
        head=tail=nullptr;
    }
    
    bool insertFront(int value) {
        if(curr<k){
            curr++;
            Deque*temp=new Deque(value);
            if(head==nullptr){
                head=tail=temp;
                tail->next=head;
                head->prev=tail;
            }else{
                temp->next=head;
                head->prev=temp;
                head=temp;
                head->prev=tail;
                tail->next=head;
            }
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(curr<k){
            curr++;
            Deque*temp=new Deque(value);
            if(head==nullptr){
                head=tail=temp;
                tail->next=head;
                head->prev=tail;
            }else{
                tail->next=temp;
                temp->prev=tail;
                tail=temp;
                tail->next=head;
                head->prev=tail;
            }
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(curr>0){
          curr--;
            Deque*temp=head;
            if(head==tail){
                head=tail=nullptr;
            }
            else{
                head=head->next;
                tail->next=head;
                head->prev=tail;
            }
            delete temp;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(curr>0){
            curr--;
            Deque*temp=tail;
            if(head==tail){
                head=tail=nullptr;
            }else{
                tail=tail->prev;
                tail->next=head;
                head->prev=tail;
            }
            delete temp;
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(curr>0){
            return head->val;
        }
        return -1;
    }
    
    int getRear() {
        if(curr>0){
            return tail->val;
        }
        return -1;
    }
    
    bool isEmpty() {
        return curr==0;
    }
    
    bool isFull() {
        return curr==k;
    }
};

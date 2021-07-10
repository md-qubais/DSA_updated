#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *segregate012(ListNode *head){
    ListNode*zero=new ListNode(-1);
    ListNode*zp=zero;
    ListNode*one=new ListNode(-1);
    ListNode*op=one;
    ListNode*two=new ListNode(-1);
    ListNode*tp=two;
    ListNode*curr=head;
    while(curr){
        if(curr->val==0){
            zp->next=curr;
            zp=zp->next;
        }else if(curr->val==1){
            op->next=curr;
            op=op->next;
        }else{
            tp->next=curr;
            tp=tp->next;
        }
        curr=curr->next;
    }
    op->next=two->next;
    zp->next=one->next;
    tp->next=NULL;
    return zero->next;
}

void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *createList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int main()
{
    int n;
    cin >> n;
    ListNode *h1 = createList(n);
    h1 = segregate012(h1);
    printList(h1);

    return 0;
}
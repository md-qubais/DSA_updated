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

ListNode* get_last(ListNode*head){
    while(head->next){
        head=head->next;
    }
    return head;
}


ListNode *segregateOnLastIndex(ListNode *head){
    ListNode*last=get_last(head);
    ListNode*first=new ListNode(-1);
    ListNode*fp=first;
    ListNode*second=new ListNode(-1);
    ListNode*sp=second;
    while(head){
        if(head->val<=last->val){
            fp->next=head;
            fp=fp->next;
        }else{
            sp->next=head;
            sp=sp->next;
        }
        head=head->next;
    }
    fp->next=second->next;
    sp->next=NULL;
    return fp;
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
    h1 = segregateOnLastIndex(h1);
    printList(h1);

    return 0;
}
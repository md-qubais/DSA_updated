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

ListNode *segregateEvenOdd(ListNode *head){
    ListNode*odd=new ListNode(-1);
    ListNode*even=new ListNode(-1);
    ListNode*op=odd;
    ListNode*ep=even;
    ListNode*curr=head;
    while(curr){
        if(curr->val%2==0){
            ep->next=curr;
            ep=ep->next;
        }else{
            op->next=curr;
            op=op->next;
        }
        curr=curr->next;
    }
    op->next=NULL;
    ep->next=odd->next;
    return even->next;
}

int main(){
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = segregateEvenOdd(dummy->next);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
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


ListNode *midNode(ListNode *head){
    if(!head or !head->next){
        return head;
    }
    ListNode*slow=head,*fast=head;
    while(fast->next and fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
    ListNode *ans=NULL;
    ListNode *tail=NULL;
    while(l1 and l2){
        if(l1->val<l2->val){
            if(ans==NULL){
                ans=tail=l1;
                l1=l1->next;
            }else{
                tail->next=l1;
                tail=l1;
                l1=l1->next;
            }
        }else{
            if(ans==NULL){
                ans=tail=l2;
                l2=l2->next;
            }else{
                tail->next=l2;
                tail=l2;
                l2=l2->next;
            }
        }
    }
    if(ans==NULL){
        ans=tail=l1?l1:l2;
    }else{
        tail->next=l1?l1:l2;
    }
    return ans;
}


ListNode *mergeSort(ListNode *head){
    if(!head or !head->next){
        return head;
    }
    ListNode*mid=midNode(head);
    ListNode*nhead=mid->next;
    mid->next=NULL;
    ListNode*left=mergeSort(head);
    ListNode*right=mergeSort(nhead);
    return mergeTwoLists(left,right);
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

    ListNode *head = mergeSort(h1);
    printList(head);

    return 0;
}
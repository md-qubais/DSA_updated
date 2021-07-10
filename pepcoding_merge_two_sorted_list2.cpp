#include <iostream>
#include <vector>

using namespace std;

class ListNode{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val){
        this->val = val;
    }
};

int length(ListNode*head){
    int len=0;
    while(head){
        head=head->next;
        len++;
    }
    return len;

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

ListNode* mergeKLists(vector<ListNode *> &lists,int s,int e){
    if(s==e){
        return lists[s];
    }
    int mid=(s+e)/2;
    ListNode*left=mergeKLists(lists,s,mid);
    ListNode*right=mergeKLists(lists,mid+1,e);
    return mergeTwoLists(left,right);
}


ListNode *mergeKLists(vector<ListNode *> &lists){
    return mergeKLists(lists,0,lists.size()-1);
}

void printList(ListNode *node){
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *createList(int n){
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

int main(){
    int n;
    cin >> n;
    vector<ListNode *> list(n, 0);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        list[i] = createList(m);
    }

    ListNode *head = mergeKLists(list);
    printList(head);
    return 0;
}
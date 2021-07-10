#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define pb push_back
#define p push
#define fori(n) for(int i=0;i<n;i++)
#define ford(n) for(int i=n-1;i>=0;i--)
#define fl(x,n) for(int i=x;i<n;i++)
#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;

class ListNode{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val){
        this->val = val;
    }
};

ListNode *removeDuplicates(ListNode *head){
    ListNode*ans=new ListNode(-1);
    ListNode*tail=ans;
    ListNode*curr=head;
    head=head->next;
    while(curr){
        bool b=false;
        while(head and curr->val==head->val){
            head=head->next;
            b=true;
        }
        if(b){
        }else{
            tail->next=curr;
            tail=curr;
            tail->next=NULL;
        }
        curr=head;
        if(head)
        head=head->next;
    }
    return ans->next;
}

ListNode *makeList(int n)
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

int32_t main(){
    qubais_judge;
    IOS;    
    int n;
    cin >> n;
    ListNode *head = makeList(n);

    head = removeDuplicates(head);
    printList(head);
    return 0;
}
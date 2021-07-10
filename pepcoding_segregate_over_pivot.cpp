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
class ListNode
{
public:
  int val = 0;
  ListNode* next = nullptr;

  ListNode(int val)
  {
    this->val = val;
  }
};

ListNode* segregate(ListNode* head, int pivotIdx){
  ListNode*temp=head;
  while(pivotIdx--){
    temp=temp->next;
  }
  ListNode*first=new ListNode(-1);
  ListNode*fp=first;
  ListNode*second=new ListNode(-1);
  ListNode*sp=second;
  while(head){
    if(head==temp){
      head=head->next;
      continue;
    }
    else if(head->val<=temp->val){
      fp->next=head;
      fp=fp->next;
    }else{
      sp->next=head;
      sp=sp->next;
    }
    head=head->next;
  }
  fp->next=temp;
  fp=temp;
  fp->next=second->next;
  sp->next=nullptr;
  return first->next;
}

void printList(ListNode* node)
{
  ListNode* curr = node;
  while (curr != nullptr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

ListNode* createList(int n)
{
  ListNode* dummy = new ListNode(-1);
  ListNode* prev = dummy;
  while (n-- > 0)
  {
    int val;
    cin >> val;
    prev->next = new ListNode(val);
    prev = prev->next;
  }
  return dummy->next;
}

int32_t main(){
  qubais_judge;
  IOS;
  int n, pivotIdx;
  cin >> n;
  ListNode* h1 = createList(n);
  cin >> pivotIdx;
  h1 = segregate(h1, pivotIdx);
  printList(h1);
  return 0;
}
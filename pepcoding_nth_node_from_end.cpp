#include <iostream>
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

ListNode* removeNthFromEnd(ListNode* head, int n){
  if(!head or n<=0){
    return head;
  }
  ListNode*fast=head;
  while(n--){
    fast=fast->next;
    if(!fast and n>0){
      return head;
    }
  }
  if(!fast){
    return head->next;
  }
  ListNode*slow=head;
  while(fast->next){
    fast=fast->next;
    slow=slow->next;
  }
  slow->next=slow->next->next;


  return head;
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

int main()
{
  int n;
  cin >> n;
  ListNode* h1 = createList(n);
  int m;
  cin >> m;
  h1 = removeNthFromEnd(h1, m);
  printList(h1);

  return 0;
}
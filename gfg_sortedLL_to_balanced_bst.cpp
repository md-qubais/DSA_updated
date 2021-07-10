TNode* construct(vector<int>&arr,int s,int e){
    if(s==e){
        return new TNode(arr[s]);
    }
    if(s>e){
        return nullptr;
    }
    int mid=(s+e)/2;
    if((e+s)%2!=0){
        mid++;
    }
    TNode* root=new TNode(arr[mid]);
    root->left=construct(arr,s,mid-1);
    root->right=construct(arr,mid+1,e);
    return root;
}
TNode* sortedListToBST(LNode *head){
    vector<int> arr;
    while(head){
        arr.push_back(head->data);
        head=head->next;
    }
    return construct(arr,0,arr.size()-1);
}
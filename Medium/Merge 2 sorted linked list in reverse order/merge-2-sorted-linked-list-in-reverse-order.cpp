//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    Node* merge(Node *head1, Node *head2){
        Node* prev = head1;
        Node* current1 = head1 -> next;
        Node* current2 = head2;
        Node * next2 = current2 -> next;
        if(current1 == NULL){
            prev -> next = current2;
            return prev;
        }
        
        while(current1 != NULL && current2 != NULL){
            if((prev -> data <= current2 -> data) && (current2 -> data <= current1 -> data)){
                prev -> next = current2;
                next2 = current2 -> next;
                current2 -> next = current1;
                prev = prev -> next;
                current2 = next2;
            }
            else{
                prev = prev -> next;
                current1 = current1 -> next;
                
                if(current1 == NULL){
                    prev -> next = current2;
                    return head1;
                }
            }
        }
        return head1;
    }
    
    Node* reverse(Node* head){
        Node* prev = NULL;
        while(head != NULL){
            Node * next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    public:
    
    struct Node * mergeResult(Node *head1,Node *head2)
    {
        // your code goes here
        if(head1 == NULL){
            return reverse(head2);
        }
        
        if(head2 == NULL){
            return reverse(head1);
        }
        
        if(head1 == NULL && head2 == NULL){
            return nullptr;
        }
        
        if(head1 -> data <= head2 -> data){
            return reverse(merge(head1 , head2));
        }
        
        else{
            return reverse(merge(head2 , head1));
        }
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends
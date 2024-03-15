//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */
\

void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    Node * merge(Node* &m1 , Node* &m2){
        Node* dummy = new Node(0);
        Node * curr = dummy;
        while(m1 != NULL && m2 != NULL){
            if(m1 -> data < m2 -> data){
                curr -> next = m1;
                m1 = m1 -> next;
            }else{
                curr -> next = m2;
                m2 = m2 -> next;
            }
            curr = curr -> next;
        }
        if(m1 != NULL){
            curr -> next = m1;
        }else{
            curr -> next = m2;
        }
        return dummy -> next;
    }
    public:
    // your task is to complete this function
    Node* sort(Node **head)
   {
       if ((*head) == NULL || (*head)->next == NULL)
           return *head;

        struct Node *curr = *head;
        struct Node *next = (*head)->next;
        struct Node *asc = new Node(-1);
        struct Node *desc = NULL;
        struct Node *temp = asc;
        bool f = true;
        
        while(curr != NULL){
            if(f){
                struct Node *t = new Node(curr -> data);
                asc -> next = t;
                asc = asc -> next;
            }else{
                struct Node *t = new Node(curr -> data);
                t -> next = desc;
                desc = t;
            }
            f = !f;
            curr = curr -> next;
        }
        return merge(temp -> next , desc);
   }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    Node * temp = ob.sort(&head);
	    printList(temp);
	}
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        //code here
        if (!head_ref || !head_ref->next) {
            return head_ref;
        }
        Node* temp = head_ref;
        Node* prev = temp;
        Node* curr = temp->next;
        Node* nxt = temp->next->next;
        while(curr){
            if(curr->data<prev->data){
                prev->next = nxt;
                Node* prev_t = NULL;
                Node* nxt_t = temp;
                while(nxt_t){
                    if(nxt_t->data>=curr->data){
                        if(prev_t!=NULL) prev_t->next = curr;
                        curr->next = nxt_t;
                        break;
                    }
                    prev_t = nxt_t;
                    nxt_t = nxt_t->next;
                }
                if(prev_t == NULL) temp = curr;
                
            }
            else{
                prev = curr;
            }
            curr = nxt;
            if(nxt) nxt = nxt->next;
        }
        return temp;
    }
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
   string solve(string &s1, string &s2){
        int i = s1.size()-1 , j = s2.size()-1;
        string ans; bool carry = false;
        while(j >= 0){    
            if(carry == true){
                s1[i]--;        
            }
            if(s1[i] < s2[j]){
               int curr;
               if(carry && s1[i] == '/'){
                   curr = 9 - (s2[j] - '0');;
               }else{
                   curr = (10 + (s1[i] -'0')) - (s2[j] - '0');
               }
               carry = true;
               ans.push_back((curr+'0'));
            }else{
                carry = false;
                int curr = (s1[i] -'0') - (s2[j] - '0');
                ans.push_back((curr + '0'));
            }
            i--; j--;
        }
        while(i>=0){
            if(carry){
                if(s1[i] == '0') {
                    ans.push_back('9');
                    i--;
                    continue;
                }
                else{
                    s1[i]--;
                    carry = 0;
                }
            }
            ans.push_back(s1[i]);
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    Node* answer(string &s){
        
        int i = 0;
        while(s[i] == '0'){i++;}
        //cout << s << endl;
        if(i == s.size()){
            Node* ans = new Node(0);
            return ans;
        }
        Node* ans = new Node((s[i]-'0'));
        Node* a = ans;
        i++;
        for(i ; i < s.size() ; i++){
            Node* temp = new Node((s[i]-'0'));
            a -> next = temp;
            a = a -> next;
        }
        return ans;
    }
    
public:
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        Node* temp1 = head1 , *temp2 = head2;
        while(temp1 != NULL && temp1 -> data == 0 ){
            temp1 = temp1 -> next;
        }
        while(temp2 != NULL && temp2 -> data == 0){
            temp2 = temp2 -> next;
        }
        
        if(temp1 == NULL && temp2 == NULL){
            string s = "0";
            return answer(s);
        }
        if(temp1 == NULL) return temp2;
        if(temp2 == NULL) return temp1;
        
        string s1 , s2;
        while(temp1 != NULL){
            s1.push_back(temp1 -> data + '0');
            temp1 = temp1 -> next;
        }
        while(temp2 != NULL){
            s2.push_back(temp2 -> data + '0');
            temp2 = temp2 -> next;    
        }
        string s;
        if(s1.size() == s2.size()){
            string maxi = max(s2 , s1) , mini = min(s2,s1);
            s = solve(maxi,mini);
        }else s = s1.size() > s2.size() ? solve(s1 , s2) : solve(s2 , s1);
       // cout << s << endl;
        
        return answer(s);
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends
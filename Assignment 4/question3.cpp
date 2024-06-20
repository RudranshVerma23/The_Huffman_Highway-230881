#include<bits/stdc++.h>
using namespace std;

struct Node{ int val; Node* next; Node(): val(-1), next(nullptr){} };

Node* makeLinkedList(int n){
    Node* head = new Node();
    cout << "Input " << n << " values:" << endl;
    int t;
    cin>>t;
    head->val = t;
    Node* temp = new Node();
    head->next = temp;
    Node* curr = temp;
    for(int i=1; i < n; i++){
        cin >> t;
        curr->val = t;
        if(i-n+1){
            Node* ran = new Node();
            curr->next = ran;
            curr = ran;
        }
    }
    return head;
}

Node* Access(Node* head, int n){
    Node* curr = head;
    for(int i = 0; i < n; i++){
        curr = curr->next;
    }
    return curr;
}

bool checkPalindrome(Node* head){
    Node* reverse = nullptr;
    Node* curr = head;
    while(curr){
        Node* temp = new Node();
        temp->val = curr->val;
        temp->next = reverse;
        reverse = temp;
        curr = curr->next;
    }
    Node* curr1 = head, *curr2 = reverse;
    while(curr1){
        if(curr1->val != curr2->val){return false;}
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return true;
}

int main(){
    int inputs = 6;
    Node* head = makeLinkedList(inputs);
    if(checkPalindrome(head))
        cout << "Linked List is a Palindrome";
    else
        cout<< "Linked List is not a Palindrome";
}
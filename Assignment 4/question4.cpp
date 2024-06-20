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

void printList(Node* head){
    Node* curr = head;
    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }
}

//Access List element like an array
Node* Access(Node* head, int n){
    Node* curr = head;
    for(int i = 0; i < n; i++){
        curr = curr->next;
    }
    return curr;
}

int lengthOfList(Node* head){
    int length = 1;
    Node* back = head;
    while(back->next){
        back = back->next;
        length++;
    }
    return length;
}

Node* rotate(Node* head, int k, int length){
    k %= length;
    if(k==0){return head;}
    Node* temp = Access(head,length-1-k);
    Node* pseudo = temp->next;
    Node* last = pseudo;
    while(last->next){last = last->next;}

    last->next = head;
    head = pseudo;
    temp->next = nullptr;
    
    return head;
}


int main(){
    int inputs = 10;
    Node* head = makeLinkedList(inputs);
    cout << "Initial List: ";
    printList(head);
    int k; cout << endl << "k = "; cin>>k;
    cout << "Final List: ";
    head = rotate(head,k,inputs); //or you can use length function
    printList(head);
}
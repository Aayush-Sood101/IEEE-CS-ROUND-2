#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(){
        val = 0;
        next = prev = NULL;
    }

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


class DoublyLinkedList{
public:
    Node* head;
    Node* tail;
    int size;
    DoublyLinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(size == 0){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(size == 0){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void forwardDisplay(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void backwardDisplay(){
        Node* temp = tail;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->prev;
        }
    }
};


int main(){
    DoublyLinkedList dll;
    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.insertAtHead(30);
    dll.insertAtTail(40);
    dll.insertAtTail(50);
    dll.insertAtTail(60);
    dll.forwardDisplay();
    dll.backwardDisplay();
}
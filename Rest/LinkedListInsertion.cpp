#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};


void insertAtFront(Node* &head,int d){
    Node* ptr=new Node(d);
    Node* temp=head;
    if(head==NULL){
       head=ptr;
    }
    ptr->next=head;
    head=ptr;
}

void insertAtEnd(Node* &head,int d){
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node*ptr=new Node(d);
    temp->next=ptr;
}

void insertAtPosition(Node* &head,int position,int d){
    Node* temp=head;
    int i=0;
    while(i<position){
        temp=temp->next;
        i++;
    }
    Node* ptr=new Node(d);
    ptr->next=temp->next;
    temp->next=ptr;
}

void print(Node* &head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }cout<<endl;
} 


void deleteNode(Node*head,int position){
    if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* current=head;
        Node* previous=NULL;
        int count=1;
        while(count<position){
            previous=current;
            current=current->next;
            count++;
        }
        previous->next=current->next;
        current->next=NULL;
        delete current;
    }

}

int main(){
    Node * temp=new Node(10);

    Node* head=temp;
    insertAtFront(head,46512);
    print(head);
    insertAtEnd(head,75421);
    print(head);
    deleteNode(head,2);
    insertAtPosition(head,1,324513);
    print(head);
    return 0;
}
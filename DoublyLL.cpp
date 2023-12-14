#include<iostream>
using namespace std;

class Node{
    public:
      int data;
      Node* next;
      Node* prev;

    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->prev=NULL;
    }

    ~Node(){
        cout<<data<<endl;
    }
};

void insertAtFront(Node* &head,int d){
     Node* newnode=new Node(d);
     newnode->next=head;
     if(head!=NULL){
        head->prev=newnode;
     }
     head=newnode;
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next; 
    }
    cout<<endl;
}

void insertAtEnd(Node* head,int d){
    Node* temp=head;
    Node* newnode=new Node(d);
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    }

void insertAtPos(Node* &head,int pos,int d){
    if(pos<=0){
        cout<<"Invalid postion\n";
    }
    if(pos==1 || head==NULL){
        insertAtFront(head,d);
        return ;
    }
    Node* temp=head;
    Node* newnode=new Node(d);
    int count=1;
    while(count<pos-1 && temp->next!=NULL){
        temp=temp->next;
        count++;
    }

    newnode->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=newnode;
    }

    temp->next=newnode;
    newnode->prev=temp;
}

void deleteNode(Node* &head,    int d){
      if(head==NULL){
        return;
      }

      if(head->data==d){
          Node* temp=head;
          head=head->next;
          if(head!=NULL){
            head->prev=NULL;
          }
          delete temp;
          return ;  
      }
      
      Node*current=head;
      while(current!=NULL && current->data!=d){
        current=current->next;
      }
      if(current==NULL){
        cout<<"Node with this value doesn't exit"<<endl;
        return ;
      }
      if(current->prev!=NULL){
        current->prev->next=current->next;
      }
      if(current->next!=NULL){
        current->next->prev=current->prev;
      }
      delete current;


    }
int main(){
    return 0;
}
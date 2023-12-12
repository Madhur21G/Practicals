#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
// Display of doubly linked list same as that of singly linked list

struct node{
    int data;
    struct node *next;
    struct node* prev;
};
struct node* head = NULL;
struct node*tail;
struct node* newnode;
struct node*temp;

void insertatbeg(){
    newnode = (struct node*)malloc(sizeof(struct node));
    scnaf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insertatend(){
    newnode = (struct node*)malloc(sizeof(struct node));
    scnaf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}

void insertatpos(){
    newnode = (struct node*)malloc(sizeof(struct node));
    scnaf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    int pos;
    temp = head;
    scanf("%d", &pos);
    // pos != 1
    int i = 1;
    while(i < pos - 1){
        temp = temp->next;
        i++;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode;
}

void deletefrombeg(){
    struct node* temp;
    temp = head;
    head = head-> next;
    head->prev = NULL;
    free(temp);
}

void deletefromend(){
    struct node* temp;
    temp = tail;
    tail->prev->next=NULL;
    tail = tail->prev;
    free(temp);
}

void deletefrompos(){
    struct node*temp;
    temp = head;
    int i = 1;
    int pos;
    scanf("%d", &pos);
    while(i < pos){
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void reverseDll(){
    struct node* current;
    struct node* nextnode;
    current = head;
    while(current != NULL){
        nextnode = curent->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    }
    current = head;
    head = tail;
    tail = current;
    
}

void create(){
    struct node* temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    scnaf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    if(head == NULL) head = temp = tail = newnode;
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

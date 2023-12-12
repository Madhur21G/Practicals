#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node{
    int data;
    struct node *next;
};
struct node*tail;
struct node*temp;

void insertatbeg(){
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &newnode->data);
    newnode->next = tail-> next;
    tail->next = newnode;
}

void insertatend(){
    newnode = (struct node*)malloc(sizeof(struct node));
    scnaf("%d", &newnode->data);
    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode;
}

void insertatpos(){
    newnode = (struct node*)malloc(sizeof(struct node));
    scnaf("%d", &newnode->data);
    int pos;
    int l = getlength();
    scanf("%d", &pos);
    // pos != 1
    int i = 1;
    newnode->next = 0;
    temp = tail->next;
    while(i < pos - 1){
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;

}

void deletefrombeg(){
    struct node* temp;
    temp = tail->next;
    tail->next = temp->next;
    free(temp);
}

void deletefromend(){
    struct node* current, *prev;
    current = tail->next;
    while(current->next != tail->next){
        prev = current;
        current = current->next;
    }
    prev->next = tail->next;
    tail = prev;
    free(current);
}

void reverseCll(){
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

void displayCLL(){
    struct node *temp;
    temp = tail->next;
    while(temp != tail->next){
        // Display
        temp -> temp -> next;
    }
}

void createCLL(){
    struct node* newnode;
    tail = NULL;
    newnode = (struct node*)malloc(sizeof(struct node));
    scnaf("%d", &newnode->data);
    newnode->next = NULL;
    if(tail == NULL) head = tail = newnode; tail->next = newnode;
    else{
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

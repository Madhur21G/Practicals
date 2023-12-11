#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node{
    int data;
    struct node *next;
};

struct node* head = NULL;
struct node* newnode;
struct node* temp;
// Delete from beginning
void deletefrombeg(){
    struct node *temp2;
    temp2 = head;
    head = head->next;
    free(temp);
}

void Deletefromend(){
    struct node*temp2;
    struct node* prevnode;
    temp2= head;
    while(temp2 -> next != NULL){
        prevnode = temp2;
        temp2 = temp2 -> next;
    }
    if(temp2 == head){
        head = NULL;
    }
    else{
        prevnode->next = NULL;
    }
    free(temp2);
}

void Deletefrompos(){
    strut node* nextnode;
    int pos;
    int i =1;
    temp = head;
    while(i < pos - 1){
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}

 // Insertion
int main(){
    newnode = (struct node *)malloc(sizeof(struct node));
    // Insertion at beginning
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    
    // Insertion ar end
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;

    // Insert At a given location
    scanf("%d", &newnode->data);
    int pos;
    int i = 1;
    scanf("%d", &pos);
    temp = head;
    while(i < pos){
        temp = temp -> next;
        i++;
    }
    newnode -> next = temp -> next;
    temp-> next = newnode;

    return 0;
}
// For printing a linked list initialise temp to head and check till the condition while(temp != 0) print temp-> data and increment temp using temp = temp -> next


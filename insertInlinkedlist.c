#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next ;
};

// creating the node with input from user 
 struct node*createnode(int data){
    struct node * newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->next= NULL;
    return newnode;
 }
 // printing the node 
void printll(struct node *head ){
    struct node *ptr=head;
    printf("the element of the linked list are \n");
    while(ptr!=NULL){
        printf ("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
//finding the length of linked list 
int  length(struct node *head){
    int i=0;
    while (head!=NULL){
        head=head->next;
        i++;
    }
    return i;
}
// insert at the beginning 
struct node* insertatbeg(struct node *head, int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
ptr->next=head;
head=ptr;
return head;
}
//insert at the end 
void insertatend (struct node *head,int data){
    struct node * ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    while (head->next!=NULL){
        head= head->next;
    }
    head->next=ptr;
    ptr->next=NULL;
}
// insert at mid 
void insertatmid(struct node* head,int data){
    struct node * ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
   int len=length(head); 
   int i=0;
   while(i<(len/2)-1){
    head=head->next;
    i++;
   }
   ptr->next=head->next;
   head->next=ptr;
   
}
//inserting at the idx 
void atTheIdx(struct node *head,int data,int idx){
   
    if (idx==(length(head)-1)){
        insertatend(head,data);
        return ;
    }
struct node * ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
int i=0;
while (i<idx-1){
    head=head->next;
    i++;
}
ptr->next=head->next;
head->next=ptr;
}
// insert after the given position 
void insertafter(struct node* head, int data,int idx){
struct node * ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    int i=0;
    while (i<idx){
head= head->next;
i++;
    }
ptr->next=head->next;
head->next=ptr;
}

int main(){
    struct node* head=NULL;
    struct node* current = NULL;
printf ("enter the length of the linkedlist \n");
int len;
scanf("%d",&len);
for(int i=0;i<len;i++){
    int data;
printf("enter the data of the %d index element\n ",i );
scanf("%d",&data);
if (head==NULL){
    head=createnode(data);
    current = head;
}
else{
    current-> next=createnode(data);
    current = current ->next;
}

}
// calling the print function 
printll(head);
//head=insertatbeg(head,55);
//printll(head);
//insertatend(head,58);
//printll(head);
printf("length of linked list is %d\n",length(head));
//insertatmid(head,143);
//printll(head);
 atTheIdx(head,56,5);// not for idx 0;
 printll(head);
 insertafter( head, 55, 4);
 printll(head);
}
#include<stdio.h>


struct node
{
int data;
struct node*next;
};

typedef struct node *NODE;

NODE getnode()
{
NODE temp;
temp=(NODE)malloc(sizeof(struct node));
if(temp==NULL)
{
    perror("error");
    //exit(0);
}
temp->next=NULL;
return temp;
}
NODE createNODE()
{
    NODE temp;
    temp=getNODE();
    scanf("%d",&temp->data);
    return temp;
}

NODE insertNODEATEND(NODE head)
{
    NODE temp,cur;
    temp=createNODE();
    temp->next=NULL;
    if(head==NULL)
    {
        return temp;
    }
    cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=temp;
    return head;

}
void displaylist(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("list empty\n");
        return NULL;
    }
    printf("the elements are: ");
    cur=head;

    while(cur!=NULL)
    {
        printf("%d-->",cur->data);
        cur=cur->next;
    }
    printf("NULL");
}

int main()
{
   NODE temp;
   NODE head;
   head=insertNODEATEND(head);
   while(1)
   {
        int choice;
   switch(choice)
   {
          //int choice;
      printf("\nMenu:\n_______\n 1:Insert\n 2:Display\n 3:Exit\n");
      printf("enter your choice: ");
      scanf("%d",&choice);
       case 1:insertNODEATEND(head);
       break;
       case 2:displayList(head);
       break;
       default: exit(0);
   }
   }
   return 0;

  }

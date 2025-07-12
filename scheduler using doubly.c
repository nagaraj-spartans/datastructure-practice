
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
   char name[10];
   int prio,dur;
   struct Node *next;
   struct Node *prev;
};

struct Node *head=0;
struct Node *tail=0;

void addbeg(char *a,int prio,int dur)
{
   struct Node *new=(struct Node*)malloc(sizeof(struct Node));
   strcpy(new->name,a);
   new->prio=prio;
   new->dur=dur;
   new->prev=0;
   new->next=head;
   if(head!=0)
       head->prev=new;
   else
       tail=new;
   head=new;    
}
void display()
{
   printf("----------");
   printf("Name\t\tPriority\tduration\n");
   printf("----------");
   struct Node *disp=tail;
   while(disp!=0)
   {
   printf("%s\t\t%d\t\t%d\n",disp->name,disp->prio,disp->dur);
   disp=disp->next;
   }
   
   printf("-----------");
}

int main()
{
int choice;
int prio,dur;
char a[10];
do{
    printf("choose one option \n");
    printf("1.Include Task \n");
    printf("2.Display Tasks \n");
    printf("3.Exit \n");
    printf("y  \n");
    scanf("%d",&choice);
    getchar();
    switch(choice){
    case 1:
       printf("Enter Task Name : ");
       scanf("%s",a);
       printf("Enter Priority : ");
       scanf("%d",&prio);
       printf("Enter duration (in mins) : ");
       scanf("%d",&dur);
       addbeg(a,prio,dur);
       break;
    case 2:display();
       break;
    case 3:printf("Exit \n");
       break;
    default:printf("Invalid option\n");       
}

}while(choice!=3);
return 0;
}

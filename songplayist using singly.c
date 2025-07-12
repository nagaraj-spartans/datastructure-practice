#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
  char song_title[100];
  char artist[100];
  float duration;
  struct Node *next;
};
struct Node *head=0;
void addend(char song[],char art[],float dur)
{
  struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->song_title,song);
  strcpy(newNode->artist,art);
  newNode->duration=dur;
  newNode->next=0;
  if(head==0)
      head=newNode;
  else
  {
    struct Node *temp=head;
    while(temp->next!=0)
       temp=temp->next;
    temp->next=newNode;   
  }
}
void display()
{
  struct Node *temp=head;
  if(temp==0)
  {
    printf("Playlist is empty.");
    return;
  }
  while(temp!=0)
  {
    printf("Song Title: %s, Artist: %s, Duration: %.1f min\n",temp->song_title,temp->artist,temp->duration);
    temp=temp->next;
  }
}
int main()
{
  char song_name[100],artist[100];
  float duration;
  int op,size,i;
  for(i=1;i<=size;i++)
  {
    scanf("%d",&op); 
    getchar();
   if(op==1)
  {
    fgets(song_name,sizeof(song_name),stdin);
    song_name[strcspn(song_name,"\n")]='\0';
    fgets(artist,sizeof(artist),stdin);
    artist[strcspn(artist,"\n")]='\0';
   
    scanf("%f",&duration);
    
    addend(song_name,artist,duration);
  }
  else if(op==2)
      display();
  else if(op==3)
  exit(0);
  }
}

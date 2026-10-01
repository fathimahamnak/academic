  1 #include<stdio.h>
  2 #include<stdlib.h>
  3 struct node{
  4     int data;
  5     struct node *next;
  6 };
  7 struct node *front=NULL;
  8 struct node *rear=NULL;
  9
 10 void enqueue(int value)
 11 {
 12     struct node *newnode=(struct node*) malloc (sizeof(struct node));
 13     if(newnode==NULL)
 14     {
 15         printf("Queue overflow\n");
 16         return ;
 17     }
 18     newnode -> data=value;
 19     newnode -> next=NULL;
 20     if(rear==NULL)
 21     {
 22         front=rear=newnode;
 23     }
 24     else
 25     {
 26         rear -> next=newnode;
 27         rear = newnode;
 28     }
 29     printf("%d enqueued to queue \n",value);
 30 }
 31 void dequeue()
 32 {
 33     if (front == NULL)
 34     {
 35         printf("Queue underflow\n");
 36         return;
 37     }
 38     struct node *temp=front;
 39     printf("%d dequeued from queue\n",front -> data);
 40     front = front -> next;
 41     if(front == NULL)
 42         rear = NULL;
 43     free(temp);
 44 }
 45 void display()
 46 {
 47     if(front == NULL)
 48 {
 49     printf("Queue is empty\n");
 50     return;
 51 }
 52 struct node *temp = front;
 53 printf("Queue elements:");
 54 while(temp!=NULL)
 55 {
 56     printf("%d -> ",temp->data);
 57     temp = temp->next;
 58 }
 59 printf("NULL\n");
 60 }
 61 int main(){
 62     int choice,value;
 63     while(1){
 64         printf("\n--Queue using Linkedlist--\n");
 65         printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
 66         printf("Enter your choice:");
 67         scanf("%d",&choice);
 68         switch(choice){
 69             case 1:
 70                 printf("Enter value to enqueue:");
 71                 scanf("%d",&value);
 72                 enqueue(value);
 73                 break;
 74             case 2:
 75                 dequeue();
 76                 break;
 77             case 3:
 78                 display();
 79                 break;
 80             case 4:
 81                 exit(0);
 82             default:
 83                 printf("Invalid choice!");
 84         }
 85     }
 86     return 0;
 87 }

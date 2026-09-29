 1 #include<stdio.h>
  2 #include<stdlib.h>
  3
  4 struct Node{
  5     int data;
  6     struct Node *Next;
  7 };
  8 struct Node *top = NULL;
  9
 10 void push(int value) {
 11     struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
 12     if (newNode == NULL) {
 13         printf("Stack overflow\n");
 14         return;
 15     }
 16     newNode->data = value;
 17     newNode->Next=top;
 18     top = newNode;
 19     printf("%d pushed to stack\n",value);
 20 }
 21 void pop() {
 22     if (top == NULL) {
 23         printf("Stack underflow\n");
 24         return;
 25     }
 26     struct Node *temp = top;
 27     printf("%d popped from stack\n", top->data);
 28     top = top->Next;
 29     free(temp);
 30 }
 31 void display(){
 32     if (top == NULL){
 33         printf("Stack is empty!\n");
 34         return;
 35     }
 36     struct Node *temp=top;
 37     printf("Stack elements are:\n");
 38
 39     while(temp !=NULL){
 40  printf("%d\n", temp->data);
 41         temp = temp->Next;
 42     }
 43 }
 44 int main() {
 45     int choice, value;
 46
 47     while (1) {
 48         printf("\n--- STACK USING LINKED LIST ---\n");
 49         printf("1. Push\n");
 50         printf("2. Pop\n");
 51         printf("3. Display\n");
 52         printf("4. Exit\n");
 53         printf("Enter your choice: ");
 54         scanf("%d", &choice);
 55
 56         switch (choice) {
 57             case 1:
 58                 printf("Enter value to push: ");
 59                 scanf("%d", &value);
 60                 push(value);
 61                 break;
 62
 63             case 2:
 64                 pop();
 65                 break;
 66
 67             case 3:
 68                 display();
 69                 break;
 70
 71             case 4:
 72                 printf("Exiting....\n");
 73                 return 0;
 74
 75             default:
 76                 printf("Invalid choice!\n");
 77         }
 78     }
 79
 80     return 0;
 81 }

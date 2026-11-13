 1 #include<stdio.h>
  2 #define SIZE 5
  3
  4 int queue[SIZE];
  5 int front = -1 , rear = -1;
  6
  7 void enqueue(int value) {
  8     if ((rear + 1)% SIZE == front) {
  9         printf("Queue is FULL (Overflow). \n");
 10         return;
 11     }
 12     if (front == -1)
 13         front = 0;
 14     rear = (rear + 1) % SIZE;
 15     queue[rear] = value;
 16     printf("%d inserted.\n", value);
 17 }
 18 void dequeue() {
 19     if(front == -1) {
 20         printf("Queue is EMPTY (Underflow).\n");
 21         return;
 22     }
 23     printf("%d deleted.\n", queue[front]);
 24     if (front == rear)
 25         front = rear = -1;
 26     else
 27         front = (front + 1)% SIZE;
 28 }
 29 void display() {
 30     if (front == -1) {
 31         printf("Queue is EMPTY.\n");
 32         return;
 33     }
 34     printf("Queue: ");
 35     int i = front;
 36     while(1) {
 37         printf("%d",queue[i]);
 38         if (i == rear)
 39             break;
 40         i= (i + 1)%SIZE;
 41     }
 42     printf("\n");
 43 }
 44 int main(){
 45     int choice, value;
 46
 47     while(1) {
 48         printf("\n---Circular Queue ---\n");
 49         printf("1. Insert\n");
 50         printf("2. Delete\n");
 51         printf("3. Display\n");
 52         printf("4. Exit\n");
 53         printf("Enter choice: ");
 54         scanf("%d", &choice);
 55
 56         switch (choice) {
 57             case 1:
 58                 printf("Enter value to insert: ");
 59                 scanf("%d", &value);
 60                 enqueue(value);
 61                 break;
 62             case 2:
 63                 dequeue();
 64                 break;
 65             case 3:
 66                 display();
 67                 break;
 68             case 4:
 69                 return 0;
 70             default:
 71                 printf("Invalid choice.\n");
 72         }
 73     }
 74 }

1 #include<stdio.h>
  2 int main()
  3 {
  4     int i,n,ch,v;
  5
  6     printf("Enter size of queue:");
  7     scanf("%d",&n);
  8     if(n<=0)
  9     {
 10         printf("Invalid size!\n");
 11         return 1;
 12     }
 13
 14     int queue[n];
 15     int f = -1,r = -1;/*front and rear ,-1 means empty */
 16
 17     while(1)
 18     {
 19         printf("\nMENU\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
 20         printf("Enter your choice:");
 21         scanf("%d",&ch);
 22
 23         if (ch==1)/*Enqueue*/
 24         {
 25             if(r==n-1)
 26             {
 27                 printf("Queue is full!\n");
 28             }
 29             else
 30             {
 31                 printf("Enter the element:");
 32                 scanf("%d",&v);
 33                 r=r+1;
 34                 queue[r]=v;
 35                 if(f==-1)
 36                 {
 37                     f=0;
 38                 }
 39             }
 40         }
 41         else if(ch==2)/*Dequeue*/
 42         {
 43             if(f==-1 || f>r)
 44             {
 45                 printf("Queue is empty!\n");
 46             }
 47             else
 48             {
 49                 printf("Deleted %d\n",queue[f]);
 50                 f=f+1;/* move front forward*/
                                                                     
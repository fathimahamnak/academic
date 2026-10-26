 1
  2 #include <stdio.h>
  3 #include <stdlib.h>
  4
  5 struct Node
  6 {
  7     int data;
  8     struct Node *prev;
  9     struct Node *next;
 10 };
 11
 12 struct Node *head = NULL;
 13
 14 // Insert at the beginning
 15 void insertAtBeginning()
 16 {
 17     struct Node *newNode;
 18     int value;
 19
 20     printf("Enter the value: ");
 21     scanf("%d", &value);
 22
 23     newNode = (struct Node *)malloc(sizeof(struct Node));
 24
 25     if (newNode == NULL)
 26     {
 27         printf("Memory allocation failed!\n");
 28         return;
 29     }
 30
 31     newNode->data = value;
 32     newNode->prev = NULL;
 33     newNode->next = head;
 34
 35     if (head != NULL)
 36     {
 37         head->prev = newNode;
 38     }
 39
 40     head = newNode;
 41
 42     printf("Node inserted at the beginning.\n");
 43 }
 44
 45 // Insert at the end
 46 void insertAtEnd()
 47 {
 48     struct Node *newNode;
 49     struct Node *temp;
 50     int value;
 51
 52     printf("Enter the value: ");
 53     scanf("%d", &value);
 54
 55     newNode = (struct Node *)malloc(sizeof(struct Node));
 56
 57     if (newNode == NULL)
 58     {
 59         printf("Memory allocation failed!\n");
 60         return;
 61     }
 62
 63     newNode->data = value;
 64     newNode->next = NULL;
 65
 66     if (head == NULL)
 67     {
 68         newNode->prev = NULL;
 69         head = newNode;
 70     }
 71     else
 72     {
 73         temp = head;
 74
 75         while (temp->next != NULL)
 76         {
 77             temp = temp->next;
 78         }
 79
 80         temp->next = newNode;
 81         newNode->prev = temp;
 82     }
 83
 84     printf("Node inserted at the end.\n");
 85 }
 86
 87 // Display in forward direction
 88 void displayForward()
 89 {
 90     struct Node *temp = head;
 91
 92     if (head == NULL)
 93     {
 94         printf("List is empty.\n");
 95         return;
 96     }
 97
 98     printf("Forward list: ");
 99
100     while (temp != NULL)
101     {
102         printf("%d ", temp->data);
103         temp = temp->next;
104     }
105
106     printf("\n");
107 }
108
109 // Delete a node by value
110 void deleteNode()
111 {
112     struct Node *temp = head;
113     int value;
114
115     if (head == NULL)
116     {
117         printf("List is empty.\n");
118         return;
119     }
120
121     printf("Enter value to delete: ");
122     scanf("%d", &value);
123
124     while (temp != NULL && temp->data != value)
125     {
126         temp = temp->next;
127     }
128
129     if (temp == NULL)
130     {
131         printf("Node not found.\n");
132         return;
133     }
134
135     // Update the previous node or head
136     if (temp->prev != NULL)
137     {
138         temp->prev->next = temp->next;
139     }
140     else
141     {
142         head = temp->next;
143     }
144
145     // Update the next node
146     if (temp->next != NULL)
147     {
148         temp->next->prev = temp->prev;
149     }
150
151     free(temp);
152
153     printf("Node deleted successfully.\n");
154 }
155
156 // Display in reverse direction
157 void displayReverse()
158 {
159     struct Node *temp = head;
160
161     if (head == NULL)
162     {
163         printf("List is empty.\n");
164         return;
165     }
166
167     // Move to the last node
168     while (temp->next != NULL)
169     {
170         temp = temp->next;
171     }
172
173     printf("Reverse list: ");
174
175     // Traverse backward
176     while (temp != NULL)
177     {
178         printf("%d ", temp->data);
179         temp = temp->prev;
180     }
181
182     printf("\n");
183 }
184
185 // Main function
186 int main()
187 {
188     int ch;
189
190     while (1)
191     {
192         printf("\n--- Doubly Linked List Menu ---\n");
193         printf("1. Insert at Beginning\n");
194         printf("2. Insert at End\n");
195         printf("3. Display Forward\n");
196         printf("4. Delete Node\n");
197         printf("5. Display Reverse\n");
198         printf("6. Exit\n");
199
200         printf("Enter your choice: ");
201         scanf("%d", &ch);
202
203         switch (ch)
204         {
205             case 1:
206                 insertAtBeginning();
207                 break;
208
209             case 2:
210                 insertAtEnd();
211                 break;
212
213             case 3:
214                 displayForward();
215                 break;
216
217             case 4:
218                 deleteNode();
219                 break;
220
221             case 5:
222                 displayReverse();
223                 break;
224
225             case 6:
226                 // Free all remaining nodes
227                 while (head != NULL)
228                 {
229                     struct Node *temp = head;
230                     head = head->next;
231                     free(temp);
232                 }
233
234                 printf("Exiting program.\n");
235                 return 0;
236
237             default:
238                 printf("Invalid choice. Try again.\n");
239         }
240     }
241
242     return 0;
243 }
244

                                                                          
                                                               
                                                                                                        
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 21

 
struct node

{

    int data;

    struct node *link;

}*front, *rear;

 

// function protypes

void insert();

void delete();

void ReverseQ();

void Sort();

bool search();

void queue_size();

void first_element();


void main()

{

    int choice, val;


    while(1)

    {

        printf("enter the choice \n");

        printf("1 : create an empty queue \n2 : Insert element\n");

        printf("3 : Dequeue an element \n4 : Check if empty\n");

        printf("5. Get the first element of the queue\n");

        printf("6. Reverse\n");

        printf("7. Sort\n");

        printf("8. Search\n");

        printf("9. Exit\n");

        scanf("%d", &choice);

        switch (choice)    // menu driven program

        {

        case 1: 

            printf("Empty queue is created with a capacity of %d\n", MAX);

            break;

        case 2:    

            insert();

            break;

        case 3: 

            delete();

            break;

        case 4: 

            first_element();

            break;

        case 5: 

            queue_size();

            break;

        case 6: 

            ReverseQ(); 
            break;

        case 7:
            Sort();
            break;  

        case 8:
            printf("\nSearch For: ");
            scanf("%d", &val);
            search(val);
            if (search(val)==true)
            {
                printf("\nThe Element is in queue!\n");
            }
            else
            {
                printf("\nThe Element is missing from queue!\n");
            }
            break;     

        case 9:
            exit(0);   

        default: 

            printf("wrong choice\n");

            break;

        }

    }

}

 

// to insert elements in queue

void insert()

{

    struct node *temp;

 

    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter value to be inserted \n");

    scanf("%d", &temp->data);

    temp->link = NULL;

    if (rear  ==  NULL)

    {

        front = rear = temp;

    }

    else

    {

        rear->link = temp;

        rear = temp;

    }    

}

 

// delete elements from queue

void delete()

{

    struct node *temp;


    temp = front;

    if (front == NULL)

    {

        printf("queue is empty \n");

        front = rear = NULL;

    }

    else

    {    

        printf("deleted element is %d\n", front->data);

        front = front->link;

        free(temp);

    }

}

 void ReverseQ()
{
   struct node* current;
   struct node* nxt;
   struct node* prev = NULL;
   struct node* temp;
   current = front;
   while (current!=NULL)
   {
      temp=current->link;
      current->link=prev;
      prev=current;
      current=temp;
   }
   front=prev;
   
}

void Sort()
{
    struct node** q;
    int i, j, swapped;
    int countQ = count(front);
    for (i = 0; i <= countQ; i++) {
 
        q = &front;
        swapped = 0;
 
        for (j = 0; j < countQ - i - 1; j++) {
 
            struct node* p1 = *q;
            struct node* p2 = p1->link;
 
            if (p1->data > p2->data) {

                  struct node* tmp = p2->link;
                  p2->link = p1;
                  p1->link = tmp;
                  *q = p2;

                swapped = 1;
            }
 
            q = &(*q)->link;
        }

        if (swapped == 0)
            break;
    }
}

bool search(int val)
{
   struct node *curr;
   curr=front;
   while (curr!=NULL)
   {
      if (curr->data==val)
      {
         return true;
      }
      curr=curr->link;
   }
   return false;
};

// check if queue is empty or not

void check()

{

    if (front == NULL)

        printf("\nQueue is empty\n");

    else

        printf("*************** Elements are present in the queue **************\n");

}

 

// returns first element of queue

void first_element()

{

    if (front == NULL)

    {

        printf("**************** The queue is empty ****************\n");

    }

    else

        printf("**************** The front element is %d ***********\n", front->data);        

}

 

// returns number of entries and displays the elements in queue

void queue_size()

{

    struct node *temp;

 

    temp = front;

    int cnt = 0;

    if (front  ==  NULL)

    {

        printf(" queue empty \n");

    }

    while (temp)

    {

        printf("%d  ", temp->data);

        temp = temp->link;

        cnt++;

    }

    printf("********* size of queue is %d ******** \n", cnt);

}
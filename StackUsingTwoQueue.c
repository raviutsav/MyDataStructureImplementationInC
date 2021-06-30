/*Name - Ravi Utsav
  Roll - IIT2020504

  IMPLEMENTATION OF STACK USING 2 QUEUE
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* front1 = NULL;
struct node* back1 = NULL;

struct node* front2 = NULL;
struct node* back2 = NULL;

void initialise_queue(void);
void enqueue1(int data);
int isEmpty1(void);
void dequeue1(void);
int peek1(void);
void enqueue2(int data);
int isEmpty2(void);
void dequeue2(void);
int peek2(void);
void stack_push(int data);
void stack_pop(void);
int stack_peek(void);


int main()
{
    initialise_queue();
    int n;
    int a;

    printf("Number of element to put in stack: ");
    scanf("%d", &a);

    printf("Enter elements in stack\n");
    for(int i = 0; i < a; i++)
    {
       scanf("%d", &n);
       stack_push(n);
    }


    printf("Press 1 to pop an element, press 2 to peek, press -1 to exit \n");
    int press;
    printf("Press: ");
    scanf("%d", &press);

    while(press != -1)
    {
        if(press == 1)
        {
            printf("popping an element.\n");
            stack_pop();
        }
        if(press == 2)
        {
            printf("Element on top: %d\n", stack_peek());
        }

        if(press == -1) break;

        printf("Press: ");
        scanf("%d", &press);
    }

    return 0;
}


void initialise_queue(void)
{
    struct node* temp1 = (struct node *)malloc(sizeof(struct node));
    temp1->data = -1;
    temp1->next = NULL;
    front1 = temp1;
    back1 = temp1;

    struct node* temp2 = (struct node *)malloc(sizeof(struct node));
    temp2->data = -1;
    temp2->next = NULL;
    front2 = temp2;
    back2 = temp2;

}


void enqueue1(int data)
{
    struct node* temp = (struct node *)malloc(sizeof(struct node));

    if(front1 == NULL)
    {
        temp->data = data;

        front1 = temp;
        back1 = front1;
        back1->next = NULL;
    }

    else
    {
        temp->data = data;
        back1->next = temp;
        temp->next = NULL;
        back1 = temp;
    }

}

int isEmpty1(void)
{
    if(front1 == NULL || back1 == NULL) return 1;
    else return 0;
}

void dequeue1(void)
{
    if(isEmpty1()) printf("Queue1 is empty\n");
    else front1 = front1->next;

    return;
}


int peek1(void)
{
    if(isEmpty1())
    {
        printf("Queue1 is empty(return 0)\n");
        return 0;
    }

    else return (front1->data);
}



void enqueue2(int data)
{
    struct node* temp = (struct node *)malloc(sizeof(struct node));

    if(front2 == NULL)
    {
        temp->data = data;

        front2 = temp;
        back2 = front2;
        back2->next = NULL;
    }

    else
    {
        temp->data = data;
        back2->next = temp;
        temp->next = NULL;
        back2 = temp;
    }

}

int isEmpty2(void)
{
    if(front2 == NULL || back2 == NULL) return 1;
    else return 0;
}

void dequeue2(void)
{
    if(isEmpty2()) printf("Queue2 is empty\n");
    else front2 = front2->next;

    return;
}



int peek2(void)
{
    if(isEmpty2())
    {
        printf("Queue2 is empty(return 0)\n");
        return 0;
    }
    else return (front2->data);
}


void stack_push(int data)
{
    enqueue2(data);
    int temp;
    while(front1 != NULL)
    {
        temp = peek1();
        enqueue2(temp);
        dequeue1();
    }

    struct node* t1 = NULL;
    t1 = front1;
    front1 = front2;
    front2 = t1;
}

void stack_pop(void)
{
    dequeue1();
}

int stack_peek(void)
{
    return (peek1());
}

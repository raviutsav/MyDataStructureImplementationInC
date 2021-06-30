/* Name - Ravi Utsav
   Roll - IIT2020504

   IMPLEMENTATION OF QUEUE USING TWO STACK
*/

#include <stdio.h>
#include <stdlib.h>

void push1(int);
void push2(int);
int pop1(void);
int pop2(void);
void enqueue(void);
void dequeue(void);
void print_queue_elements(void);
void create(void);

int stack1[100];
int stack2[100];
int top1, top2;
int count = 0;

int main()
{
    create();

    int n;
    printf("Enter no of elements to put in queue: ");
    scanf("%d", &n);

    printf("Enter elements into queue\n");
    for(int i = 0; i < n; i++)
    {
        enqueue();
    }

    printf("Press 1 to dequeue, Press 2 to print queue elements and -1 to exit.\n");
    printf("Press: ");
    int press;
    scanf("%d", &press);

    while(press != -1)
    {
        if(press == 1)
        {
            printf("dequeued \n");
            dequeue();
        }
        if(press == 2)
        {
            printf("Printing the elements of queue\n");
            print_queue_elements();
        }

        if(press == -1) break;

        printf("Press: ");
        scanf("%d", &press);
    }

    return 0;
}

void create()
{
    top1 = -1;
    top2 = -1;
}

void push1(int data)
{
    top1++;
    stack1[top1] = data;
}

int pop1()
{
    return(stack1[top1--]);
}

void push2(int data)
{
    top2++;
    stack2[top2] = data;
}

int pop2()
{
    return(stack2[top2--]);
}

void enqueue()
{
    int data;

    printf("Enter data into queue: ");
    scanf("%d", &data);
    push1(data);
    count++;
}

void dequeue()
{
    int i;

    for (i = 0;i <= count;i++)
    {
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++)
    {
        push1(pop2());
    }
}

void print_queue_elements()
{
    int i;
    for (i = 0;i <= top1; i++)
    {
        printf(" %d ", stack1[i]);
    }
    printf("\n");
}

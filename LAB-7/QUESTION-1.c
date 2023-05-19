//PRODUCER CONSUMER PROBLEM
#include<stdio.h> 
#include<stdlib.h>
int mutex = 1, full = 0, empty, x = 0;
int main()
{
    int n;
    printf("Enter the max size of the buffer  --> ");
    scanf("%d", &empty);
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("1.Producer\n2.Consumer\n3.Exit");
    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:    
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer full!!");
            break;
        case 2:    
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer empty!!");
            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}
int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return (++s);
}
void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("Producer produces the item %d", x);
    printf("\nBuffer size  --> %d", full);
    mutex = signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Consumer consumes item %d", x);
    printf("\nBuffer size  --> %d", full);
    x--;
    mutex = signal(mutex);
}
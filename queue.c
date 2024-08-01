#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int* arr;
    unsigned int capacity;
    unsigned int size;    
    unsigned int start;
    unsigned int end;
} Queue;

Queue* queueInitialize(int capacity)
{
    Queue* q = malloc(sizeof(Queue));
    if (q == NULL)
    {
        printf("Error allocating memory");
        exit(1);
    }
    q->arr = malloc(sizeof(int) * capacity);
    if (q->arr == NULL)
    {
        printf("Error allocating memory");
        exit(1);
    }
    q->capacity = capacity;
    q->size = 0;
    q->start = 0;
    q->end = 0;
    return q;
}
void defaultQueue(Queue* q)
{
    int i; 
    for (i = 0; i < q->capacity; i++)
        q->arr[i] = i;
    q->end = q->capacity - 1;
    q->size = q->capacity;
    q->start = 0;
}
void clearQueue(Queue* q)
{
    q->start = 0;
    q->end = 0;
    q->size = 0;
    int i;
    for(i = 0; i < q->capacity; i++)
        q->arr[i] = 0;
}
void printQueue(Queue *q)
{
    if (q->size == 0)
    {
        printf("No elements in queue to print\n");
        return;
    }
    int i;
    for (i = 0; i < q->size; i++)
        printf("%d ", q->arr[(i + q->start) % q->capacity]);
    printf("\n");
}
void enqueue(Queue* q, int value)
{
    if (q->size == q->capacity)
    {
        printf("Queue at max capacity, please dequeue some elements\n");
        return;
    }
    q->size++;
    q->arr[q->end] = value;
    q->end = (q->end + 1) % q->capacity; 
}
void dequeue(Queue* q)
{
    if (q->size == 0)
    {
        printf("Queue has no elements to dequeue\n");
        return;
    }
    q->size--;
    q->arr[q->start] = 0;
    q->start = (q->start + 1) % q->capacity; 
}
int main()
{
    Queue* q = queueInitialize(4);
    dequeue(q);
    defaultQueue(q);

    printQueue(q);
    clearQueue(q);
    printQueue(q);

    enqueue(q, 4); 
    enqueue(q, 18);  

    printQueue(q);

    enqueue(q, 4); 
    enqueue(q, 18);  

    printQueue(q);
    enqueue(q, 4); 
    
    dequeue(q);
    printQueue(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    printQueue(q);
    dequeue(q);
    printQueue(q);

    enqueue(q, 3); 
    enqueue(q, 4);  


    enqueue(q, 5); 
    enqueue(q, 6);
    printQueue(q);
    dequeue(q);
    enqueue(q,45);
    printQueue(q);
    clearQueue(q);
    
    enqueue(q,45);
    enqueue(q,45);
    enqueue(q,45);

    printf("=========================================\n");
    printQueue(q);
    int i;
    for (i = 0; i < 25; i++)
    {
        enqueue(q,i);
        printQueue(q);
        dequeue(q);
        printQueue(q);
    }
    free(q);
    return 0;
}

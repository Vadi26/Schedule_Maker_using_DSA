#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char classroom[20];
    char day[20];
    char start[20];
    char end[20];
} Request;

typedef struct que
{
        int size;
        int front, rear;
        Request arr[100];
}que;

void initQueue(que *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(que* q) {
    return (q->front == -1 && q->rear == -1);
}

int isQueueFull(que* q)
{
	return 	((q->rear + 1) % 100 == q->front);
}

void enqueue(que *q, Request req) 
{
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot enqueue more requests.\n");
        return;
    }

    if (isQueueEmpty(q))
        q->front = q->rear = 0;
    else
        q->rear = (q->rear + 1);
    q->arr[q->rear] = req;
}

Request dequeue(que *q) {
    Request emptyRequest;
    strcpy(emptyRequest.classroom, "");
    strcpy(emptyRequest.day, "");
    strcpy(emptyRequest.start, "");
    strcpy(emptyRequest.end, "");

    if (isQueueEmpty(q)) {
        printf("Queue is empty. No requests to dequeue.\n");
        return emptyRequest;
    }
    Request dequeuedRequest = q->arr[q->front];

    if (q->front == q->rear)
	    q->front = q->rear = -1;
    else 
        q->front = (q->front + 1) % 100;
    return dequeuedRequest;
}

void top(que* q)
{
	if (isQueueEmpty(q)) 
	{
        	printf("Queue is empty. No requests to display.\n");
        	return;
	}
	Request r= q->arr[q->front];
	printf("Classroom: %s, Day: %s, Start Time: %s, End Time: %s\n",r.classroom, r.day, r.start, r.end);
}

int main()
{
	que* q=(que*)malloc(sizeof(que));
	initQueue(q);

	Request math={"AC-101", "Monday", "10:00 AM", "12:00 PM"};
	enqueue(q, math);
	top(q);

	return 0;
}

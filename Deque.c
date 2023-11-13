
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int deque[max];
int front = -1, rear = -1;

void inputRestrictedEnqueue(int data) {
    if ((front == 0 && rear == max - 1) || front == rear + 1) {
        printf("Deque is full.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = max - 1;
    } else {
        front--;
    }
    deque[front] = data;
    printf("%d has been enqueued.\n", data);
}

void outputRestrictedEnqueue(int data) {
    if ((front == 0 && rear == max - 1) || front == rear + 1) {
        printf("Deque is full.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == max - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = data;
    printf("%d has been enqueued.\n", data);
}

void inputRestrictedDequeue() {
    if (front == -1) {
        printf("Deque is empty.\n");
        return;
    }
    printf("%d has been dequeued.\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == max - 1) {
        front = 0;
    } else {
        front++;
    }
}

void outputRestrictedDequeue() {
    if (front == -1) {
        printf("Deque is empty.\n");
        return;
    }
    printf("%d has been dequeued.\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = max - 1;
    } else {
        rear--;
    }
}

void peek() {
    if (front == -1) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Front element: %d\n", deque[front]);
    printf("Rear element: %d\n", deque[rear]);
}

void isEmpty() {
    if (front == -1) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque is not empty.\n");
    }
}

void isFull() {
    if ((front == 0 && rear == max - 1) || front == rear + 1) {
        printf("Deque is full.\n");
    } else {
        printf("Deque is not full.\n");
    }
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Input-restricted enqueue\n");
        printf("2. Output-restricted enqueue\n");
        printf("3. Input-restricted dequeue\n");
        printf("4. Output-restricted dequeue\n");
        printf("5. Peek\n");
        printf("6. Is empty?\n");
        printf("7. Is full?\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                inputRestrictedEnqueue(data);
                break;
            case 2:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                outputRestrictedEnqueue(data);
                break;
            case 3:
                inputRestrictedDequeue();
                break;
            case 4:
                outputRestrictedDequeue();
                break;
            case 5:
                peek();
                break;
            case 6:
                isEmpty();
                break;
            case 7:
                isFull();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

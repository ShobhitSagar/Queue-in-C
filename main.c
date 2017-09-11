//
//  main.c
//  Queue
//
//  Created by Shobhit Sagar on 11/09/17.
//  Copyright © 2017 Shobhit Sagar. All rights reserved.
//

#include <stdio.h>
#define MAX 5

int addq(int *, int, int *, int *);
int delq(int *, int *, int *);

int main() {
    
    int a[MAX];
    int front = -1, rear = -1,t=1;
    int i,j,x,y,w;
    
    printf("Enter the number of insertion\n");
    scanf("%d",&x);
    
    printf("Enter the Values\n");
    for (i = 0; i < x; i++) {
        if (t != 0) {
            scanf("%d",&w);
            t = addq(a, w, &front, &rear);
        }
        else
            break;
    }
    
    printf("Enter the number of deletion\n");
    scanf("%d",&y);
    
    for (j = 0; j < y; j++) {
        i = delq(a, &front, &rear);
        if (i != 0) {
            printf("Element Deleted = %d\n",i);
        }
        else
            break;
    }
    
    return 0;
}

int addq(int *a, int item, int *front, int *rear) {
    
    (*rear)++;
    a[*rear] = item;
    
    if(*rear == MAX-1) {
        printf("\nQueue is FULL\n\n");
        return 0;
    }
    
    if(*front == -1)
        *front=0;
    return 1;
}

int delq(int *a, int *front, int *rear) {
    int data;
    if (*front == -1) {
        printf("\nQueue is EMPTY\n\n");
        return 0;
    }
    data = a[*front];
    a[*front] = 0;
    if(*front == *rear)
        *front = *rear = -1;
    else
        (*front)++;
    return data;
}

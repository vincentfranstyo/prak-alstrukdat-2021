# include "circular_queue.h"
# include <stdio.h>

int main()  {
    Queue q;
    q = CreateQueue(100);
    q.HEAD = 86;
    q.TAIL = 99;
    ElType bf[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
    for (int i = 0; i < 100; i++)    {
        q.Tab[i] = bf[i];
    }
    printf("HEAD: %d\n", Front(q));
    printf("TAIL: %d\n", (q.Tab[q.TAIL]));
    //displayQueue(q);
    printf("length: %d\n", Length(q));
    printf("isEmpty: %d\n", IsEmpty(q));
    printf("isFull: %d\n", IsFull(q));
    Pop(&q);
    Push(&q, 100);
    printf("HEAD: %d\n", Front(q));
    printf("TAIL: %d\n", (q.Tab[q.TAIL]));

    int i = q.HEAD;
    while (i != q.TAIL){
        Pop(&q);
        printf("head : %d\n", q.HEAD);
        i = (i + 1) % q.MaxEl;
    }
    printf("length: %d\n", Length(q));
    printf("isEmpty: %d\n", IsEmpty(q));
    printf("HEAD: %d\n", Front(q));
    Pop(&q);
    printf("length: %d\n", Length(q));
    printf("isEmpty: %d\n", IsEmpty(q));
    printf("HEAD: %d\n", Front(q));
    //enqueue(&q, 999);
    //displayQueue(q);
    DeleteQueue(&q);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
    char *name;
};

void printPoints(struct point p[], int length) {
    int i = 0;
    for ( i = 0; i < length; i++) {
        printf("%d %d %s\n", p[i].x,  p[i].y, p[i].name);
    } 
}

void printPoints2(struct point * p, int length) {
    int i = 0;
    for ( i = 0; i < length; i++) {
        printf("%d %d %s\n", (p+i)->x,  (*(p+i)).y,  (p+i)->name);
    } 
}


int main()
{
    int N = 3;
    int i = 0;
    struct point p[N];
    printf("Enter %d points (x, y, name):\n", N);
    for ( i = 0; i < N; i++) { 
        p[i].name = (char *) malloc(80 * sizeof(char)); 
        scanf("%d%d%s", &p[i].x, &p[i].y, p[i].name);
    }
    printf("Your Points:\n");
    printPoints(p, N);
    
    struct point * q;
    printf("Enter %d points again (x, y, name):\n", N);
    q = (struct point *) malloc(N* sizeof(struct point)); // sizeof(struct point *) is not OK
    
    for ( i = 0; i < N; i++) { 
        (q+i)->name = (char *) malloc(80 * sizeof(char));
        scanf("%d%d%s", &(q+i)->x, &(q+i)->y, (q+i)->name);
    }
    printf("Your Points:\n");
    printPoints2(q, N);
    return 0;
}
#include <stdio.h>
#include <string.h>

struct point {
    int x;
    int y;
    char name[80];
};

void changePoint1(struct point p) {
    p.x = 20;
    p.y = 30;
    strcpy(p.name, "PointChanged");
}

void changePoint2(struct point *p) {
    p->x = 20;
    p->y = 30;
    strcpy(p->name, "PointChanged");
}

int main()
{
    struct point p1;
    p1.x = 10;
    p1.y = 15;
    strcpy(p1.name, "Point1");
    struct point * p;
    p = &p1;
    printf("%d %d %s\n", p1.x,  p1.y, p1.name); 
    printf("%d %d %s\n", p->x,  p->y, (*p).name);
    changePoint1(p1);   
    printf("%d %d %s\n", p1.x,  p1.y, p1.name);      
    changePoint2(p);
    printf("%d %d %s\n", p1.x,  p1.y, p1.name); 
    return 0;
}
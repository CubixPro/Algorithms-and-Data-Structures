#include <stdio.h>
#include <stdlib.h>

typedef struct point_tag{
    float x;
    float y;
    struct point_tag* next;
}point;

point* create(float x, float y){
    point* p = (point *)malloc(sizeof(point));

    p->x = x;
    p->y = y;
    p->next = NULL;

    return p;
}

void join(point* p1, point* p2){
    p1->next = p2;
}

int ret_sign(const point* P, const point* p1,const point* p2){
    float f = 0;
    /*f = (y-y1)(x2-x1) -(y2-y1)(x-x1)*/

    printf("(%f,%f)<---->(%f,%f)",p1->x,p1->y,p2->x,p2->y);
    f = (P->y - p1->y)*(p2->x - p1->x) - (P->x - p1->x)*(p2->y - p1->y);

    printf("---->%f\n\n", f);
    if(f>0) return 1;
    else if(f<0) return -1;
    else return 0;
}

int  check_if_inside(const point* P, point* P_head){
    int check_in = 1;
    point* prev = P_head;
    point* curr = P_head->next;

    if(prev == NULL || curr == NULL || curr->next == NULL ) return 1;
    do{
        check_in = check_in*ret_sign(P, prev, curr);
        prev = curr;
        curr = curr->next;
    }while(prev != P_head);

    return check_in;
}

point* form_polygon(int no_corners){
    point* prev = NULL;
    point* curr = NULL;
    point* head = NULL;

    float x, y;
    printf("Please enter the values in anti-clockwise direction :: \n");
    printf("Enter the values of x and y below :: \n");

    for(int i=0; i<no_corners; i++){
        scanf("%f",&x);
        scanf("%f",&y);
        if(head == NULL){
            head = create(x,y);
            prev = head;
        }
        else{
            curr = create(x,y);
            join(prev, curr);
            join(curr, head);
            prev = curr;
        }
    }

    return head;
}

void display(point* head){
    printf("(%0.2f,%0.2f)",head->x, head->y);

    point* temp = head->next;

    while(temp!= NULL && temp != head){
        printf("<----->");
        printf("(%0.2f,%0.2f)",temp->x, temp->y);
        temp = temp->next;
    }
    printf("\n\n");
    return;
}

int main(){
    int no_corners;
    printf("Enter the number of corners for polygon P1 :: ");
    scanf("%d", &no_corners);

    point* Poly1 = form_polygon(no_corners);
    display(Poly1);

    printf("Enter the number of corners for polygon P2 :: ");
    scanf("%d", &no_corners);

    point* Poly2 = form_polygon(no_corners);
    display(Poly2);

    point *Poly2_p = Poly2;

    do{
        int present_where = check_if_inside(Poly2_p,Poly1);
        if(present_where == -1) printf("Present inside :: (%f,%f)\n",Poly2_p->x,Poly2_p->y);
        else if (present_where == 0) printf("Present on :: (%f,%f)\n",Poly2_p->x,Poly2_p->y);
        else printf("Present outside :: (%f,%f)\n",Poly2_p->x,Poly2_p->y);

        Poly2_p = Poly2_p->next;
    }while(Poly2_p != Poly2);
}
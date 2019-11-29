#include<stdio.h>
typedef struct {
    int coeff[10000];
    int power[10000];
    int begin[100];
    int end[100];
    int count;
}polynomials;

void print_one(polynomials poly, int i)
{
    if(i < poly.count)
    {
        for(int j = poly.begin[i] ; j < poly.end[i] ; j++)
        {
            printf("%dx^%d + ", poly.coeff[j], poly.power[j]);
        }
        printf("%dx^%d\n", poly.coeff[poly.end[i]], poly.power[poly.end[i]]);
    }
    else
    {
        printf("Polynomial doesn't exist\n");
    }
    
}
void input(polynomials *poly)
{
    printf("Enter -1 to stop entering polynomials, 0 to enter a new polynomial. Enter polynomials in decreasing power\n");
    int ch;
    scanf("%d", &ch);
    while(ch != -1)
    {
        switch(ch)
        {
            case 0:{
                printf("Enter the terms you want : ");
                int terms ;
                scanf("%d", &terms);
                for(int i = poly->begin[poly->count]; i < poly->begin[poly->count] + terms ; i++)
                {
                    printf("coeff : ");
                    scanf("%d", &(poly->coeff[i]));
                    printf("Power : ");
                    scanf("%d", &(poly->power[i]));
                }
                poly->end[poly->count] = poly->begin[poly->count] + terms - 1;
                poly->count++;
                poly->begin[poly->count] = poly->end[poly->count - 1] + 1;
            }
            default : break;
        }
        printf("Enter -1 to stop entering polynomials, 0 to enter a new polynomial. Enter polynomials in decreasing power\n");
        
        scanf("%d", &ch);
    }
}

void print_all(polynomials poly)
{
    for(int i = 0 ; i < poly.count ; i++)
    {
        for(int j = poly.begin[i] ; j < poly.end[i] ; j++)
        {
            printf("%dx^%d + ", poly.coeff[j], poly.power[j]);
        }
        printf("%dx^%d\n", poly.coeff[poly.end[i]], poly.power[poly.end[i]]);

    }
}
int degree(polynomials poly, int i)
{
   // printf("Degree of polynomial %d : %d\n", coeff[begin[i - 1]]);
   return poly.coeff[poly.begin[i - 1]];
}
void add(polynomials* poly, int i, int j)
{
    int a = poly->begin[i];
    int b = poly->begin[j];
    int k = 0;
    while(a <= poly->end[i] && b <= poly->end[j])
    {
        if(poly->power[a] > poly->power[b])
        {
            poly->coeff[poly->begin[poly->count]+k] = poly->coeff[a];
            poly->power[poly->begin[poly->count]+k] = poly->power[a];
            k++;
            a++;
        }
        else if(poly->power[b] > poly->power[a])
        {
            poly->coeff[poly->begin[poly->count]+k] = poly->coeff[b];
            poly->power[poly->begin[poly->count]+k] = poly->power[b];
            k++;
            b++;
        }
        else
        {
            poly->coeff[poly->begin[poly->count]+k] = poly->coeff[a] + poly->coeff[b];
            poly->power[poly->begin[poly->count]+k] = poly->power[a];
            k++;
            a++;
            b++;
        }
    }
    for(; a <= poly->end[i] ; a++)
    {
        poly->coeff[poly->begin[poly->count]+k] = poly->coeff[a];
            poly->power[poly->begin[poly->count]+k] = poly->power[a];
            k++;
           
    }
    for(; b <= poly->end[j] ; b++)
    {
        poly->coeff[poly->begin[poly->count]+k] = poly->coeff[b];
            poly->power[poly->begin[poly->count]+k] = poly->power[b];
            k++;
    }

    poly->end[poly->count] = poly->begin[poly->count] + k - 1;
    poly->count ++;
    poly->begin[poly->count] = poly->end[poly->count - 1] + 1;


}

void delete_poly(polynomials* poly, int i)
{
    int start_val = poly->begin[i];
    int start = i;
    for(int k = i + 1 ; k < poly->count ; k++)
    {
        for(int l = poly->begin[k] ; l <= poly->end[k] ; l++)
        {
            poly->coeff[start_val] = poly->coeff[l];
            poly->power[start_val] = poly->power[l];
            start_val ++;
        }
        poly->end[start] = poly->begin[start] + poly->end[k] - poly->begin[k];
        start++;
        poly->begin[start] = poly->end[start - 1] + 1;
           
    }
        poly->count--;

}
void multiply(polynomials* poly, int i, int j)
{
    int val = poly->begin[poly->count];
    for(int k = poly->begin[i] ; k <= poly->end[i] ; k++)
    {
        poly->power[val] = poly->power[poly->begin[j]] + poly->power[k];
        poly->coeff[val] = poly->coeff[poly->begin[j]] * poly->coeff[k];
        val++;
    }
    poly->end[poly->count] = val - 1;
    poly->count++;
    poly->begin[poly->count] = poly->end[poly->count - 1] + 1;
    for(int l = poly->begin[j] + 1 ; l <= poly->end[j] ; l++)
    {
        val = poly->begin[poly->count];//goes to line 144 as well
        for(int k = poly->begin[i] ; k <= poly->end[i] ; k++)
        {
            poly->power[val] = poly->power[k] + poly->power[l];
            poly->coeff[val] = poly->coeff[k] * poly->coeff[l];
            val++;
        }
    poly->end[poly->count] = val - 1;
    poly->count++;
    poly->begin[poly->count] = poly->end[poly->count - 1] + 1;
    add(poly, poly->count - 1, poly->count - 2);
    delete_poly(poly, poly->count - 2);
    delete_poly(poly, poly->count - 2);
    }
    print_all(*poly);
}
int main()
{
    printf("Maximum number of terms is 10000\n");
    printf("Maximum number of polynomials is 100\n");
    polynomials poly;
    poly.begin[0] = 0;
    poly.count = 0;
    input(&poly);
    print_all(poly);
    printf("------------\n");
    /*add(&poly, 0, 1);
    print_all(poly);
    printf("-------------\n");
    delete_poly(&poly, 1);
    print_all(poly);
    printf("------------\n");
    multiply(&poly, 0, 1);
    //printf("hi\n");
    */
   printf(" 1. Add any two polynomials \n 2. Multiply any two polynomials \n 3. Delete any two polynomials \n 4. Print all the polynomials \n 5. Print a particular polynomial(0 based indexing)\n");
   int choice;
   scanf("%d", &choice);
   while(choice != -1)
   {
    switch(choice)
    {
        case 1 :
        {
            int i, j;
            printf("Enter the polynomials to be added : ");
            scanf("%d %d", &i, &j);
            add(&poly, i, j);
            break;
        } 
        case 2 :
        {
            int i, j;
            printf("Enter the polynomials to be multiplied : ");
            scanf("%d %d", &i, &j);
            multiply(&poly, i, j);
            break;
        }
        case 3 :
        {
            int i;
            printf("Enter the polynomial to be deleted : ");
            scanf("%d", &i);
            delete_poly(&poly, i);
            break;
        }
        case 4 :
        {
            print_all(poly);
            break;
        }
        case 5 :
        {
            int i;
         printf("Enter the polynomial to be printed : ");
            scanf("%d", &i);
            print_one(poly, i);
            //printf("i");
            break;

        }
        case -1 :
        {
            printf("Bye :( \n");
            break;
        }
        default : printf("You're being dumb \n");

    }
   printf(" 1. Add any two polynomials \n 2. Multiply any two polynomials \n 3. Delete any two polynomials \n 4. Print all the polynomials \n 5. Print a particular polynomial(0 based indexing)\n");
   scanf("%d", &choice);

   } 
    printf("Bye :( \n");
}
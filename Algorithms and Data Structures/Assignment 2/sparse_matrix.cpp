#include<stdio.h>
#include<stdlib.h>
#define size 100
typedef struct {
    int data[size][3];
    int r, c;
    int len;
}matrix;


void input_deets(matrix* mat)
{
    scanf("%d %d", &mat->r, &mat->c);
    mat->len = 0;
}

void init_mat(matrix *mat, int ro, int co)
{
   mat->r = ro;
   mat->c = co; 
   mat->len = 0;
}

void insert(matrix *mat, int i, int j, int val)
{
    mat->data[mat->len][0] = i;
    mat->data[mat->len][1] = j;
    mat->data[mat->len][2] = val;
    mat->len++;
}

void print(matrix mat)
{
    printf("Dimensions : %d %d\n", mat.r, mat.c);
    for(int i = 0 ; i < mat.len ; i++)
    {
        printf("%d %d %d\n", mat.data[i][0], mat.data[i][1], mat.data[i][2]);
    }
}

void add(const matrix a, const matrix b)
{
        if (a.r != b.r || a.c != b.c) { 
            printf("Matrices can't be added"); 
            
        } 
  
        else { 
  
            int apos = 0, bpos = 0; 
            matrix result ;
            result.r = a.r;
            result.c = b.c;
            result.len = 0;
  
            while (apos < a.len && bpos < b.len) { 
  
                // if b's row and col is smaller 
                if (a.data[apos][0] > b.data[bpos][0] ||  
                  (a.data[apos][0] == b.data[bpos][0] &&  
                   a.data[apos][1] > b.data[bpos][1])) 
  
                { 
  
                    // insert smaller value into result 
                    insert(&result, b.data[bpos][0], 
                                  b.data[bpos][1], 
                                  b.data[bpos][2]); 
  
                    bpos++; 
                } 
  
                // if a's row and col is smaller 
                else if (a.data[apos][0] < b.data[bpos][0] ||  
                (a.data[apos][0] == b.data[bpos][0] &&  
                  a.data[apos][1] < b.data[bpos][1])) 
  
                { 
  
                    // insert smaller value into result 
                    insert(&result, a.data[apos][0], 
                                  a.data[apos][1], 
                                  a.data[apos][2]); 
  
                    apos++; 
                } 
  
                else { 
  
                    // add the values as row and col is same 
                    int addedval = a.data[apos][2] + b.data[bpos][2]; 
  
                    if (addedval != 0) 
                        insert(&result, a.data[apos][0], 
                                      a.data[apos][1], 
                                      addedval); 
                    // then insert 
                    apos++; 
                    bpos++; 
                } 
            } 
  
            // insert remaining elements 
            while (apos < a.len) 
                insert(&result, a.data[apos][0], 
                              a.data[apos][1], 
                              a.data[apos++][2]); 
  
            while (bpos < b.len) 
                insert(&result, b.data[bpos][0], 
                              b.data[bpos][1], 
                              b.data[bpos++][2]); 
  
            // print result 
            
            print(result); 
        }  
}

matrix  transpose(matrix a) 
{ 
  
        // new matrix with inversed row X col 
        matrix result;
  
        // same number of elements 
        result.len = a.len; 
        result.r = a.c;
        result.c = a.r;
  
        // to count number of elements in each column 
        int count[a.c + 1]; 
  
        // initialize all to 0 
        for (int i = 1; i <= a.c; i++) 
            count[i] = 0; 
  
        for (int i = 0; i < a.len; i++) 
            count[a.data[i][1]]++; 
  
        int index[a.c + 1]; 
  
        // to count number of elements having col smaller 
        // than particular i 
  
        // as there is no col with value < 1 
        index[1] = 0; 
  
        // initialize rest of the indices 
        for (int i = 2; i <= a.c; i++) 
  
            index[i] = index[i - 1] + count[i - 1]; 
  
        for (int i = 0; i < a.len; i++) { 
  
            // insert a data at rpos and increment its value 
            int rpos = index[a.data[i][1]]++; 
  
            // transpose row=col 
            result.data[rpos][0] = a.data[i][1]; 
  
            // transpose col=row 
            result.data[rpos][1] = a.data[i][0]; 
  
            // same value 
            result.data[rpos][2] = a.data[i][2]; 
        } 
  
        // the above method ensures 
        // sorting of transpose matrix 
        // according to row-col value 
        return result; 
} 

 void multiply(matrix a, matrix c) 
    { 
  
        if (a.c != c.r) { 
  
            // Invalid multiplication 
            printf("Can't multiply, Invalid dimensions"); 
  
            return; 
        } 
  
        // transpose b to compare row 
        // and col values and to add them at the end 
        matrix b = transpose(c); 
        int apos, bpos; 
  
        // result matrix of dimension row X b.col 
        // however b has been transposed, hence row X b.row 
        matrix result ;
        init_mat(&result, a.r, b.r); 
  
        // iterate over all elements of A 
        for (apos = 0; apos < a.len;) { 
  
            // current row of result matrix 
            int r = a.data[apos][0]; 
  
            // iterate over all elements of B 
            for (bpos = 0; bpos < b.len;) { 
  
                // current column of result matrix 
                // data[][0] used as b is transposed 
                int c = b.data[bpos][0]; 
  
                // temporary pointers created to add all 
                // multiplied values to obtain current 
                // element of result matrix 
                int tempa = apos; 
                int tempb = bpos; 
  
                int sum = 0; 
  
                // iterate over all elements with 
                // same row and col value 
                // to calculate result[r] 
                while (tempa < a.len && a.data[tempa][0] == r 
                       && tempb < b.len && b.data[tempb][0] == c) { 
  
                    if (a.data[tempa][1] < b.data[tempb][1]) 
  
                        // skip a 
                        tempa++; 
  
                    else if (a.data[tempa][1] > b.data[tempb][1]) 
  
                        // skip b 
                        tempb++; 
                    else
  
                        // same col, so multiply and increment 
                        sum += a.data[tempa++][2] * b.data[tempb++][2]; 
                } 
  
                // insert sum obtained in result[r] 
                // if its not equal to 0 
                if (sum != 0) 
                    insert(&result, r, c, sum); 
  
                while (bpos < b.len && b.data[bpos][0] == c) 
  
                    // jump to next column 
                    bpos++; 
            } 
  
            while (apos < a.len && a.data[apos][0] == r) 
  
                // jump to next row 
                apos++; 
        } 
  
        print(result); 
    } 

int main()
{
    matrix a1, a2;
    matrix *a3;
    input_deets(&a1);
    input_deets(&a2);
        insert(&a1, 1, 2, 10); 
        insert(&a1, 1, 4, 12); 
        insert(&a1, 3, 3, 5); 
        insert(&a1, 4, 1, 15); 
        insert(&a1, 4, 2, 12); 
        insert(&a2, 1, 3, 8); 
        insert(&a2, 2, 4, 23); 
        insert(&a2, 3, 3, 9); 
        insert(&a2, 4, 1, 20); 
        insert(&a2, 4, 2, 25); 
        add(a1, a2);
        print(transpose(a1));
        multiply(a1, a2);
}

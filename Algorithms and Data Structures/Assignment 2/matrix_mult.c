#include <stdio.h>
#include <stdlib.h>

#define B_MAT_N 10
#define S_MAT_N 3


int out_of_range(int i){
    if(i<0 || i>B_MAT_N) return 1;
    else return 0;    
}

void multiply(int mat[B_MAT_N][B_MAT_N], int sub_m[S_MAT_N][S_MAT_N], int out[B_MAT_N][B_MAT_N]){
    int s_mat_mid = (S_MAT_N-1)/2;
    
    for(int row=0; row<B_MAT_N; row++){
        for(int col=0; col<B_MAT_N; col++){
            int val = 0;
            for(int s_col=0; s_col<S_MAT_N;s_col++){
                int r_index = row-s_mat_mid+s_col;
                if(!out_of_range(r_index))
                    val = val+mat[r_index][col]*sub_m[s_mat_mid][s_col];
            }
            out[row][col] = val;
        }        
    }
}

int main(){
    
    int mat[B_MAT_N][B_MAT_N];
    int sub_m[S_MAT_N][S_MAT_N];
    
    for(int row=0; row<S_MAT_N; row++){
        for(int col=0; col<S_MAT_N; col++){
            sub_m[row][col] = rand()%10;
            printf("%d ", sub_m[row][col]);
        }
        printf("\n");
    }
    
    for(int row=0; row<B_MAT_N; row++){
        for(int col=0; col<B_MAT_N; col++){
            mat[row][col] = rand()%10;
            printf("%d ", mat[row][col]);
        }
        printf("\n");
    }
    
    int out[B_MAT_N][B_MAT_N] = {0};
    
    multiply(mat, sub_m, out);
    
    for(int row=0; row<B_MAT_N; row++){
        for(int col=0; col<B_MAT_N; col++){
           printf("%d  ",out[row][col]);
        }
        printf("\n");
    }
    
    return 0;
}   

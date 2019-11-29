#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
    if(a>b)
        return b;
    return a;
}
int max(int a,int b)
{
    if(a<b)
        return b;
    return a;
}
int get_size()
{
    int n;
    printf("Enter the size of data: ");
    scanf("%d",&n);
    return n;
}
int **allocate_357(int n,int s)
{
    int **temp=(int **)malloc(n*sizeof(int *));
    int i=0;
    for(i=0;i<n;i++)
        temp[i]=(int *)malloc(s*sizeof(int));
    return temp;
}
int *allocate(int n)
{
    int *temp=(int *)malloc(n*sizeof(int));
    return temp;
}
void get_data(int ar[],int n)
{
    int i=0;
    printf("Enter your data: ");
    for(i=0;i<n;i++)
        scanf("%d",ar+i);
}
void get_value_3(int ar[],int array[],int n)
{
    int i=0;
    //for average i.e. mean
    for(i=0;i<n;i++)
    {
        int sum=0,x=0;
        while((x+i)<n&&x<3)
        {
            sum+=ar[i+x];
            x++;
        }
        array[i*4+0]=sum/x;
    }
    //for median
    for (i=0; i<n; i++) {
        array[i*4+1]=ar[(i+min(i+2,n-1))/2];
    }
    //for maximum and minimum
    for(i=0;i<n;i++)
    {
        int temp=ar[i],temp1=ar[i],j=0;
        for(j=i;j<min(i+3,n);j++)
            temp=max(temp,ar[j]);
        array[i*4+2]=temp;
        for (j=i; j<min(i+3,n); j++)
            temp1=min(temp1,ar[j]);
        array[i*4+3]=temp1;
    }
}
void get_value_5(int ar[],int array[],int n)
{
    int i=0;
    //for average i.e. mean
    for(i=0;i<n;i++)
    {
        int sum=0,x=0;
        while((x+i)<n&&x<5)
        {
            sum+=ar[i+x];
            x++;
        }
        array[i*4+0]=sum/x;
    }
    //for median
    for (i=0; i<n; i++) {
        array[i*4+1]=ar[(i+min(i+4,n-1))/2];
    }
    //for maximum and minimum
    for(i=0;i<n;i++)
    {
        int temp=ar[i],temp1=ar[i],j=0;
        for(j=i;j<min(i+5,n);j++)
            temp=max(temp,ar[j]);
        array[i*4+2]=temp;
        for (j=i; j<min(i+5,n); j++)
            temp1=min(temp1,ar[j]);
        array[i*4+3]=temp1;
    }
}
void get_value_7(int ar[],int array[],int n)
{
    int i=0;
    //for average i.e. mean
    for(i=0;i<n;i++)
    {
        int sum=0,x=0;
        while((x+i)<n&&x<7)
        {
            sum+=ar[i+x];
            x++;
        }
        array[i*4+0]=sum/x;
    }
    //for median
    for (i=0; i<n; i++) {
        array[i*4+1]=ar[(i+min(i+6,n-1))/2];
    }
    //for maximum and minimum
    for(i=0;i<n;i++)
    {
        int temp=ar[i],temp1=ar[i],j=0;
        for(j=i;j<min(i+7,n);j++)
            temp=max(temp,ar[j]);
        array[i*4+2]=temp;
        for (j=i; j<min(i+7,n); j++)
            temp1=min(temp1,ar[j]);
        array[i*4+3]=temp1;
    }
}
void print_data(int s,int *array,int n)
{
    printf("Data for window filter for size %d \n",s);
    printf("S.no.     MEAN     MEDIAN     MAXIMUM       MINIMUM \n");
    int i=0;
    for (i=0; i<n; i++) {
        printf("%d        %d           %d           %d          %d\n",i+1,*(array+i*4+0),*(array+i*4+1),*(array+i*4+2),*(array+i*4+3));
    }
}
void form_window_filter()
{
    int n=get_size();
    int *array=allocate(n);
    get_data(array,n);
    int **array_3=allocate_357(n,4);
    int **array_5=allocate_357(n,4);
    int **array_7=allocate_357(n,4);
    get_value_3(array,array_3[0],n);
    get_value_5(array,array_5[0],n);
    get_value_7(array,array_7[0],n);
    print_data(3,array_3[0],n);
    print_data(5,array_5[0],n);
    print_data(7,array_7[0],n);
}
int main()
{
    form_window_filter();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void countsort(int arr[], int arrsize, int curplace)
{
    int finarr[arrsize];
    //count array of size 10 is initialized as we only sort one digit here, that is digit by digit starting from one end of the number
    int count[10];
    int i;
    for(i=0;i<10;i++)
    {
        //initializing all elements of the count array to 0
        count[i]=0;
    }
    for(i=0;i<arrsize;i++)
    {
        //initializing all elements of the final array to 0
        finarr[i]=0;
    }
    for(i=0;i<arrsize;i++)
    {
        //incrementing those places where element of original array is present
        count[(arr[i]/curplace)%10] = count[(arr[i]/curplace)%10]+1;
    }
    for(i=1;i<10;i++)
    {
        //for each element of count array, we add it to value of previous index
        count[i] = count[i] + count[i-1];
    }
    for(i=arrsize-1;i>=0;i--)
    {
        //copying the element into final array and decrementing its count in the count array
        finarr[count[(arr[i]/curplace)%10] - 1] = arr[i];
        count[(arr[i]/curplace)%10] = count[(arr[i]/curplace)%10] - 1;
    }
    for(i=0;i<arrsize;i++)
    {
        //copying the sorted array into initial array
        arr[i] = finarr[i];
    }
}
void radixsort(int arr[], int arrsize, int ndigits)
{

    //calling counting sort on each digit of the input numbers
    for(int i=1; i<=pow(10,ndigits) ; i*=10)
    {
        countsort(arr,arrsize,i);
    }
}
int main(int argc, char *argv[])
{
    //opening the input file
    FILE *fp = fopen(argv[1],"r");
    if(fp == NULL)
    {
        printf("Could not read input from input file\n");
    }
    else
    {
        int *p = (int*)malloc(sizeof(int));
        int count=0;
        int input=0;
        int ndigits = atoi(argv[2]);
        //reading file from input
        while(fscanf(fp,"%d",&input)!=EOF)
        {
            p = (int*)realloc(p,(count+1)*sizeof(int));
            p[count] = input;
            count++;
        }
        //calling radix sort function on the dynamic array space we created
        radixsort(p,count,ndigits);
        //printing output into radix.txt file
        FILE *fp2 = fopen("radix.txt","w");
        if(fp2==NULL)
        {
            printf("Could not write to the output file\n");
        }
        else
        {
            for(int i=0;i<count-1;i++)
            {
                fprintf(fp2,"%d\n",p[i]);
            }
            fprintf(fp2,"%d",p[count-1]);
        }
        fclose(fp);
        fclose(fp2);

    }
    return 0;
}

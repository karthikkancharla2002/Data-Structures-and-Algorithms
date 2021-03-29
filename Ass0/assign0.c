#include <stdio.h>

int main(int argc, char *argv[])
{
    int count = 0;
    int input;
    long long int sum=0;
    int max=0,min=0;
    float avg;
    FILE *fp,*fp2;

    fp = fopen(argv[1],"r");
    if(fp == NULL)
    {
        fprintf(stderr,"Can't open the specified input file");

    }
    else{
    while(scanf("%d",&input)!= EOF)
    {
        if(count ==0)
        {
            max = input;
            min = input;
        }
        sum += input;
        count++;
        if (input>max)
        {
            max = input;
        }
        if(input < min)
        {
            min = input;
        }
    }
    }

    avg = sum/count;



    fp2 = fopen("output.txt","w");
    if(fp2 == NULL)
    {
        fprintf(stderr,"Can't write in the specified output file");

    }
    else
    {
        fprintf(fp2, "%d\n",count);
        fprintf(fp2, "%d\n",min);
        fprintf(fp2, "%d\n",max);
        fprintf(fp2, "%lld\n",sum);
    }
    fclose(fp);

    fclose(fp2);
}

#include <stdio.h>
int main(int argc,char *argv[])
{
    FILE *fp = fopen(argv[1],"r");
    if(fp == NULL)
    {
        printf("Could not read input from input file\n");
    }
    else{
        int input=0;
        int count=0;
        int min = 0;
        int max = 0;
        long long int sum = 0;
        while(fscanf(fp,"%d",&input)!=EOF)
        {
            if(count ==0)
        {
            max = input;
            min = input;
        }
            count++;
            sum+=input;
            if(input<min)
            {
                min=input;
            }
            if(input>max)
            {
                max=input;
            }
        }
        float avg = sum/((double)count);
        FILE *fp2 = fopen("output.txt","w");
        if(fp2==NULL)
        {
            printf("Could not write to the output file\n");
        }
        else{
            fprintf(fp2,"%d\n",count);
            fprintf(fp2,"%d\n",min);
            fprintf(fp2,"%d\n",max);
            fprintf(fp2,"%lld\n",sum);
            fprintf(fp2,"%.2f\n",avg);

        }
        fclose(fp);
        fclose(fp2);
    }

}


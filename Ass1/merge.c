#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r)
{
    //This function takes an array, and takes the left most(l), middle(m) and right(r) most indices of the array.
    //Then this function copies two halves of the given array into two separate arrays.
    // Then it does something called two finger algorithm.
    // It then compares starting elements of both the sub arrays and then copies the smallest into the original array until the completion of the comparing all the elements of both the sub arrays.
    //First sub array is from index l to m, second sub array is from index m+1 to r.
	int i, j, k;
	int s1 = m - l + 1;
	int s2 = r - m;

	int L[s1], R[s2];

	for (i = 0; i < s1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < s2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < s1 && j < s2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

    //Here we copy the remaining elements of both sub arrays if left.
	while (i < s1) {
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < s2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergesort(int arr[], int left, int right)
{
    //This function sorts 2 halves separately and gives our final sorted array using two finger algorithm.
	if (left < right) {
        //left and right are indices of the array from and to the places where the array has to be sorted.
		int middle = left + (right - left) / 2;
    //middle stores the middle index of the array

		// Sorting both the halves of the array separately and then joining them using the merge function which joins 2 different sorted arrays by comparing their first elements and then so on.
		mergesort(arr, left, middle);
		mergesort(arr, middle + 1, right);

		merge(arr, left, middle, right);
	}
}
int main(int argc, char *argv[])
{
    // Here in this file i used the term array at some places where i have allocated the memory dynamically, which is similar to an array for using in this file.
    //opening the input file for taking the input
    FILE *fp = fopen(argv[1],"r");
    if(fp == NULL)
    {
        printf("Could not read input from input file\n");
    }
    else
    {
        //allocating memory for storing the data from file
        int *p = (int*)malloc(sizeof(int));

        int input=0;
        int count=0;
        //count stores the number of elements in the file
        while(fscanf(fp,"%d",&input)!=EOF)
        {
            //storing all elements in the file dynamically

            p =(int*)realloc(p,(count+1)*sizeof(int));
            p[count]=input;
            //arr[count]=input;
            count++;

        }
        //calling the merge sort function on the array(space) which has stored our elements upto the number of elements(count)
        mergesort(p, 0, count - 1);
        //printing array(space) into a new file after sorting in separate lines
        FILE *fp2 = fopen("mergesort.txt","w");
        if(fp2==NULL)
        {
            printf("Could not write to the output file\n");
        }
        else
        {
            for(int j=0;j<count-1;j++)
            {
                fprintf(fp2,"%d\n",p[j]);
            }
            fprintf(fp2,"%d",p[count-1]);
        }
        //closing the opened files
        fclose(fp);
        fclose(fp2);
    }
	return 0;
}

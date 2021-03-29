#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};
struct node* newnode(int number)
{
    // This creates a new node with a given integer
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = number;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}
void predecessor(FILE *fp2,struct node* node,int pred,int number,int count)
{
    if(node == NULL)
    {

        return;
    }
    if(count==0)
    {
        pred = node->data;
        count++;
    }

    if(count!=0 && node->data == number)
    {
        fprintf(fp2,"%d\n",pred);
    }
    predecessor(fp2,node->left,pred,number,count);

    predecessor(fp2,node->right,pred,number,count);

}
void successor(FILE *fp2,struct node* node,int* check,int number)
{
    if(node == NULL)
    {

        return;
    }



    successor(fp2,node->left,check,number);

    if(*check==1)
    {
        fprintf(fp2,"%d\n", node->data);
        return;
    }
    if(node->data == number)
    {
        *check = 1;
    }
    successor(fp2,node->right,check,number);
}
struct node* searchnode(struct node* node, int number)
{
    if(node == NULL || node->data == number)
    {
        return node;
    }
    if(node->data < number)
    {
        return searchnode(node->right,number);
    }
    else if(node->data >number)
    {
        return searchnode(node->left,number);
    }
}


struct node* insert(FILE *fp2,struct node* node, int number)
{
    // This inserts a node into the binary tree given a new integer.
    if(node==NULL)
    {
        fprintf(fp2,"%d inserted\n",number);
        return newnode(number);
    }
    struct node* temp;
    if(number<(node->data))
    {
        temp = insert(fp2,node->left,number);
        node->left = temp;
        temp->parent = node;
    }
    else if(number > node->data)
    {
        temp = insert(fp2,node->right,number);
        node->right = temp;
        temp->parent = node;
    }
    return node;
}
void min_bst(FILE *fp2,struct node* node)
{
    // This prints the minimum element of the bst.
    if(node == NULL)
    {
        fprintf(fp2,"\n");
        return;
    }
    else
    {
    struct node* min_node = node;
    while(min_node->left != NULL)
    {
        min_node = min_node->left;
    }
    fprintf(fp2,"%d\n",min_node->data);
    return;
    }
}
void max_bst(FILE *fp2,struct node* node)
{
    // This prints the maximum element of the bst.
    if(node == NULL)
    {
        fprintf(fp2,"\n");
        return;
    }
    else
    {
    struct node* max_node = node;
    while(max_node->right!=NULL)
    {
        max_node = max_node->right;
    }
    fprintf(fp2,"%d\n",max_node->data);
    return;
    }
}

int search(FILE *fp2,struct node* node, int number)
{
    // This gives output as 1 if number is found else output is zero
    if(node == NULL)
    {
        return 0;
    }
    if(node->data == number)
    {
        return 1;
    }
    if(number < (node->data))
    {
        return search(fp2,node->left,number);
    }
    else
    {
        return search(fp2,node->right,number);
    }
}
void preorder_traversal(FILE *fp2,struct node* node,int rootdata)
{
    // This prints the preorder traversal of the binary search tree
    if(node == NULL)
    {

        return;
    }
    if(node->data == rootdata)
    {
        fprintf(fp2,"%d",node->data);
    }
    else
    {
        fprintf(fp2," %d",node->data);
    }

    preorder_traversal(fp2,node->left,rootdata);
    preorder_traversal(fp2,node->right,rootdata);
}
struct node* minnode(struct node* node)
{
    struct node* temp = node;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
void inorder_traversal(FILE *fp2,struct node* node,int min)
{
    //This prints the inorder traversal of the binary search tree
    if(node == NULL)
    {

        return;
    }

    inorder_traversal(fp2,node->left,min);
    if(node->data == min)
    {
        fprintf(fp2,"%d", node->data);

    }
    else
    {
        fprintf(fp2," %d", node->data);
    }
    inorder_traversal(fp2,node->right,min);

}
void postorder_traversal(FILE *fp2,struct node* node,int rdata)
{
    //This prints the post order traversal of the bst
    if(node == NULL)
    {

        return;
    }
    postorder_traversal(fp2,node->left,rdata);
    postorder_traversal(fp2,node->right,rdata);
    if(node->data == rdata)
    {
        fprintf(fp2,"%d",node->data);
    }
    else
    {
        fprintf(fp2,"%d ",node->data);
    }


}
int main(int argc, char *argv[])
{
    //Taking input
    FILE *fp = fopen("input1.txt","r");
    int n,s;
    char str[20];
    char st[5];
    int icount=0;
    if(fp == NULL)
    {
        printf("Could not read input from input file\n");
    }
    else
    {
        //Writing into output file
        FILE *fp2 = fopen("bstf.txt","w");
        if(fp2==NULL)
        {
            printf("Could not write to the output file\n");
        }
        else
        {
            struct node* node = NULL;
            while(fscanf(fp,"%s",str)!=EOF)
            {
                //This prints the necesaary output based on the input
                if(strcmp(str,"insert")==0)
                {
                    fscanf(fp,"%s",str);
                    n = atoi(str);
                    if(icount==0)
                    {
                        icount++;
                        node = insert(fp2,node,n);

                    }
                    else
                    {
                        insert(fp2,node,n);
                    }
                }
                if(strcmp(str,"preorder")==0)
                {
                    if(node==NULL)
                    {
                        fprintf(fp2,"\n");
                    }
                    else
                    {
                        int rootdata = node->data;
                        preorder_traversal(fp2,node,rootdata);
                        fprintf(fp2,"\n");

                    }
                }
                if(strcmp(str,"postorder")==0)
                {
                    if(node==NULL)
                    {
                        fprintf(fp2,"\n");
                    }
                    else
                    {
                        int rdata = node->data;
                        postorder_traversal(fp2,node,rdata);
                        fprintf(fp2,"\n");

                    }
                }
                if(strcmp(str,"inorder")==0)
                {
                    if(node==NULL)
                    {
                        fprintf(fp2,"\n");
                    }
                    else
                    {
                        struct node* tempin = minnode(node);
                        int min = tempin->data;
                        inorder_traversal(fp2,node,min);
                        fprintf(fp2,"\n");

                    }
                }
                if(strcmp(str,"search")==0)
                {
                    fscanf(fp,"%s",str);
                        n = atoi(str);
                    if(node == NULL)
                        {
                            fprintf(fp2,"%d not found\n",n);

                        }
                    else
                    {

                        s = search(fp2,node,n);
                        if(s==0)
                        {
                            fprintf(fp2,"%d not found\n",n);
                        }
                        else if(s==1)
                        {
                            fprintf(fp2,"%d found\n",n);
                        }
                    }
                }
                if(strcmp(str,"minimum")==0)
                {
                    min_bst(fp2,node);
                }
                if(strcmp(str,"maximum")==0)
                {
                    max_bst(fp2,node);
                }
                if(strcmp(str,"successor")==0)
                {
                    fscanf(fp,"%s",str);
                    n = atoi(str);
                    if(search(fp2,node,n)==1)
                    {
                        int check;
                        check = 0;
                        successor(fp2,node,&check,n);
                    }
                    else
                    {
                        fprintf(fp2,"%d does not exist\n",n);
                    }

                }
                if(strcmp(str,"predecessor")==0)
                {
                    fscanf(fp,"%s",str);
                    n = atoi(str);
                    if(search(fp2,node,n)==1)
                    {
                        predecessor(fp2,node,0,n,0);
                    }
                    else
                    {
                        fprintf(fp2,"%d does not exist\n",n);
                    }

                }
            }
        }
        fclose(fp);
        fclose(fp2);
    }
    return 0;
}

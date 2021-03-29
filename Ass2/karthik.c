#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int suc;
int pred;
struct node* newnode(int number)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = number;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void successor(FILE *fp2,struct node* node, int number)
{
    //if(search(fp2,node,number)==0)
    //{
      //  fprintf(fp2,"%d not found",number);
        //return;
    //

    if(node== NULL)
    {
        return;
    }
    if(node->data == number)
    {
        if(node->right != NULL)
        {
            struct node* suc_node= node->right;
            while(suc_node->left != NULL)
            {
                suc_node = suc_node->left;
            }
            fprintf(fp2,"%d\n",suc_node->data);
            return;
        }
        else
        {
            fprintf(fp2,"successor of %d does not exist\n",number);
        }
    }
    else if((node->data) >number)
    {
        return successor(fp2,node->left,number);
    }
    else if((node->data) <number)
    {
        return successor(fp2,node->right,number);
    }
}
void predecessor(FILE *fp2,struct node* node, int number,struct node* pred)
{

    if(node== NULL)
    {
        return;
    }
    if(node->data == number)
    {
        if(node->left != NULL)
        {
            struct node* pred_node = node->left;
            while(pred_node->right != NULL)
            {
                pred_node = pred_node->right;
            }
            pred = pred_node;
            //fprintf(fp2,"%d\n",pred_node->data);
            return;
        }
        else
        {
            return;
            //fprintf(fp2,"%d 2nd\n",node->data);
        }
    }
    else if(node->data < number)
    {
        pred = node;
        predecessor(fp2,node->right,number,pred);
    }
    else if(node->data > number)
    {
        predecessor(fp2,node->left,number,pred);
    }

    return;
}

struct node* insert(FILE *fp2,struct node* node, int number)
{
    if(node==NULL)
    {
        fprintf(fp2,"%d inserted\n",number);
        return newnode(number);
    }
    if(number<(node->data))
    {
        node->left = insert(fp2,node->left,number);
    }
    else if(number > node->data)
    {
        node->right = insert(fp2,node->right,number);
    }
    return node;
}
void min_bst(FILE *fp2,struct node* node)
{
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
    // use if statement 0 and 1 and then write to file found or not
    if(node == NULL)
    {
        //fprintf(fp2,"%d not found\n",number);
        return 0;
    }
    if(node->data == number)
    {
        //fprintf(fp2,"%d found\n",number);
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
void preorder_traversal(FILE *fp2,struct node* node)
{
    if(node == NULL)
    {

        return;
    }
    fprintf(fp2,"%d ",node->data);
    preorder_traversal(fp2,node->left);
    preorder_traversal(fp2,node->right);
}
void inorder_traversal(FILE *fp2,struct node* node)
{
    //if node==null removed the part fprintf(fp2,"\n"); in all 3 traversals so
    //so use that condition in main also print new line after each traversal
    if(node == NULL)
    {

        return;
    }
    inorder_traversal(fp2,node->left);
    fprintf(fp2,"%d ", node->data);
    inorder_traversal(fp2,node->right);

}
void postorder_traversal(FILE *fp2,struct node* node)
{
    if(node == NULL)
    {

        return;
    }
    postorder_traversal(fp2,node->left);
    postorder_traversal(fp2,node->right);
    fprintf(fp2,"%d ",node->data);
}
void sample(FILE *fp2, int x)
{
    fprintf(fp2,"Hello World");
}
int main(int argc, char *argv[])
{
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
        FILE *fp2 = fopen("bstf2.txt","w");
        if(fp2==NULL)
        {
            printf("Could not write to the output file\n");
        }
        else
        {
            struct node* node = NULL;
            while(fscanf(fp,"%s",str)!=EOF)
            {
                //fscanf(fp,"%s",str);
                //n = atoi(str);
                //fprintf(fp2,"%d\n",n);

                if(strcmp(str,"insert")==0)
                {
                    fscanf(fp,"%s",str);
                    n = atoi(str);
                    //icount++;
                    //fscanf(fp2," %d",&n);
                    //fscanf(fp2," %d",&n);
                    //fprintf(fp2,"%d\n",n);
                    //fprintf(fp2,"%d\n",icount);
                    //n = (int)str;
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
                        preorder_traversal(fp2,node);
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
                        postorder_traversal(fp2,node);
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
                        inorder_traversal(fp2,node);
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
                        //struct node* pred = NULL;
                        //struct node* suc = NULL;
                        //presuc(node,n);
                        //fprintf(fp2,"%d\n",suc);
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
                        //struct node* pred = node;
                        //struct node* suc = node;
                        //presuc(node,n);
                        //fprintf(fp2,"%d\n",pred);
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

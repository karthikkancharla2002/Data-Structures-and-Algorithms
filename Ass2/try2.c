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
struct node* successor(struct node* node, struct node* snode)
{
    // This gives the successor node of a given snode as output

        if(snode->right != NULL)
        {
            struct node* temp = node->right;
            while(temp->left!=NULL)
                {
                    temp = temp->left;
                }
                snode = temp;
                return snode;

        }
        struct node* temp = snode->parent;
        while(temp != NULL && snode == temp->right)
        {
            snode = temp;
            temp = temp->parent;
        }
        return temp;


}
struct node* predecessor(struct node* node, struct node* pnode)
{
    // This gives the predecessor node of a given pnode as output

        if(pnode->left!=NULL)
        {
            struct node* temp = node->left;
            while(temp->right!=NULL)
                {
                    temp = temp->right;
                }
                pnode = temp;
                return pnode;
        }
        struct node* temp = pnode->parent;
        while(temp!=NULL && pnode == temp->left)
        {
            pnode = temp;
            temp = temp->parent;
        }
        return temp;

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
void preorder_traversal(FILE *fp2,struct node* node)
{
    // This prints the preorder traversal of the binary search tree
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
    //This prints the inorder traversal of the binary search tree
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
    //This prints the post order traversal of the bst
    if(node == NULL)
    {

        return;
    }
    postorder_traversal(fp2,node->left);
    postorder_traversal(fp2,node->right);
    fprintf(fp2,"%d ",node->data);
}
int main(int argc, char *argv[])
{
    //Taking input
    FILE *fp = fopen(argv[1],"r");
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
        FILE *fp2 = fopen("bst.txt","w");
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
                        struct node* snode = NULL;
                        struct node* temp2 = NULL;
                        temp2 = searchnode(node,n);
                        snode = successor(node,temp2);
                        fprintf(fp2,"%d\n",snode->data);
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
                        struct node* pnode = NULL;
                        struct node* temp2 = NULL;
                        temp2 = searchnode(node,n);
                        pnode = predecessor(node,temp2);
                        fprintf(fp2,"%d\n",pnode->data);
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

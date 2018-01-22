
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 struct binary_tree {
     int data;
     struct binary_tree *left;
     struct binary_tree *right;
};
typedef struct binary_tree node;

void insert(node**tree, int val)
{
    node *temp =NULL;
    if(!(*tree)){
        temp = (node*)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp -> data = val;
        *tree = temp;
    }
    if(val <(*tree)->data)
    {
        insert(&(*tree)->left,val);
    }
    else if (val>(*tree)->data){
        insert (&(*tree)->right,val);
    }
}

void del(node* tree){
        if (tree)
        {
            del(tree->left);
            del(tree->right);
            free (tree);
        }
}

void print_preorder(node* tree)
{
    if (tree)
    {
        printf ("%d  ",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}
int main(void)
{
    node * root;
    node * tmp;
    //int i;

    root = NULL;
    /* Inserting nodes into tree */
    insert(&root,9);
    insert(&root,4);
    insert(&root,15);
    insert(&root,6);
    insert(&root,12);
    insert(&root,17);
    insert(&root,2);

    printf("Pre Order Display\n");
    print_preorder(root);
    
    del(root);
}

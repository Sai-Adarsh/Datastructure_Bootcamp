#include<stdlib.h>
#include<stdio.h>

//Tree node 
struct bin_tree 
{
    int data;
    struct bin_tree * right, * left;
};

typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree)) //Creation of the tree node        
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data) //If the incoming node val is less than the tree data insert in Left
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data) //If the incoming node val is greater than the tree data insert in right
    {
        insert(&(*tree)->right, val);
    }

}

//<root><left><right>
void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d\t",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

//<left><root><right>
void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\t",tree->data);
        print_inorder(tree->right);
    }
}

//<left><right><root>
void print_postorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        print_inorder(tree->right);
        printf("%d\t",tree->data);
    }
}

//<right><root><left>
void print_descend(node * tree)
{
    
    if (tree)
    {
        print_descend(tree->right);
        printf("%d\t",tree->data);
        print_descend(tree->left);
    }
}

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    //if the val less than root val search in the left subtree
    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    //if the val greater than root val search in the right subtree
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    //val equal to the root return the val
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

void getMin(node* tree)
{ 
    //Traversing to the left end to get the minimum element
    while(tree->left != NULL)
    {
        tree = tree->left;
    }
    printf("Minimum element: %d\n",tree->data);
}

void getMax(node* tree)
{
    //Traversing to the right end to get the maximum element
     while(tree->right != NULL)
    {
        tree = tree->right;
    }
    printf("Maximum element: %d\n",tree->data);
}


void main()
{
    node *root;
    node *tmp;
    //int i;

    root = NULL;
    /* Inserting nodes into tree */
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);

    /* Printing nodes of tree */
    printf("Pre Order Display\n");
    print_preorder(root);

    //Inorder traversal gives the ascending order
    printf("\nIn Order Display\n");
    print_inorder(root);

    printf("\nPost Order Display\n");
    print_postorder(root);

    printf("\nDescending Order Display\n");
    print_descend(root);


    /* Search node into tree */
    tmp = search(&root, 4);
    if (tmp)
    {
        printf("\nSearched node=%d\n", tmp->data);
    }
    else
    {
        printf("\nData Not found in tree.\n");
    }
    
    getMin(root);
    
    getMax(root);
    
    
    /* Deleting all nodes of tree */
    deltree(root);
}

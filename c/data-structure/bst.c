#include <stdlib.h> //return exit
#include <stdio.h> //printf

typedef struct node_t
{
    int key;
    int size;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
}node_t;

typedef struct bst_t
{
    node_t root;
}bst_t;

void init_node(node_t *node, int key)
{
    node->key = key;
    node->size = 1;
    node->right = NULL;
    node->left = NULL;
    node->parent = NULL;
}
void insert_node(node_t *root, int key)
{
    node_t *node = malloc(sizeof(node_t));
    init_node(node, key);
    /* if it's empty */
    if(root == NULL) root = node;
    else{
        node_t *ptr = root;
        while(ptr != NULL){
            node->parent = ptr;
            ptr->size++;
            if(ptr->key > key)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if(key < node->parent->key)
            node->parent->left = node;
        else
            node->parent->right = node;
    }
}
void display_node(node_t *node)
{
    if(node == NULL)
        printf(" Empty tree\n");
    else if(node->left != NULL && node->right != NULL)
    {
        printf("    %d \n", node->key);
        printf("   / \\\n");
        printf("  /   \\\n");
        printf(" %d    %d\n", node->left->key, node->right->key);
    }
    else if(node->right != NULL)
    {
        printf("    %d \n", node->key);
        printf("     \\\n");
        printf("      \\\n");
        printf("       %d\n", node->right->key);
    }
    else if(node->left != NULL)
    {
        printf("    %d \n", node->key);
        printf("   /   \n");
        printf("  /     \n");
        printf(" %d      \n", node->left->key);
    }
}
void display_bst(node_t *root)
{
    if(root != NULL)
    {
        display_bst(root->left);
        display_node(root);
        display_bst(root->right);
    }
}
int main(int argc, char **argv)
{
    node_t *root = malloc(sizeof(node_t)); 
    init_node(root, 0);
    insert_node(root, 10);
    insert_node(root, 5);
    insert_node(root, 7);
    insert_node(root, 9);
    insert_node(root, 6);
    insert_node(root, 1);
    insert_node(root, 8);
    insert_node(root, 4);
    insert_node(root, 2);
    insert_node(root, 3);
    display_bst(root);

    return EXIT_SUCCESS;
}

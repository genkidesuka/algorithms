#include <stdlib.h> //return exit
#include <stdio.h> //printf

typedef struct node_t
{
    int key;
    int size;//total nodes on the subtree
    int height;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
}node_t;

typedef struct bst_t
{
    node_t root;
}bst_t;


int max_int(node_t *node_a, node_t *node_b)
{
    if(node_a != NULL && node_b != NULL)
    {
        return (node_a->height > node_b->height)? 
            node_a->height : node_b->height;
    }
    else if(node_a != NULL)
    {
        return node_a->height;
    }
    else if(node_b != NULL)
    {
        return node_b->height;
    }
    else
    {
        return -1;
    }
}

void init_node(node_t *node, int key)
{
    node->key = key;
    node->size = 1;
    node->right = NULL;
    node->left = NULL;
    node->parent = NULL;
    node->height= max_int(node->left, node->right) + 1;
}
void rotate_right(node_t *node)
{
    /*
     *       y            x
     *      / \          / \
     *     x   C  --->  A   y
     *    / \              / \
     *   A   B            B   C
     */
}
void rotate_left(node_t *node)
{
    /*
     *       y            x
     *      / \          / \
     *     x   C  <---  A   y
     *    / \              / \
     *   A   B            B   C
     */
}
void verify_avl(node_t *node)
{
    int hl = (node->left == NULL)? -1 : node->left->height;
    int hr = (node->right == NULL)? -1 : node->right->height;
    if(hl - hr > 1)
        rotate_right(node);
    else if(hr - hl > 1)
        rotate_left(node);
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
            {
                ptr = ptr->left;
            }
            else
            {
                ptr = ptr->right;
            }
        }
        if(key < node->parent->key)
            node->parent->left = node;
        else
            node->parent->right = node;
        /* update nodes height through out the insertion path */
        ptr = node;
        while(ptr != NULL)
        {
            ptr->height = max_int(ptr->left, ptr->right) + 1;
            verify_avl(ptr);
            ptr = ptr->parent;
        }
    }
}
void display_node(node_t *node)
{
    if(node == NULL)
        printf(" Empty tree\n");
    else if(node->left != NULL && node->right != NULL)
    {
        printf("   %d,%d \n", node->key, node->height);
        printf("   / \\\n");
        printf("%d,%d %d,%d\n", node->left->key, node->left->height,
                node->right->key, node->right->height);
    }
    else if(node->right != NULL)
    {
        printf("   %d,%d \n", node->key, node->height);
        printf("     \\\n");
        printf("      %d,%d\n", node->right->key, node->right->height);
    }
    else if(node->left != NULL)
    {
        printf("   %d,%d \n", node->key, node->height);
        printf("   /   \n");
        printf("%d,%d      \n", node->left->key, node->left->height);
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
    display_bst(root);

    return EXIT_SUCCESS;
}

#include <conio.h>
#include <stdio.h>

//define tree node 
typedef struct node {
    int value;
    node *left;
    node *right;
} NODE;


int tree_height (NODE *root) 
/*------------------------------------------------------------------------------
    tree_height    : utility function to find tree hight
    Written by     : RaspiRepo
    Date           : Nov 30, 2016
 ------------------------------------------------------------------------------*/
{
    if (root == NULL) {
        return 0;
    }
    //get left sub tree height
    int left_h = tree_height(root->left) + 1;

    //get right sub tree height
    int right_h = tree_height(root->right) + 1;

    //return max of left/right tree height as tree hight
    int max = right_h;
    if (left_h > right_h) {
        max = left_h;
    }
    return max;
}

void print_level(NODE *root, int level)
/*------------------------------------------------------------------------------
    print_level    : utility function to display tree node value in level order
    Written by     : RaspiRepo
    Date           : Nov 30, 2016
 ------------------------------------------------------------------------------*/
{
    if (root == NULL) {
        return;
    } 
    if (level == 1) {
        printf("%d ", root->value);
    }
    print_level(root->left, level -1);
    print_level(root->right, level -1);
}

void print_level_order (NODE *root) 
/*------------------------------------------------------------------------------
    print_level_order
                   : utility function to display tree node value in level order
    Written by     : RaspiRepo
    Date           : Nov 30, 2016
 ------------------------------------------------------------------------------*/
{
    int tree_h = tree_height(root)+1;
    for (int i = 0; i < tree_h; i++) {
        print_level(root, i);
        printf("\n");
    }
}

NODE *rotate_right (NODE *x)
/*------------------------------------------------------------------------------
    rotate_right   : Rotate right direction of given node
    Written by     : RaspiRepo
    Date           : Nov 30, 2016
 ------------------------------------------------------------------------------*/
{
    NODE *y = x->left;
    NODE *t = y->right;
    y->right = x;
    x->left = t;

    return y;
}

NODE *rotate_left (NODE *x)
/*------------------------------------------------------------------------------
    rotate_left    : Rotate left direction of given node
    Written by     : RaspiRepo
    Date           : Nov 30, 2016
 ------------------------------------------------------------------------------*/
{
    NODE *y = x->right;
    NODE *t = y->left;
    y->left = x;
    x->right = t;
    return y;
}


NODE *avl_insert_node (NODE *root, int value)
/*------------------------------------------------------------------------------
    avl_insert_node
                    : Recursive call to insert node into binary search tree 
                      and also balance the tree, so wrost case search is O(log n)

    Written by     : RaspiRepo
    Date           : Nov 30, 2016
 ------------------------------------------------------------------------------*/
{
    //first time or leaf node reached then create new node and update the value
    if (root == NULL) {
        root = new NODE;
        root->value = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    //recursivly find insert postion eight left or right sub tree.
    if (value < root->value) {
        root->left = avl_insert_node(root->left, value);
    } else {
        root->right = avl_insert_node(root->right, value);
    }

    //*** THIS BELOW SECTION CALLED IN REVERSE PATH FROM LEAF(NEWLY INSERTED) NODE TO ROOT ***
    // *** SO BALANCE FACTOR IS CHECKED AS WELL AS APPLY THE BALANCE ON TREE
    //1. find height of left and right sub tree
    int left_h = tree_height(root->left);
    int right_h = tree_height(root->right);

    //balance factor current root
    int bf = left_h - right_h; //NOTE: REVERSE THE LOGIC OF BF = RIGHT - LEFT

    //left is heavy. 
    if (bf > 1) {
        //added left i.e. 9->7->6
        if (value < root->left->value) {
            root = rotate_right (root);

        //left heavy added right->left (zig zag)
        } else {
            root->left = rotate_left(root->left);
            root = rotate_right(root);
        }
    //right side is heavy
    } else if (bf < -1) {
        //right-right, i.e. 12->14->15 
        if (value > root->right->value) { 
            root = rotate_left(root);

        //d. right heavy added right->left (zig zag)
        } else {
            root->right = rotate_right(root->right);
            root = rotate_left(root);
        }
    }
    return root;
}   



void main () 
/*------------------------------------------------------------------------------
    main            : main function to check avl tree insert and balance. 
                      search operation always O(long n)

    Written by     : RaspiRepo
    Date           : Nov 30, 2016
 ------------------------------------------------------------------------------*/
{
    int input_a[] = {10, 12, 9, 7, 6, 8, 11, 4, 1, 3, 16, 19, 13, 14,18,17,21,20};
    int n = sizeof(input_a) / sizeof(int);
    printf("number of elements %d\n", n);
    NODE *avl_root = NULL;
   
    for (int i = 0; i < n; i++) {
        //printf("**** Insert %d  ****\n", input_a[i]);
        avl_root = avl_insert_node (avl_root, input_a[i]);
    }
    printf("tree height %d\n", tree_height(avl_root));
    print_level_order(avl_root);
    getch();
}

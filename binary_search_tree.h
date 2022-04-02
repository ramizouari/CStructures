//
// Created by ramizouari on 02/04/2022.
//

#ifndef CSTRUCTURES_BINARY_SEARCH_TREE_H
#define CSTRUCTURES_BINARY_SEARCH_TREE_H
#include <stddef.h>
#include <stdlib.h>
#include <math.h>


typedef struct avl_node {
    void *data;
    struct avl_node *left;
    struct avl_node *right;
    int height;
} avl_node,*avl_tree;

avl_tree avl_tree_create(void)
{
    return NULL;
}

int avl_tree_height(avl_tree tree)
{
    if (tree == NULL)
        return -1;
    return tree->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

avl_tree avl_tree_rotate_left(avl_tree tree)
{
    avl_tree new_root = tree->right;
    tree->right = new_root->left;
    new_root->left = tree;
    tree->height = 1 + max(avl_tree_height(tree->left), avl_tree_height(tree->right));
    new_root->height = 1 + max(avl_tree_height(new_root->left), avl_tree_height(new_root->right));
    return new_root;
}

avl_tree avl_tree_rotate_right(avl_tree tree)
{
    avl_tree new_root = tree->left;
    tree->left = new_root->right;
    new_root->right = tree;
    tree->height = 1 + max(avl_tree_height(tree->left), avl_tree_height(tree->right));
    new_root->height = 1 + max(avl_tree_height(new_root->left), avl_tree_height(new_root->right));
    return new_root;
}

avl_tree avl_tree_rotate_left_right(avl_tree tree)
{
    tree->left = avl_tree_rotate_left(tree->left);
    return avl_tree_rotate_right(tree);
}

avl_tree avl_tree_rotate_right_left(avl_tree tree)
{
    tree->right = avl_tree_rotate_right(tree->right);
    return avl_tree_rotate_left(tree);
}

avl_tree avl_tree_insert(avl_tree tree, void *data)
{
    if (tree == NULL)
    {
        tree = malloc(sizeof(avl_node));
        tree->data = data;
        tree->left = NULL;
        tree->right = NULL;
        tree->height = 1;
    }
    else if (data < tree->data)
    {
        tree->left = avl_tree_insert(tree->left, data);
        if (avl_tree_height(tree->left) - avl_tree_height(tree->right) == 2)
        {
            if (data < tree->left->data)
            {
                tree = avl_tree_rotate_left(tree);
            }
            else
            {
                tree = avl_tree_rotate_right_left(tree);
            }
        }
    }
    else if (data > tree->data)
    {
        tree->right = avl_tree_insert(tree->right, data);
        if (avl_tree_height(tree->right) - avl_tree_height(tree->left) == 2)
        {
            if (data > tree->right->data)
            {
                tree = avl_tree_rotate_right(tree);
            }
            else
            {
                tree = avl_tree_rotate_left_right(tree);
            }
        }
    }
    tree->height = max(avl_tree_height(tree->left), avl_tree_height(tree->right)) + 1;
    return tree;
}

avl_tree avl_tree_min(avl_tree tree)
{
    if (tree == NULL)
        return NULL;
    while (tree->left != NULL)
    {
        tree = tree->left;
    }
    return tree;
}

avl_tree avl_tree_erase(avl_tree tree, void *data) {
    if (tree == NULL) {
        return NULL;
    } else if (data < tree->data) {
        tree->left = avl_tree_erase(tree->left, data);
        if (avl_tree_height(tree->right) - avl_tree_height(tree->left) == 2) {
            if (avl_tree_height(tree->right->left) > avl_tree_height(tree->right->right)) {
                tree = avl_tree_rotate_right(tree);
            } else {
                tree = avl_tree_rotate_left_right(tree);
            }
        }
    } else if (data > tree->data) {
        tree->right = avl_tree_erase(tree->right, data);
        if (avl_tree_height(tree->left) - avl_tree_height(tree->right) == 2) {
            if (avl_tree_height(tree->left->right) > avl_tree_height(tree->left->left)) {
                tree = avl_tree_rotate_left(tree);
            } else {
                tree = avl_tree_rotate_right_left(tree);
            }
        }
    } else {
        if (tree->left == NULL) {
            avl_tree temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            avl_tree temp = tree->left;
            free(tree);
            return temp;
        } else {
            avl_tree temp = avl_tree_min(tree->right);
            tree->data = temp->data;
            tree->right = avl_tree_erase(tree->right, temp->data);
            if (avl_tree_height(tree->left) - avl_tree_height(tree->right) == 2) {
                if (avl_tree_height(tree->left->right) > avl_tree_height(tree->left->left)) {
                    tree = avl_tree_rotate_left(tree);
                } else {
                    tree = avl_tree_rotate_right_left(tree);
                }
            }
        }
    }
    return tree;
}

typedef avl_node binary_node;
typedef avl_tree binary_search_tree;
#endif //CSTRUCTURES_BINARY_SEARCH_TREE_H

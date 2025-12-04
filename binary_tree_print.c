#include "binary_trees.h"
#include <stdio.h>
#include <string.h>

/**
 * _print_t - Recursively prints a binary tree into a 2D array of characters
 * @tree: Pointer to the root node of the tree
 * @is_left: Flag to indicate if current node is a left child
 * @offset: Horizontal offset for printing
 * @depth: Current depth in the tree
 * @s: 2D array of characters used for printing
 *
 * Return: Width of the printed tree
 */
int _print_t(const binary_tree_t *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;
    int left, right;
    int i;

    if (tree == NULL)
        return (0);

    sprintf(b, "(%03d)", tree->n);

    left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left)
    {
        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
#else
    for (i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left)
    {
        for (i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';
        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width / 2 + i] = '-';
        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }
#endif

    return (left + width + right);
}

/**
 * binary_tree_print - Prints a binary tree in a structured format
 * @tree: Pointer to the root node of the tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
    char s[20][255];
    int i;

    if (tree == NULL)
        return;

    for (i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

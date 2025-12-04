#include "binary_trees.h"
#include <stdlib.h>

/**
* binary_tree_size - Measures the size of a binary tree (iterative DFS)
* @tree: Pointer to the root node of the tree to measure
*
* Return: Size of the tree, or 0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
const binary_tree_t **stack;
size_t top = 0, size = 0, capacity = 1024;

if (tree == NULL)
return (0);

stack = malloc(sizeof(binary_tree_t *) * capacity);
if (stack == NULL)
return (0);

stack[top++] = tree;

while (top > 0)
{
const binary_tree_t *node = stack[--top];
size++;

if (node->left)
stack[top++] = node->left;
if (node->right)
stack[top++] = node->right;
}

free(stack);
return (size);
}

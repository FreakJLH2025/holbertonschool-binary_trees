#include "binary_trees.h"
#include <stdlib.h>

/**
* binary_tree_nodes - Counts nodes with at least 1 child (iterative DFS)
* @tree: Pointer to the root node of the tree
*
* Return: Number of nodes with at least 1 child
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
const binary_tree_t **stack;
size_t top = 0, count = 0, capacity = 1024;

if (tree == NULL)
return (0);

stack = malloc(sizeof(binary_tree_t *) * capacity);
if (stack == NULL)
return (0);

stack[top++] = tree;

while (top > 0)
{
const binary_tree_t *node = stack[--top];

if (node->left != NULL || node->right != NULL)
count++;

if (node->left)
stack[top++] = node->left;
if (node->right)
stack[top++] = node->right;
}

free(stack);
return (count);
}

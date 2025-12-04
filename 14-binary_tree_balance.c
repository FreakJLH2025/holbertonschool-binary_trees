#include "binary_trees.h"

static size_t height(const binary_tree_t *tree)
{
size_t left, right;

if (tree == NULL)
return (0);

left = height(tree->left);
right = height(tree->right);

return ((left > right ? left : right) + 1);
}

/**
* binary_tree_balance - Measures the balance factor of a binary tree
* @tree: Pointer to the root node of the tree
*
* Return: Balance factor, or 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return ((int)height(tree->left) - (int)height(tree->right));
}

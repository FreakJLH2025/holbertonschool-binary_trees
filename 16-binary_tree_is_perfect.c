#include "binary_trees.h"

/**
* height - Measures the height of a binary tree
* @tree: Pointer to the root node of the tree
*
* Return: Height of the tree, or 0 if tree is NULL
*/
static size_t height(const binary_tree_t *tree)
{
size_t left, right;

if (tree == NULL)
return (0);

left = height(tree->left);
right = height(tree->right);

return ((left > right ? left : right)+1);
}

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect
* @tree: Pointer to the root node of the tree
*
* Return: 1 if tree is perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t left_h, right_h;

if (tree == NULL)
return (0);

if (tree->left == NULL && tree->right == NULL)
return (1);

if (tree->left == NULL || tree->right == NULL)
return (0);

left_h = height(tree->left);
right_h = height(tree->right);

if (left_h != right_h)
return (0);

return (binary_tree_is_perfect(tree->left) &&
binary_tree_is_perfect(tree->right));
}

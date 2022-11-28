int min(Tree tree)
{
    return tree->left == nullptr
        ? tree->value
        : min(tree->left);
}
int max(Tree tree)
{
    return tree->right == nullptr
        ? tree->value
        : max(tree->right);
}

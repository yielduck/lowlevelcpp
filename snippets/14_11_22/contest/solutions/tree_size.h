unsigned int treeSize(Tree const tree)
{
    if(tree == nullptr)
        return 0u;
    return 1u + treeSize(tree->left) + treeSize(tree->right);
}

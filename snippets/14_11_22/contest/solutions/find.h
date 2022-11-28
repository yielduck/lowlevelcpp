Node *find(Tree const tree, int const n)
{
    if(tree == nullptr)
        return nullptr;
    if(tree->value < n)
        return find(tree->left , n);
    if(tree->value > n)
        return find(tree->right, n);
    return tree;
}

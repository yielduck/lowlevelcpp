Tree merge(Tree const base, Tree const tree)
{
    if(base == nullptr)
        return tree;
    if(tree == nullptr)
        return base;
    if(base->value < tree->value)
    {
        base->right = merge(base->right, tree->right);
        Tree const left = tree->left;
        return merge(insert(tree, base), left);
    }
    if(base->value > tree->value)
    {
        base->left = merge(base->left, tree->left);
        Tree const right = tree->right;
        return merge(insert(tree, base), right);
    }
    else
    {
        base->left  = merge(base->left , tree->left );
        base->right = merge(base->right, tree->right);
        std::free(tree);
        return base;
    }
}

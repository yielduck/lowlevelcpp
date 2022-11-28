unsigned int depth(Tree const tree)
{
    if(tree == nullptr)
        return 0u;
    unsigned int const left  = depth(tree->left );
    unsigned int const right = depth(tree->right);
    return 1u + (left < right ? right : left);
}

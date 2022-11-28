Tree insert(int const value, Tree const tree)
{
    if(tree == nullptr)
        return cons(nullptr, value, nullptr);
    else if(value < tree->value)
        tree->left  = insert(value, tree->left );
    else if(value > tree->value)
        tree->right = insert(value, tree->right);
    return tree;
}
Tree insert(Node * const node, Tree const tree)
{
    if(tree == nullptr)
    {
        node->left  = nullptr;
        node->right = nullptr;
        return node;
    }
    else if(node->value < tree->value)
        tree->left  = insert(node, tree->left );
    else if(node->value > tree->value)
        tree->right = insert(node, tree->right);
    else
        std::free(node);
    return tree;
}

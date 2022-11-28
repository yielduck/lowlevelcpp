List inorder(Tree const tree)
{
    if(tree == nullptr)
        return nullptr;
    List const left  = inorder(tree->left );
    List const right = inorder(tree->right);
    return concat(left, cons(tree, right));
}
List preorder(Tree const tree)
{
    if(tree == nullptr)
        return nullptr;
    List const left  = preorder(tree->left );
    List const right = preorder(tree->right);
    return concat(cons(tree, left), right);
}

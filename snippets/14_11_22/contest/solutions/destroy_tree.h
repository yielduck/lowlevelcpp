void destroyTree(Tree const tree)
{
    if(tree == nullptr)
        return;
    destroyTree(tree->left );
    destroyTree(tree->right);
    std::free(tree);
}

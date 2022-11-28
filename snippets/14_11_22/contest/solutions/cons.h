Tree cons(Tree const left, int const value, Tree const right)
{
    Node * const node = static_cast<Node *>(std::malloc(sizeof(Node)));
    node->value = value;
    node->left  =  left;
    node->right = right;
    return node;
}

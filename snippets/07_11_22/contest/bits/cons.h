List cons(int const value, List const tail)
{
    Node * const node = static_cast<Node *>(std::malloc(sizeof(Node)));
    node->value = value;
    node->next = tail;
    return node;
}

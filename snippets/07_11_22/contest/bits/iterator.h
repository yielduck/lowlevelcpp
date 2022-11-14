struct ListIterator
{
    Node *node;

    ListIterator &operator++(   ) {                  node = node->next; return *this;}
    ListIterator  operator++(int) {Node *tmp = node; node = node->next; return {tmp};}

    bool operator!=(ListIterator const &other) const {return node != other.node;}
    bool operator==(ListIterator const &other) const {return node == other.node;}

    int &operator* () const {return  node->value;}
    int *operator->() const {return &node->value;}
};

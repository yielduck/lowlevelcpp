// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
#include <ostream>
#include <string>
std::ostream &printTree(std::ostream &out, Tree const tree, bool right, std::string const &prefix)
{
    if(tree != nullptr)
    {
        out << prefix << (right ? "└──" : "├──" ) << tree->value << std::endl;
        printTree(out, tree->left, false, prefix + (right ? "    " : "│   "));
        printTree(out, tree->right, true, prefix + (right ? "    " : "│   "));
    }
    return out;
}
std::ostream &operator<<(std::ostream &out, Tree const tree)
{
    return printTree(out, tree, true, "");
}

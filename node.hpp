//Email: maayan1sher@gmail.com
#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
using namespace std;

template <typename T>
class Node
{

public:
    T key;
    vector<Node<T> *> children;

    // Constructor
    Node(T value) : key(value) {}



    // Return the value of the node
    T get_value() const
    {
        return key;
    }

    // // Return the childrens of the node
    vector<Node *> &get_children()
    {
        return children;
    }

    // Add a child to a node
    void add_child(Node<T> *child)
    {
        children.push_back(child);
    }
    
    // Method for remoive the children of the node
    void clear_children(){
        children.clear();
    }
};

#endif
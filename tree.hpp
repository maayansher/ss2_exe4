//Email: maayan1sher@gmail.com

#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <iomanip>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include "node.hpp"
#include "complex.hpp"

using namespace std;
template <typename T>
class Tree
{
private:
    Node<T> *root;
    size_t k;

public:
    // Constructor to tree with default of 2 children max
    explicit Tree(size_t k = 2) : root(nullptr), k(k) {}

    ~Tree() {}

    void add_root(Node<T> &node)
    {
        if (!root)
        {

            root = &node;
        }
        else{
            throw runtime_error("Cannot add more then one root");
        }
    }

    Node<T> *get_root() const
    {
        return root;
    }

    void add_sub_node(Node<T> &parent, Node<T> &child)
    {
        // Check if root is set, if not throw error
        if (!root)
        {
            throw runtime_error("Root isnt set yet");
        }
        // Check if the parent as less children then K, if so we can add the child to the parent
        if (parent.children.size() < k)
        {
            parent.add_child(&child);
        }
        else
        {
            // If the parent have children equal to K, throw error since he cant have more then k childrens
            throw runtime_error("Max children reached for this node");
        }
    }

    template <typename U>
    void add_sub_node(Node<T> &parent, Node<U> &child)
    {
        throw runtime_error("Cannot add child from different type");
    }

public:
    class PreOrderIterator
    {
    private:
        stack<Node<T> *> stack1; // Stack to keep track of nodes to visit

    public:
        PreOrderIterator() = default;
        // Constructor intializes the iterator, starting at the root node
        PreOrderIterator(Node<T> *root)
        {
            if (root)
            {

                stack1.push(root);
            }
        }

        // Comparison operator to determine when to stop the traversl
        bool
        operator!=(const PreOrderIterator &other) const
        {
            return !stack1.empty();
        }
        // operator to access the current node
        Node<T> &operator*() const
        {
            return *stack1.top(); // Return reference to the top node in the stack
        }
        // operator to access the current nodes member
        Node<T> *operator->() const
        {
            return stack1.top();
        }

        // Increment operator to move to the next node in PreOrder
        PreOrderIterator &operator++()
        {
            Node<T> *node = stack1.top(); // Get the top node from the stack
            stack1.pop();                 // Remove the top node from the stack

            // To ensure that left child is procssed before the right child
            // we push the children onto the stack in reverse order.
            for (auto i = node->children.rbegin(); i != node->children.rend(); ++i)
            {
                stack1.push(*i);
            }
            return *this;
        }
    };

    class PostOrderIterator
    {
    private:
        stack<Node<T> *> stack1, stack2;

    public:
        PostOrderIterator() = default;
        PostOrderIterator(Node<T> *root)
        {
            if (root)
            {
                stack1.push(root); // If root isnt null push the root node onto stack1

                while (!stack1.empty())
                {
                    /**
                     * Get the top node from the first stack and remove from stack1 into stack 2.
                     * then on for loop insert all the node children into stack1
                     */
                    Node<T> *node = stack1.top();
                    stack1.pop();
                    stack2.push(node);

                    for (auto child : node->children)
                    {
                        stack1.push(child);
                    }
                }
            }
        }

        // Comparison operator to determine when to stop the traversl
        bool operator!=(const PostOrderIterator &other) const
        {
            return !stack2.empty();
        }
        // operator to access the current node
        Node<T> &operator*() const
        {
            return *stack2.top();
        }
        // operator to access the current nodes member
        Node<T> *operator->() const
        {
            return stack2.top();
        }
        // increment operator to move to the next node
        PostOrderIterator &operator++()
        {
            stack2.pop();
            return *this;
        }
    };

    class InOrderIterator
    {
    private:
        stack<Node<T> *> stack1; // stack to keep track of nodes we need to visit
        Node<T> *current;        // current node

        void push_left(Node<T> *node)
        {
            /**
             * The purpose of this loop is to traverse down to the left subtree of the given node.
             */
            while (node)
            {
                stack1.push(node);
                // If the node as children it accesses the left child, if null leave the while loop
                node = !node->children.empty() ? node->children[0] : nullptr;
            }
        }

    public:
        InOrderIterator() = default;
        // constructor initializes the iterator starting from the root node
        InOrderIterator(Node<T> *root) : current(root)
        {
            push_left(root);
        }

        bool operator!=(const InOrderIterator &other) const
        {
            return !stack1.empty();
        }

        Node<T> &operator*() const
        {
            return stack1.top();
        }

        Node<T> *operator->() const
        {
            return stack1.top();
        }
        InOrderIterator &operator++()
        {
            Node<T> *node = stack1.top();
            stack1.pop();

            if (!node->children.empty())
            {
                for (size_t i = 1; i < node->children.size(); ++i)
                {
                    push_left(node->children[i]);
                }
            }
            return *this;
        }
    };

    class BFSIterator
    {
    private:
        queue<Node<T> *> q;

    public:
        BFSIterator() = default;
        BFSIterator(Node<T> *root)
        {
            if (root)
            {
                q.push(root); // if theres root, push it into the queue
            }
        }

        bool operator!=(const BFSIterator &other) const
        {
            return !q.empty();
        }

        Node<T> &operator*() const
        {
            return *q.front(); // return reference to the front node in the queue
        }

        Node<T> *operator->() const
        {
            return q.front(); // return pointer to the front node in the queue
        }

        BFSIterator &operator++()
        {
            Node<T> *node = q.front(); // get the front node from the queue
            q.pop();                   // pop the front node from the queue

            for (auto child : node->children) // add all children of the node into the queue
            {
                q.push(child);
            }
            return *this;
        }
    };

    class DFSIterator
    {
    private:
        stack<Node<T> *> stack1;

    public:
        DFSIterator() = default;
        DFSIterator(Node<T> *root)
        {
            if (root)
            {
                stack1.push(root);
            }
        }

        bool operator!=(const DFSIterator &other) const
        {
            return !stack1.empty();
        }

        Node<T> &operator*() // dereference operator to access the current node
        {
            return *stack1.top();
        }

        Node<T> *operator->() // operator to access the nodes members
        {
            return stack1.top();
        }

        DFSIterator &operator++()
        {
            Node<T> *node = stack1.top(); // get the top node from the stack
            stack1.pop();                 // remove the top node from the stack
                                          // push all children of the node onto the stack in reverese order
            for (auto i = node->children.rbegin(); i != node->children.rend(); ++i)
            {
                stack1.push(*i);
            }
            return *this;
        }
    };

    /**
     * Heap iterator to convert the tree into Heap tree (this iterator works for binary tree only)
     * */
    class HeapIterator
    {
    private:
        vector<Node<T> *> heap_nodes;
        // comprator to compare nodes base on their values.
        struct NodeCompartor
        {
            bool operator()(Node<T> *first, Node<T> *second)
            {
                return first->get_value() > second->get_value();
            }
        };
        // recursive function to gather all nodes in the tree starting from the given node
        void gather_nodes(Node<T> *node)
        {
            if (node)
            {
                heap_nodes.push_back(node); // add current node to the heap
                for (auto child : node->get_children())
                {
                    gather_nodes(child); // recursively add all the nodes children into the heap
                }
            }
        }

    public:
        HeapIterator() = default;
        HeapIterator(Node<T> *root, size_t k)
        {
            if (k != 2)
            {
                throw runtime_error("Cannot create a min heap tree since the following tree isnt a binary tree");
            }
            if (root)
            {
                gather_nodes(root);                                               // collect all nodes from the tree starting from the root
                make_heap(heap_nodes.begin(), heap_nodes.end(), NodeCompartor()); // create min heap from the collected nodes
            }
        }
        // operator to compare the current iterator with another one
        bool operator!=(const HeapIterator &other) const
        {
            // check if the current heap isnt empty compared to other heap
            return !heap_nodes.empty() != !other.heap_nodes.empty();
        }

        Node<T> *operator->() const
        {
            return heap_nodes.front();
        }

        Node<T> &operator*() const
        {
            return *heap_nodes.front();
        }
        // Increment to move to the next node in the heap
        HeapIterator &operator++()
        {
            if (!heap_nodes.empty())
            {
                pop_heap(heap_nodes.begin(), heap_nodes.end(), NodeCompartor()); // remove the front node from the heap
                heap_nodes.pop_back();                                           // remove the last element which is the smallest one
            }
            return *this;
        }
    };
    auto begin_pre_order() const
    {
        return PreOrderIterator(root); // creates the PreOrder iterator starting from the root
    }

    auto end_pre_order() const
    {
        return PreOrderIterator(); // creates the PreOrder iterator to detemine when the traverse as finished
    }

    auto begin_post_order() const
    {

        return PostOrderIterator(root);
    }

    auto end_post_order() const
    {

        return PostOrderIterator();
    }

    auto begin_in_order() const
    {
        return InOrderIterator(root);
    }

    auto end_in_order() const
    {
        return InOrderIterator();
    }

    auto begin_bfs_scan() const
    {
        return BFSIterator(root);
    }

    auto end_bfs_scan() const
    {
        return BFSIterator();
    }

    auto begin_dfs_scan() const
    {
        return DFSIterator(root);
    }

    auto end_dfs_scan() const
    {
        return DFSIterator();
    }

    auto begin_heap() const
    {
        return HeapIterator(root, k);
    }

    auto end_heap() const
    {
        return HeapIterator();
    }

};

#endif
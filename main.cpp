//Email: maayan1sher@gmail.com
/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include "gui.hpp"
#include "complex"

using namespace std;

int main()
{

    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    TreeVisualizer<double> visual(tree);
    visual.display();

    cout << "PreOrder traverse: " << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << endl;
    }

    // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    cout << "PostOrder traverse: " << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << endl;
    }
    // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    cout << "InOrder traverse: " << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << endl;
    }
    // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    cout << "BFS traverse: " << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << "DFS traverse: " << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    cout << "Min Heap travrse :" << endl;
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    root_node.clear_children();
    n1.clear_children();
    n2.clear_children();
    n3.clear_children();
    n4.clear_children();
    n5.clear_children();

    Tree<double> three_ary_tree(3); // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    TreeVisualizer<double> visual2(three_ary_tree);
    visual2.display();
    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    cout << "BFS traverse on three ary tree: " << endl;
    for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    }

    cout << "DFS traverse on three ary tree: " << endl;
    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    }

    Node<Complex> root_cnode(Complex(1.1, 4.2));
    Node<Complex> cn1(Complex(2, 2));
    Node<Complex> cn2(Complex(1, 8));
    Node<Complex> cn3(Complex(4, 32));
    Node<Complex> cn4(Complex(1.5, 4));
    Node<Complex> cn5(Complex(11.6));
    Node<Complex> cn6(Complex(13));
    Node<Complex> cn7(Complex(5, 3));

    Tree<Complex> complexTree; // Binary tree that contains doubles.
    complexTree.add_root(root_cnode);
    complexTree.add_sub_node(root_cnode, cn1);
    complexTree.add_sub_node(root_cnode, cn2);
    complexTree.add_sub_node(cn1, cn3);
    complexTree.add_sub_node(cn1, cn4);
    complexTree.add_sub_node(cn2, cn5);
    complexTree.add_sub_node(cn5, cn6);
    complexTree.add_sub_node(cn5, cn7);
    TreeVisualizer<Complex> visual1(complexTree);
    visual1.display();

    cout << "PreOrder traverse on Complex Tree: " << endl;
    for (auto node = complexTree.begin_pre_order(); node != complexTree.end_pre_order(); ++node)
    {
        cout << node->get_value() << endl;
    }

    cout << "PostOrder traverse on Complex Tree: " << endl;
    for (auto node = complexTree.begin_post_order(); node != complexTree.end_post_order(); ++node)
    {
        cout << node->get_value() << endl;
    }

    cout << "InOrder traverse on Complex Tree: " << endl;
    for (auto node = complexTree.begin_in_order(); node != complexTree.end_in_order(); ++node)
    {
        cout << node->get_value() << endl;
    }

    cout << "BFS traverse on Complex Tree: " << endl;
    for (auto node = complexTree.begin_bfs_scan(); node != complexTree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    }

    cout << "DFS traverse on Complex Tree: " << endl;
    for (auto node = complexTree.begin_dfs_scan(); node != complexTree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    }

    cout << "Min Heap travrse on Complex Tree:" << endl;
    for (auto node = complexTree.begin_heap(); node != complexTree.end_heap(); ++node)
    {
        cout << node->get_value() << endl;
    }
}
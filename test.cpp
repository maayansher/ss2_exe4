// Email: maayan1sher@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "node.hpp"
#include "tree.hpp"
#include "complex.hpp"

using namespace std;

TEST_CASE("Testing binary tree")
{
    Node<int> root(1);
    Node<int> n1(3);
    Node<int> n2(6);
    Node<int> n3(9);

    Tree<int> tree(2); // Binary tree with max 2 children per node

    tree.add_root(root);

    SUBCASE("Adding nodes")
    {
        tree.add_sub_node(root, n1);
        tree.add_sub_node(root, n2);

        CHECK(root.children.size() == 2);
        CHECK(root.children[0]->get_value() == 3);
        CHECK(root.children[1]->get_value() == 6);

        // Adding thrid child and it throwing an error

        CHECK_THROWS_AS(tree.add_sub_node(root, n3), runtime_error);

        // Adding root to the tree should throw error since the tree have root already
        Node<int> root2(14);
        CHECK_THROWS_AS(tree.add_root(root2), runtime_error);

        // Adding a double node to a int tree should throw runtime error.(cannot add node from different type)
        Node<double> differentNode(3.3);
        CHECK_THROWS_AS(tree.add_sub_node(n2, differentNode), runtime_error);
    }
}

TEST_CASE("Tree traverse on binary tree")
{
    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    Tree<double> tree(2);
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

    SUBCASE("PreOrder")
    {
        vector<double> result;
        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<double> excepted = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
        CHECK(result == excepted);
    }

    SUBCASE("PostOrder")
    {
        vector<double> result;
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {

            result.push_back(node->get_value());
        }
        vector<double> excepted = {1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
        CHECK(result == excepted);
    }

    SUBCASE("InOrder")
    {
        vector<double> result;
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<double> excepted = {1.4, 1.2, 1.5, 1.1, 1.6, 1.3};
        CHECK(result == excepted);
    }

    SUBCASE("BFS")
    {
        vector<double> result;
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<double> excepted = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
        CHECK(result == excepted);
    }

    SUBCASE("DFS")
    {
        vector<double> result;
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<double> excepted = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
        CHECK(result == excepted);
    }

    SUBCASE("Min Heap")
    {
        vector<double> result;
        for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<double> excepted = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
        CHECK(result == excepted);
    }
}

TEST_CASE("Tree with k = 3")
{
    Node<int> root(3);
    Node<int> n1(5);
    Node<int> n2(6);
    Node<int> n3(8);
    Node<int> n4(9);
    Node<int> n5(11);
    Node<int> n6(12);
    Node<int> n7(13);

    Tree<int> tree(3);
    tree.add_root(root);
    tree.add_sub_node(root, n1);
    tree.add_sub_node(root, n2);
    tree.add_sub_node(root, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n1, n5);
    tree.add_sub_node(n2, n6);
    tree.add_sub_node(n2, n7);

    // The tree should look like:
    /**
     *         root = 3
     *       /      |   \
     *      5       6    8
     *    /  \     / \
     *   9    11 12   13
     */

    SUBCASE("DFS and BFS")
    {
        vector<int> bfsResult;
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            bfsResult.push_back(node->get_value());
        }
        vector<int> bfsExcpected = {3, 5, 6, 8, 9, 11, 12, 13};
        CHECK(bfsResult == bfsExcpected);

        vector<int> dfsResult;
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            dfsResult.push_back(node->get_value());
        }
        vector<int> dfsExcpected = {3, 5, 9, 11, 6, 12, 13, 8};
        CHECK(dfsResult == dfsExcpected);
    }

    SUBCASE("Min heap on a non-binary tree")
    {
        // Min heap should work on binary tree only , throw error when k > 2
        CHECK_THROWS_AS(tree.begin_heap(), runtime_error);
    }

    SUBCASE("Adding fourth kid")
    {
        // Adding fourth kid to a k = 3 tree should throw runtime error
        CHECK_THROWS_AS(tree.add_sub_node(root, n5), runtime_error);
    }
}

TEST_CASE("Tree with complex numbers")
{
    Node<Complex> root(Complex(2, 5));
    Node<Complex> n1(Complex(2, 2));
    Node<Complex> n2(Complex(1, 8));
    Node<Complex> n3(Complex(4, 32));
    Node<Complex> n4(Complex(1.5, 4));

    Tree<Complex> complexTree;
    complexTree.add_root(root);
    complexTree.add_sub_node(root, n1);
    complexTree.add_sub_node(root, n2);
    complexTree.add_sub_node(n1, n3);
    complexTree.add_sub_node(n1, n4);

    // The tree should look like:
    /**
     *       root = 2 + 5i
     *     /       \
     *    2 + 2i    1 + 8i
     *   /      \
     * 4+32i  1.5+4i
     */

    SUBCASE("PreOrder")
    {
        vector<Complex> result;
        for (auto node = complexTree.begin_pre_order(); node != complexTree.end_pre_order(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<Complex> excepted = {Complex(2, 5), Complex(2, 2), Complex(4, 32), Complex(1.5, 4), Complex(1, 8)};
        CHECK(result == excepted);
    }

    SUBCASE("PostOrder")
    {
        vector<Complex> result;
        for (auto node = complexTree.begin_post_order(); node != complexTree.end_post_order(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<Complex> excepted = {Complex(4, 32), Complex(1.5, 4), Complex(2, 2), Complex(1, 8), Complex(2, 5)};
        CHECK(result == excepted);
    }

    SUBCASE("InOrder")
    {
        vector<Complex> result;
        for (auto node = complexTree.begin_in_order(); node != complexTree.end_in_order(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<Complex> excepted = {Complex(4, 32), Complex(2, 2), Complex(1.5, 4), Complex(2, 5), Complex(1, 8)};
        CHECK(result == excepted);
    }

    SUBCASE("BFS")
    {
        vector<Complex> result;
        for (auto node = complexTree.begin_bfs_scan(); node != complexTree.end_bfs_scan(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<Complex> excepted = {Complex(2, 5), Complex(2, 2), Complex(1, 8), Complex(4, 32), Complex(1.5, 4)};
        CHECK(result == excepted);
    }

    SUBCASE("DFS")
    {
        vector<Complex> result;
        for (auto node = complexTree.begin_dfs_scan(); node != complexTree.end_dfs_scan(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<Complex> excepted = {Complex(2, 5), Complex(2, 2), Complex(4, 32), Complex(1.5, 4), Complex(1, 8)};
        CHECK(result == excepted);
    }

    SUBCASE("Min Heap")
    {
        vector<Complex> result;
        for (auto node = complexTree.begin_heap(); node != complexTree.end_heap(); ++node)
        {
            result.push_back(node->get_value());
        }

        vector<Complex> excepted = {Complex(2, 2), Complex(1.5, 4), Complex(2, 5), Complex(1, 8), Complex(4, 32)};
        CHECK(result == excepted);
    }
}

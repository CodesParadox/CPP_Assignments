/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include "complex.hpp"

using namespace std;

int main(){
    // Creating root node with a complex number value
    Complex root_value(1.1, 2);
    Node<Complex> root_node(root_value);
    Tree<Complex> tree; // Binary tree that contains Complex numbers.
    tree.add_root(&root_node);
    
    // Adding more nodes to the tree
    Node<Complex> n1(Complex(1.2, 3));
    Node<Complex> n2(Complex(1.3, 5.2));
    Node<Complex> n3(Complex(1.4, 7.0));
    Node<Complex> n4(Complex(1.5, 3.9));
    Node<Complex> n5(Complex(1.6, 4.1));

    // Building the tree structure
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1 + 2i
     *     /       \
     *    1.2 + 3i  1.3 + 5.2i
     *   /  \        /
     *  1.4  1.5    1.6
     */

    // Pre-order traversal
    cout << "Pre-order:" << endl; 
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 1.1 + 2i  1.2 + 3i  1.4 + 7i  1.5 + 3.9i  1.3 + 5.2i  1.6 + 4.1i 
    cout << endl << endl;

    // Post-order traversal
    cout << "Post-order:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 1.4 + 7i  1.5 + 3.9i  1.2 + 3i  1.6 + 4.1i  1.3 + 5.2i  1.1 + 2i 
    cout << endl << endl;

    // In-order traversal
    cout << "In-order:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 1.4 + 7i  1.2 + 3i  1.5 + 3.9i  1.1 + 2i  1.6 + 4.1i  1.3 + 5.2i 
    cout << endl << endl;

    // Breadth-First Search (BFS) traversal
    cout << "BFS:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 1.1 + 2i  1.2 + 3i  1.3 + 5.2i  1.4 + 7i  1.5 + 3.9i  1.6 + 4.1i 
    cout << endl << endl;

    // Depth-First Search (DFS) traversal
    cout << "DFS:" << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 1.1 + 2i  1.3 + 5.2i  1.6 + 4.1i  1.2 + 3i  1.5 + 3.9i  1.4 + 7i 
    cout << endl << endl;

    // Creating nodes for an N-ary tree
    Node<int> root(10);
    Node<int> node1(20);
    Node<int> node2(30);
    Node<int> node3(40);
    Node<int> node4(50);
    Node<int> node5(60);
    Node<int> node6(70);
    Node<int> node7(80);

    // N-ary tree with up to 3 children per node
    Tree<int> three_ary_tree(3); 
    three_ary_tree.add_root(&root);
    three_ary_tree.add_sub_node(root, node1);
    three_ary_tree.add_sub_node(root, node2);
    three_ary_tree.add_sub_node(root, node3);
    three_ary_tree.add_sub_node(node1, node4);
    three_ary_tree.add_sub_node(node1, node5);
    three_ary_tree.add_sub_node(node2, node6);
    three_ary_tree.add_sub_node(node3, node7);

    // The N-ary tree should look like:
    /**
     *         10
     *       / | \
     *     20  30  40
     *    / \  |    \
     *   50 60 70   80
     */

    // Pre-order traversal
    cout << "Pre-order:" << endl; 
    for (auto node = three_ary_tree.begin_pre_order(); node != three_ary_tree.end_pre_order(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 10  20  50  60  30  70  40  80
    cout << endl << endl;

    // Post-order traversal
    cout << "Post-order:" << endl;
    for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 50  60  20  70  30  80  40  10 
    cout << endl << endl;

    // // In-order traversal
    // cout << "In-order:" << endl;
    // for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node){
    //     cout << node->get_value() << "  ";
    // } // prints: 50  20  60  10  70  30  40  80
    // cout << endl << endl;

    // Breadth-First Search (BFS) traversal
    cout << "BFS:" << endl;
    for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 10  20  30  40  50  60  70  80
    cout << endl << endl;

    // Depth-First Search (DFS) traversal
    cout << "DFS:" << endl;
    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node){
        cout << node->get_value() << "  ";
    } // prints: 10  40  80  30  70  20  60  50
    cout << endl << endl;

    //three_ary_tree.displayTree();

    return 0;
}

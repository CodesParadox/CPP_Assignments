#include "doctest.h"
#include "tree.hpp"
#include "node.hpp"
#include "iterators.hpp"
#include "complex.hpp"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

/*
 * Author: Hadar Froimowich.
 * ID: 213118458
 * Email: hadarfro12@gmail.com
 */

using namespace doctest;
using namespace std;

TEST_CASE("Testing Tree with Integers") {
    Tree<int> intTree;
    Node<int> root(1);
    intTree.add_root(&root);
    Node<int> child1(2);
    Node<int> child2(3);
    intTree.add_sub_node(root, child1);
    intTree.add_sub_node(root, child2);

    SUBCASE("Test Pre-Order Traversal") {
        vector<int> expected{1, 2, 3};
        vector<int> test;
        for (auto node = intTree.begin_pre_order(); node != intTree.end_pre_order(); ++node){
            test.push_back(node->get_value());
        }
        CHECK(test == expected);
        
    }

    SUBCASE("Test Post-Order Traversal") {
        vector<int> expected{2, 3, 1};
        vector<int> test;
        size_t i = 0;
        for (auto node = intTree.begin_post_order(); node != intTree.begin_post_order(); ++node){
            test.push_back(node->get_value());
            CHECK(node->get_value() == expected[i]);
            i++;
        }
    }

    SUBCASE("Test In-Order Traversal") {
        vector<int> expected{2, 1, 3};
        vector<int> test;
        size_t i = 0;
        for (auto node = intTree.begin_in_order(); node != intTree.begin_in_order(); ++node){
            test.push_back(node->get_value());
            CHECK(node->get_value() == expected[i]);
            i++;
        }
        
    }

    SUBCASE("Test BFS Traversal") {
        vector<int> expected{1, 2, 3};
        vector<int> test;
        size_t i = 0;
        for (auto node = intTree.begin_bfs_scan(); node != intTree.begin_bfs_scan(); ++node){
            test.push_back(node->get_value());
            CHECK(node->get_value() == expected[i]);
            i++;
        }
    }
}

TEST_CASE("Test Tree Creation with Doubles") {
    Tree<double> doubleTree(3); // k-ary tree that contains doubles.
    Node<double> root(1.1);
    doubleTree.add_root(&root);
    Node<double> child1(1.2);
    Node<double> child2(1.3);
    doubleTree.add_sub_node(root, child1);
    doubleTree.add_sub_node(root, child2);

    SUBCASE("Test Pre-Order Traversal") {
        vector<double> expected{1.1, 1.2, 1.3};
        vector<double> test;
        size_t i = 0;
        for (auto node = doubleTree.begin_pre_order(); node != doubleTree.end_pre_order(); ++node){
            test.push_back(node->get_value());
            CHECK(node->get_value() == expected.at(i));
            i++;
        }
    }

    SUBCASE("Test Post-Order Traversal") {
        vector<double> expected{1.2, 1.3, 1.1};
        vector<double> test;
        size_t i = 0;
        for (auto node = doubleTree.begin_post_order(); node != doubleTree.end_post_order(); ++node){
            CHECK(node->get_value() == expected[i]);
            i++;
        }
    }

    SUBCASE("Test In-Order Traversal") {
        vector<double> expected{1.2, 1.1, 1.3};
        vector<double> test;
        size_t i = 0;
        for (auto node = doubleTree.begin_in_order(); node != doubleTree.end_in_order(); ++node){
            test.push_back(node->get_value());
            CHECK(node->get_value() == expected[i]);
            i++;
        }
    }

    SUBCASE("Test BFS Traversal") {
        vector<double> expected{1.1, 1.2, 1.3};
        vector<double> test;
        size_t i = 0;
        for (auto node = doubleTree.begin_bfs_scan(); node != doubleTree.end_bfs_scan(); ++node){
            test.push_back(node->get_value());
            CHECK(node->get_value() == expected[i]);
            i++;
        }
    }
}

TEST_CASE("Test Tree with Strings") {
    Tree<string> stringTree;
    Node<string> root("root");
    stringTree.add_root(&root);
    Node<string> child1("child1");
    Node<string> child2("child2");
    stringTree.add_sub_node(root, child1);
    stringTree.add_sub_node(root, child2);

    SUBCASE("Test Pre-Order Traversal") {
        vector<string> expected{"root", "child1", "child2"};
        vector<string> test;
        for (auto node = stringTree.begin_pre_order(); node != stringTree.end_pre_order(); ++node){
            test.push_back(node->get_value());
        }
        CHECK(test == expected);
    }

    SUBCASE("Test Post-Order Traversal") {
        vector<string> expected{"child1", "child2", "root"};
        vector<string> test;
        size_t i = 0;
        for (auto node = stringTree.begin_post_order(); node != stringTree.end_post_order(); ++node){
            test.push_back(node->get_value());
            CHECK(node->get_value() == expected[i]);
            i++;
        }
    }

    SUBCASE("Test In-Order Traversal") {
        vector<string> expected{"child1", "root", "child2"};
        vector<string> test;
        size_t i = 0;
        for (auto node = stringTree.begin_in_order(); node != stringTree.end_in_order(); ++node){
            test.push_back(node->get_value());
            CHECK(node->get_value() == expected[i]);
            i++;
        }
    }

    SUBCASE("Test BFS Traversal") {
        vector<string> expected{"root", "child1", "child2"};
        vector<string> test;
        size_t i = 0;
        for (auto node = stringTree.begin_bfs_scan(); node != stringTree.end_bfs_scan(); ++node){
            test.push_back(node->get_value());
            CHECK(node->get_value() == expected[i]);
            i++;
        }
    }

    SUBCASE("Test DFS Traversal") {
        vector<string> expected{"root", "child2", "child1"};
        vector<string> test;
        size_t i = 0;
        for (auto node = stringTree.begin_dfs_scan(); node != stringTree.end_dfs_scan(); ++node){
            test.push_back(node->get_value());
            CHECK(node->get_value() == expected[i]);
            i++;
        }
    }
}

TEST_CASE("Test Tree Creation") {
    Node<int> root(10);
    Node<int> child1(20);
    Node<int> child2(30);

    root.addChild(&child1);
    root.addChild(&child2);

    CHECK(root.get_value() == 10);
    CHECK(root.getChildren().size() == 2);
    CHECK(root.getChildren()[0]->get_value() == 20);
    CHECK(root.getChildren()[1]->get_value() == 30);
} 

TEST_CASE("Tree Operations") {
    SUBCASE("Adding root node") {
        Tree<int> tree;
        Node<int> root_node(10);

        tree.add_root(&root_node);

        REQUIRE(tree.getRoot() == &root_node);
    }

    SUBCASE("Adding sub-nodes") {
        Tree<int> tree;
        Node<int> root_node(10);
        tree.add_root(&root_node);

        Node<int> child1(20);
        Node<int> child2(30);

        REQUIRE_NOTHROW(tree.add_sub_node(root_node, child1));
        REQUIRE_NOTHROW(tree.add_sub_node(root_node, child2));

        // Verify the children were correctly added
        auto children = root_node.getChildren();
        REQUIRE(children.size() == 2);
        REQUIRE(children[0]->get_value() == 20);
        REQUIRE(children[1]->get_value() == 30);

        // Attempt to add more children than allowed
        Node<int> child3(40);
        Node<int> child4(50);
        Node<int> child5(60);

        CHECK_THROWS_AS(tree.add_sub_node(root_node, child4), runtime_error);
    }
}

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "node.hpp"
#include "tree.hpp"
using namespace sf;
using namespace std;

// Function to create a sample tree
template <typename T>
Tree<T>* createSampleTree() {
    Node<double> root_node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(&root_node);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    cout << "the node is: " << tree.getRoot()->get_value() << endl;
    return tree;
}

template <typename T>
void drawTree(RenderWindow& window, Node<T>* node, const Font& font, int x, int y, unsigned long level = 0) {
    if (!node) {
        return;
    }
    //constexpr int BASE_SPACING = 555;  // Base horizontal spacing
    int HORIZONTAL_SPACING = 555 / (level + 1);
    int VERTICAL_SPACING = 100;
    int RADIUS = 30;
    int childrenCount = node->getChildren().size();
    // Calculate horizontal spacing based on the number of children
    int offsetIncrement = HORIZONTAL_SPACING/ (childrenCount + 1);
    int startX = x - (childrenCount - 1) * offsetIncrement / 2;
        
    //Draw the value inside the node
    Text text(to_string(node->get_value()), font, 10);
    text.setFillColor(Color::White);
    float textWidth = text.getLocalBounds().width;
    float textHeight = text.getLocalBounds().height;
    text.setPosition(x - textWidth / 2, y - textHeight/2);

    //Draw the node itself
    CircleShape shape(RADIUS);
    shape.setFillColor(Color::Black);
    shape.setPosition(x-RADIUS, y-RADIUS);
        
    int childX = startX; 
    for(size_t i = 0; i < childrenCount; i++) {    
        int childY = y + VERTICAL_SPACING;
        
        // Draw line to child
        Vertex line[] = {
            Vertex(Vector2f(x, y + RADIUS),Color::White),
            Vertex(Vector2f(childX, childY - RADIUS),Color::Black)
        };
        window.draw(line, 2, Lines);
        Node<T>* n = node->getChildren().at(i);
        drawTree(window, node->getChildren()[i], font, childX, childY, level + 1);
        childX += offsetIncrement;
    }    
    window.draw(shape);
    window.draw(text);
}
    
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization with SFML");
    
    // Load font
    sf::Font font;
    if (!font.loadFromFile("/home/hadarfro/Downloads/Roboto/Roboto-Black.ttf")) {
        cerr << "Failed to load font 'arial.ttf'" << endl;
        return -1;
    }

    Node<double> root_node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(&root_node);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    Tree<double> three_ary_tree(3); // 3-ary tree.
    Node<double> root2_node(1.1);
    three_ary_tree.add_root(&root2_node);
    three_ary_tree.add_sub_node(root2_node, n1);
    three_ary_tree.add_sub_node(root2_node, n2);
    three_ary_tree.add_sub_node(root2_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    if(!three_ary_tree.getRoot()){
        return 0;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed){
                window.close();
            }
        }
        window.clear(Color::White);
        drawTree(window, three_ary_tree.getRoot(), font, 400, 50);
        window.display();
    }
    return 0;
}

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <cmath>
#include <memory>
#include <queue>
#include <stack>
#include <iterator>
#include "tree.hpp"
#include "node.hpp"

using namespace std;
using namespace sf;

template <typename T>
Node<T>* Tree<T>::find_node(Node<T>* node, T value) {
    if (!node){
     return nullptr;
    }
    if (node->get_value() == value){
        return node;
    }
    for (auto& child : node->getChildren()) {
        Node<T>* found = find_node(child, value);
        if (found){
            return found;
        } 
    }
    return nullptr;
}

template <typename T>
void drawTree(sf::RenderWindow& window, Node<T>* node, const sf::Font& font, int x, int y, unsigned long level = 0){
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

template <typename T>
void Tree<T>::displayTree(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization with SFML");
    
    // Load font
    sf::Font font;
    if (!font.loadFromFile("/home/hadarfro/Downloads/Roboto/Roboto-Black.ttf")) {
        cerr << "Failed to load font 'arial.ttf'" << endl;
        return ;
    }

    if(!getRoot()){
        return ;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed){
                window.close();
            }
        }
        window.clear(Color::White);
        drawTree(window, getRoot(), font, 400, 50);
        window.display();
    }
}

// Explicit template instantiation for int
//template class Tree<int>;

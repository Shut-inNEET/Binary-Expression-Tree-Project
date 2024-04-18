#ifndef BINARY_EXPRESSION_TREE_CLASS_H
#define BINARY_EXPRESSION_TREE_CLASS_H

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "binaryTree.h"

using namespace std;

class binaryExpressionTree : public binaryTree<string> {
public:
    
    // Builds an expression tree
    // Precondition: postfixExpression is a valid postfix expression string
    // Postcondition: A binary expression tree is built from the postfix expression
    void buildExpressionTree(const string& postfixExpression);
    
    // Evaluates the expression tree
    // Precondition: The binary expression tree has been built
    // Postcondition: The value of the expression represented by the binary expression tree is returned
    double evaluateExpressionTree();

    // Pure virtual functions from abstract class binaryTree
    bool search(const string& searchItem) const override;
    void insert(const string& insertItem) override;
    void deleteNode(const string& deleteItem) override;

private:
    
    // Function: Evaluates the expression tree
    // Precondition: The binary expression tree has been built correctly, and p points to a valid node in the tree.
    // Postcondition: The function recursively evaluates the expression tree rooted at the node pointed to by p and returns the result as a double value.
    double evaluateExpressionTree(nodeType<string>* p);
};

#endif
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
    void buildExpressionTree(const string& postfixExpression);
    double evaluateExpressionTree();
    virtual bool search(const string& value) = 0;
    virtual void insert(const string& value) = 0;
    virtual void deleteNode(const string& value) = 0;

private:
    double evaluateExpressionTree(nodeType<string>* p);
};

#endif
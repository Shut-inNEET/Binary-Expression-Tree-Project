#include "binaryExpressionTree_class.h"
#include <stack>
#include <cstring>
#include <cctype>
#include <sstream>

using namespace std;

void binaryExpressionTree::buildExpressionTree(const string& postfixExpression) {
    stack<nodeType<string>*> nodeStack;
    char* expression = new char[postfixExpression.length() + 1];
    strcpy_s(expression, postfixExpression.length() + 1, postfixExpression.c_str());

    char* next_token = nullptr;
    char* token = strtok_s(expression, " ", &next_token);
    while (token != nullptr) {
        if (isdigit(token[0]) || (token[0] == '-' && token[1] != '\0')) {
            nodeType<string>* newNode = new nodeType<string>;
            newNode->info = string(token);
            newNode->lLink = nullptr;
            newNode->rLink = nullptr;
            nodeStack.push(newNode);
        }
        else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            nodeType<string>* newNode = new nodeType<string>;
            newNode->info = string(1, token[0]);
            newNode->lLink = nullptr;
            newNode->rLink = nullptr;
            if (!nodeStack.empty()) {
                newNode->rLink = nodeStack.top();
                nodeStack.pop();
            }
            else {
                cout << "Error: Stack is empty" << endl;
                return;
            }
            if (!nodeStack.empty()) {
                newNode->lLink = nodeStack.top();
                nodeStack.pop();
            }
            else {
                cout << "Error: Stack is empty" << endl;
                return;
            }
            nodeStack.push(newNode);
        }
        else {
            cout << "Error: Unsupported token" << endl;
            return;
        }
        token = strtok_s(nullptr, " ", &next_token);
    }

    if (!nodeStack.empty()) {
        root = nodeStack.top();
        nodeStack.pop();
    }
    else {
        cout << "Error: Stack is empty" << endl;
        root = nullptr;
    }

    delete[] expression;
}


double binaryExpressionTree::evaluateExpressionTree() {
    return evaluateExpressionTree(root);
}

double binaryExpressionTree::evaluateExpressionTree(nodeType<string>* p) {
    if (p == nullptr) {
        return 0;
    }

    if (p->lLink == nullptr && p->rLink == nullptr) {
        return stod(p->info);
    }

    double x = evaluateExpressionTree(p->lLink);
    double y = evaluateExpressionTree(p->rLink);
    char op = p->info[0];

    switch (op) {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        cout << "Error: Unsupported operator" << endl;
        return 0;
    }
}

bool binaryExpressionTree::search(const string& value) {
    return false;
}

void binaryExpressionTree::insert(const string& value) {
}

void binaryExpressionTree::deleteNode(const string& value) {
}

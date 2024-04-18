#include <iostream>
#include <fstream>
#include <string>
#include "binaryExpressionTree_class.h"

using namespace std;

int main() {
    ifstream inFile("RpnData.txt");
    if (!inFile) {
        cout << "Unable to open the input file." << endl;
        return 1;
    }

    binaryExpressionTree expTree;
    string expression;

    while (getline(inFile, expression)) {
        expTree.destroyTree();  // Clear the current expression tree
        expTree.buildExpressionTree(expression);
        double result = expTree.evaluateExpressionTree();
        cout << "Expression: " << expression << " = " << result << endl;
    }

    inFile.close();
    return 0;
}

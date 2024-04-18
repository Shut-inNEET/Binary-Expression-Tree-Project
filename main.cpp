#include <iostream>
#include <fstream>
#include <string>
#include "binaryExpressionTree_class.h"

using namespace std;

int main() {
    ifstream inFile("RpnData.txt"); // Open the input file
    ofstream outFile("OutData.txt"); // Open the output file

    if (!inFile) {
        cout << "Unable to open RpnData.txt" << endl;
        return 1;
    }

    if (!outFile) {
        cout << "Unable to open OutData.txt" << endl;
        return 1;
    }

    binaryExpressionTree expTree;
    string expression;

    while (getline(inFile, expression)) {
        expTree.destroyTree();  // Clear the current expression tree
        expTree.buildExpressionTree(expression);
        double result = expTree.evaluateExpressionTree();
        outFile << "Expression: " << expression << " = " << result << endl;
    }

    inFile.close(); // Close the input file
    outFile.close(); // Close the output file

    return 0;
}

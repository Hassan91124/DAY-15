#include <iostream>
#include <map>
#include <stack>

using namespace std;

// Function to evaluate simple expressions
double evaluateExpression(string expression, map<string, double> variables) {
    stack<double> values;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') continue;

        if (isdigit(expression[i])) {
            double value = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                value = (value * 10) + (expression[i] - '0');
                i++;
            }
            values.push(value);
            i--;
        } else if (isalpha(expression[i])) {
            string var;
            while (i < expression.length() && isalpha(expression[i])) {
                var += expression[i];
                i++;
            }
            values.push(variables[var]);
            i--;
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = operators.top(); operators.pop();

                switch (op) {
                    case '+': values.push(val1 + val2); break;
                    case '-': values.push(val1 - val2); break;
                    case '*': values.push(val1 * val2); break;
                    case '/': values.push(val1 / val2); break;
                }
            }
            operators.pop();
        } else {
            while (!operators.empty() && (operators.top() == '*' || operators.top() == '/') &&
                   (expression[i] == '+' || expression[i] == '-')) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = operators.top(); operators.pop();

                switch (op) {
                    case '+': values.push(val1 + val2); break;
                    case '-': values.push(val1 - val2); break;
                    case '*': values.push(val1 * val2); break;
                    case '/': values.push(val1 / val2); break;
                }
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = operators.top(); operators.pop();

        switch (op) {
            case '+': values.push(val1 + val2); break;
            case '-': values.push(val1 - val2); break;
            case '*': values.push(val1 * val2); break;
            case '/': values.push(val1 / val2); break;
        }
    }

    return values.top();
}

int main() {
    map<string, double> variables;
    variables["x"] = 5.0;
    variables["y"] = 3.0;

    string expression;
    cout << "Enter a mathematical expression: ";
    getline(cin, expression);

    double result = evaluateExpression(expression, variables);
    cout << "Result of expression: " << result << endl;

    return 0;
}

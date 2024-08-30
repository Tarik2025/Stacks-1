#include <iostream>
#include <stack>

void removeKthElement(std::stack<int>& s, int k) {
    std::stack<int> tempStack;

    // Check if k is valid
    if (k <= 0 || k > s.size()) {
        std::cerr << "Invalid k value" << std::endl;
        return;
    }

    // Move top k elements to tempStack
    for (int i = 0; i < k; ++i) {
        tempStack.push(s.top());
        s.pop();
    }

    // Remove the kth element (which is at the top of tempStack)
    tempStack.pop();

    // Move the remaining elements back to s
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

// Function to print stack elements
void printStack(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    std::cout << "Original stack: ";
    printStack(s);

    int k = 3; // Specify the kth element to remove
    removeKthElement(s, k);

    std::cout << "Stack after removing the " << k << "th element from the top: ";
    printStack(s);

    return 0;
}


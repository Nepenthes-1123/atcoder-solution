#include <iostream>

class Node {
   private:
    const Node* leftNode;
    const Node* rightNode;
    const int n;

   public:
    Node(const int n) : n{n} {
        if (n < 3) {
            return;
        }
        leftNode = new Node{n - 1};
        rightNode = new Node{n - 2};
    };

    int Calc() const {
        int result = n;
        std::cout << "now" << std::endl;
        if (leftNode != nullptr) {
            result += leftNode->Calc();
        }

        if (rightNode != nullptr) {
            result += rightNode->Calc();
        }

        return result;
    }
};

int main() {
    const Node rootNode{6};
    std::cout << rootNode.Calc() << std::endl;

    return 0;
}

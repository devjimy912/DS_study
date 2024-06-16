#include <iostream>
#include "AVLTree.h"

using namespace std;

int main() {
    AVL<int, std::string> avlTree;

    // Insertion tests
    std::cout << "Inserting LL case: 10, 5, 15, 2, 7\n";
    avlTree.Insert(10, "Node 10");
    avlTree.Insert(5, "Node 5");
    avlTree.Insert(15, "Node 15");
    avlTree.Insert(2, "Node 2");
    avlTree.Insert(7, "Node 7");
    std::cout << "Tree structure after LL case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    std::cout << "Inserting LR case: 10, 5, 15, 7, 12\n";
    avlTree.Insert(12, "Node 12");
    std::cout << "Tree structure after LR case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    std::cout << "Inserting RR case: 10, 5, 15, 12, 20\n";
    avlTree.Insert(20, "Node 20");
    std::cout << "Tree structure after RR case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    std::cout << "Inserting RL case: 10, 5, 15, 12, 17\n";
    avlTree.Insert(17, "Node 17");
    std::cout << "Tree structure after RL case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    // Deletion tests
    std::cout << "Deleting L0 case: 5\n";
    avlTree.Delete(5);
    std::cout << "Tree structure after L0 case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    std::cout << "Deleting L1 case: 12\n";
    avlTree.Delete(12);
    std::cout << "Tree structure after L1 case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    std::cout << "Deleting L-1 case: 15\n";
    avlTree.Delete(15);
    std::cout << "Tree structure after L-1 case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    return 0;
}
#include <iostream>
#include "AVLTree.h"

int main() {
    AVL<int, std::string> avlTree;

    // Insertion tests
    std::cout << "Inserting LL case: 10, 7, 5\n";
    avlTree.Insert(10, "Node 10");
    avlTree.Insert(7, "Node 7");
    avlTree.Insert(5, "Node 5");
    std::cout << "Tree structure after LL case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    std::cout << "Inserting LR case: 10, 7, 5, 3, 1\n";
    avlTree.Insert(3, "Node 3");
    avlTree.Insert(1, "Node 1");
    std::cout << "Tree structure after LR case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    std::cout << "Deleting R0 case: 10\n";
    avlTree.Delete(10);
    std::cout << "Tree structure after R0 case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    std::cout << "Deleting L1 case: 1\n";
    avlTree.Delete(1);
    std::cout << "Tree structure after L1 case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    std::cout << "Inserting RR case: 3, 5, 7, 9, 11\n";
    avlTree.Insert(9, "Node 9");
    // avlTree.PrintTree();
    avlTree.Insert(11, "Node 11");
    std::cout << "Tree structure after RR case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    std::cout << "Deleting L0 case: 3\n";
    avlTree.Delete(3);
    std::cout << "Tree structure after L0 case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    std::cout << "Deleting R-1 case: 11\n";
    avlTree.Delete(11);
    std::cout << "Tree structure after R-1 case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    std::cout << "Inserting RL case: 5, 7, 9, 11, 13\n";
    avlTree.Insert(13, "Node 13");
    // avlTree.PrintTree();
    avlTree.Insert(11, "Node 11");
    std::cout << "Tree structure after RL case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;

    //Remaining : L-1, R1

    //for L-1 deletion
    std::cout << "Deletion Setting L-1 case: 3, 5, 7, 9, 11, 13, 15\n";
    avlTree.Insert(3, "Node 3");
    avlTree.Insert(15, "Node 15");
    avlTree.PrintTree();

    //Deletion case L-1
    std::cout << "Deleting L-1 case: 3\n";
    avlTree.Delete(3);
    std::cout << "Tree structure after L-1 case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;
    
    //for R1 deletion
    std::cout << "Deletion Setting R1 case: 3, 5, 7, 9, 11, 13, 15\n";
    avlTree.Insert(3, "Node 3");
    avlTree.PrintTree();

    //Deletion case R1
    std::cout << "Deleting R1 case: 15\n";
    avlTree.Delete(15);
    std::cout << "Tree structure after R1 case:\n";
    avlTree.PrintTree();
    std::cout << std::endl;


    return 0;
}
#include <iostream>
#include "AVLTree.h"

using namespace std;

int main(){
    AVL<int, std::string> avlTree;

    // Insertion Test
    avlTree.Insert(10, "Ten");
    avlTree.Insert(20, "Twenty");
    avlTree.Insert(30, "Thirty");
    avlTree.Insert(40, "Forty");
    avlTree.Insert(50, "Fifty");
    avlTree.Insert(25, "Twenty-Five");
    cout << "InOrder Traversal after insertion: ";
    avlTree.PrintInOrder(); // Expected: 10 20 25 30 40 50

    // Search Test
    try {
        cout << "Search key 30: " << avlTree.Search(30) << endl; // Expected: Thirty
        cout << "Search key 50: " << avlTree.Search(50) << endl; // Expected: Fifty
    } catch (std::runtime_error& e) {
        cout << e.what() << endl;
    }

    // Delete Test
    avlTree.Delete(10);
    avlTree.Delete(20);
    avlTree.Delete(30);
    cout << "InOrder Traversal after deletion: ";
    avlTree.PrintInOrder(); // Expected: 25 40 50

    return 0;
}
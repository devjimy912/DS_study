#include "HashTable.h"

int main() {
    HashTable<int, int> hashTable(10);

    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(13, 120);
    hashTable.insert(22, 220);

    std::cout << "Value for key 2: " << hashTable.search(2) << std::endl;
    std::cout << "Value for key 12: " << hashTable.search(12) << std::endl;

    hashTable.display();

    hashTable.remove(22);
    std::cout << "After removing key 22:" << std::endl;
    hashTable.display();

    return 0;
}
#include "HashTable.h"

int main() {
    // HashTable<int, int> hashTable(10);

    // hashTable.insert(1, 10);
    // hashTable.insert(2, 20);
    // hashTable.insert(13, 120);
    // hashTable.insert(22, 220);

    // std::cout << "Value for key 2: " << hashTable.search(2) << std::endl;
    // std::cout << "Value for key 12: " << hashTable.search(12) << std::endl;

    // hashTable.display();

    // hashTable.remove(22);
    // std::cout << "After removing key 22:" << std::endl;
    // hashTable.display();

    // return 0;

    std::cout << "Hash Table with bucket size 10:" << std::endl;
    HashTable<int, std::string> hashTable10(10);

    hashTable10.insert(1, "one");
    hashTable10.insert(2, "two");
    hashTable10.insert(3, "three");
    hashTable10.insert(4, "four");
    hashTable10.insert(5, "five");
    hashTable10.insert(6, "six");
    hashTable10.insert(7, "seven");
    hashTable10.insert(8, "eight");
    hashTable10.insert(9, "nine");
    hashTable10.insert(10, "ten");
    hashTable10.insert(11, "one1");
    hashTable10.insert(21, "two1");
    hashTable10.insert(31, "three1");
    hashTable10.insert(41, "four1");
    hashTable10.insert(51, "five1");
    hashTable10.insert(61, "six1");
    hashTable10.insert(71, "seven1");
    hashTable10.insert(81, "eight1");
    hashTable10.insert(91, "nine1");
    hashTable10.insert(101, "ten1");

    hashTable10.display();

    std::cout << "Hash Table with bucket size 11:" << std::endl;
    HashTable<int, std::string> hashTable11(11);

    hashTable11.insert(1, "one");
    hashTable11.insert(2, "two");
    hashTable11.insert(3, "three");
    hashTable11.insert(4, "four");
    hashTable11.insert(5, "five");
    hashTable11.insert(6, "six");
    hashTable11.insert(7, "seven");
    hashTable11.insert(8, "eight");
    hashTable11.insert(9, "nine");
    hashTable11.insert(10, "ten");
    hashTable11.insert(11, "one1");
    hashTable11.insert(21, "two1");
    hashTable11.insert(31, "three1");
    hashTable11.insert(41, "four1");
    hashTable11.insert(51, "five1");
    hashTable11.insert(61, "six1");
    hashTable11.insert(71, "seven1");
    hashTable11.insert(81, "eight1");
    hashTable11.insert(91, "nine1");
    hashTable11.insert(101, "ten1");

    hashTable11.display();

    return 0;
}
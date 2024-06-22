#include <iostream>
#include <utility> // for std::pair
#include <functional> // for std::hash


template <typename K, typename V>
class HashTable{
private:
    struct Node{
        // pair is a built-in data structure that can hold a key and value pair.
        // https://en.cppreference.com/w/cpp/utility/pair
        // as in the reference, to create a pair, use the make_pair function for the insert function.
        std::pair<K, V> data;
        Node *next;
        Node(const K &key, const V &value) : data(std::make_pair(key, value)), next(nullptr) {}
    };

    Node **table; // hash table

    int size;

    int hashFunction(const K &key) const{
        return std::hash<K>{}(key) % size;
    }

public:
    HashTable(int size); // constructor
    ~HashTable(); // destructor
    void insert(const K &key, const V &value); //
    V search(const K &key) const;
    void remove(const K &key);
    void display() const;
};

// implement functions here
template <typename K, typename V>
HashTable<K, V>::HashTable(int size) : size(size){
    // std::cout<<"Make HAshTable"<<std::endl;
    table = new Node*[size]();
}

template <typename K, typename V>
HashTable<K, V>::~HashTable(){
    for (int i = 0; i < size; ++i){
        Node *entry = table[i];
        while (entry != nullptr){
            Node *prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] table;
}

template <typename K, typename V>
void HashTable<K, V>::insert(const K &key, const V &value){
    // std::cout<<"Call insert"<<std::endl;
    int hashValue = hashFunction(key);
    Node *prev = nullptr;
    Node *entry = table[hashValue];

    while (entry != nullptr && entry->data.first != key){
        prev = entry;
        entry = entry->next;
    }

    if (entry == nullptr){
        entry = new Node(key, value);
        if (prev == nullptr){
            table[hashValue] = entry;
        }else{
            prev->next = entry;
        }
    }else{
        entry->data.second = value;
    }
}

template <typename K, typename V>
V HashTable<K, V>::search(const K &key) const{
    // std::cout<<"Call search"<<std::endl;
    int hashValue = hashFunction(key);
    Node *entry = table[hashValue];

    while (entry != nullptr){
        if (entry->data.first == key){
            return entry->data.second;
        }
        entry = entry->next;
    }

    return V();
}

template <typename K, typename V>
void HashTable<K, V>::remove(const K &key){
    int hashValue = hashFunction(key);
    Node *prev = nullptr;
    Node *entry = table[hashValue];

    while (entry != nullptr && entry->data.first != key){
        prev = entry;
        entry = entry->next;
    }

    if (entry == nullptr){
        throw std::runtime_error("Key not found");
    }else{
        if (prev == nullptr){
            table[hashValue] = entry->next;
        }else{
            prev->next = entry->next;
        }
        delete entry;
    }
}

template <typename K, typename V>
void HashTable<K, V>::display() const{
    for (int i = 0; i < size; ++i){
        Node *entry = table[i];
        if (entry == nullptr){
            std::cout << "Bucket " << i << ": " << std::endl;
            continue;
        }

        std::cout << "Bucket " << i << ": ";
        while (entry != nullptr){
            std::cout << "[" << entry->data.first << ", " << entry->data.second << "] ";
            entry = entry->next;
        }
        std::cout << std::endl;
    }
}
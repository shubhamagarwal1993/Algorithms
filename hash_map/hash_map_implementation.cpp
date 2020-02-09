/*
 * A simple implementation of a hash map with insert and find functions
 * A hash table uses a hash function to compute an index into an array of buckets or slots, from which the corresponding value can be found
 *
 * Missing functionality:
 *     Iterators for traversal
 *     Comparator for key comparisons
 *     Capacity and size functions
 */

#include <iostream>

using namespace std;
#define TABLE_SIZE 10

// Hash node class template
template <typename K, typename V>
class HashNode {
    private:
        K key;
        V value;

        // next bucket with the same key
        HashNode *next;

    public:

        HashNode(const K key, const V value) {
            this->key = key;
            this->value = value;
            this->next = NULL;
        }

        K getKey() const {
            return this->key;
        }

        V getValue() const {
            return this->value;
        }

        void setValue(V value) {
            this->value = value;
        }

        HashNode *getNext() const {
            return this->next;
        }

        void setNext(HashNode *next) {
            this->next = next;
        }

};

// Default hash function class takes a key, converts it to unsigned long int, and takes mod
template <typename K>
struct KeyHash {
    unsigned long operator()(const K key) const {
        return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
    }
};

struct MyKeyHash {
    unsigned long operator()(const int k) const {
        return k % 10;
    }
};

// Hash map class template
template <typename K, typename V, typename F = KeyHash<K>>
class HashMap {
    private:
        // hash table
        HashNode<K, V> **table;
        F hashFunc;

    public:
        HashMap() {
            // construct zero initialized hash table of size
            table = new HashNode<K, V> *[TABLE_SIZE]();
        }

        ~HashMap() {
            // destroy all buckets one by one
            for (int i = 0; i < TABLE_SIZE; ++i) {
                HashNode<K, V> *entry = table[i];
                while (entry != NULL) {
                    HashNode<K, V> *prev = entry;
                    entry = entry->getNext();
                    delete prev;
                }
                table[i] = NULL;
            }
            // destroy the hash table
            delete [] table;
        }

        bool get(const K key, V &value) {
            unsigned long hashValue = hashFunc(key);
            HashNode<K, V> *entry = table[hashValue];

            while (entry != NULL) {
                if (entry->getKey() == key) {
                    value = entry->getValue();
                    return true;
                }
                entry = entry->getNext();
            }
            return false;
        }

        void put(const K key, const V value) {
            unsigned long hashValue = hashFunc(key);
            HashNode<K, V> *prev = NULL;
            HashNode<K, V> *entry = table[hashValue];

            while (entry != NULL && entry->getKey() != key) {
                prev = entry;
                entry = entry->getNext();
            }

            if (entry == NULL) {
                entry = new HashNode<K, V>(key, value);
                if (prev == NULL) {
                    // insert as first bucket
                    table[hashValue] = entry;
                } else {
                    prev->setNext(entry);
                }
            } else {
                // just update the value
                entry->setValue(value);
            }
        }

        void remove(const K key) {
            unsigned long hashValue = hashFunc(key);
            HashNode<K, V> *prev = NULL;
            HashNode<K, V> *entry = table[hashValue];

            while (entry != NULL && entry->getKey() != key) {
                prev = entry;
                entry = entry->getNext();
            }

            if (entry == NULL) {
                // key not found
                return;
            }
            else {
                if (prev == NULL) {
                    // remove first bucket of the list
                    table[hashValue] = entry->getNext();
                } else {
                    prev->setNext(entry->getNext());
                }
                delete entry;
            }
        }
};

int main() {
    HashMap<int, string, MyKeyHash> hmap;

    // insert
    hmap.put(1, "val1");
    hmap.put(2, "val2");
    hmap.put(3, "val3");

    // find
    string value;
    hmap.get(2, value);
    cout << value << endl;

    // find
    bool res = hmap.get(3, value);
    if(res) {
        cout << value << endl;
    }

    // remove
    hmap.remove(3);
    res = hmap.get(3, value);
    if(res) {
        cout << value << endl;
    }

    return 0;
}

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// LRU - remove the least recently used when cache is full
// Given
//      Total possible page numbers
//      Cache of memory size - number of page frames that cache can hold at a time
//
// Data structures:
//      Queue       : Doubly linked list, size = max page frames that cache needs to hold
//                    most recently used pages in the front of queue, and least recently at end
//      Hash table  : Page number as key and address of the corresponding queue node as value

class LRUCache {

    private:
        // store keys of cache
        list<int> cache_list;

        // store references of key in cache
        unordered_map<int, list<int>::iterator> cache_map;

        // Maximum capacity of cache
        int cache_size;

    public:

        // constructor
        LRUCache(int cache_size);

        // add page to cache
        void add(int page);

        // print cache contents
        void display();
};

// constructor
LRUCache::LRUCache(int cache_size) {
    this->cache_size = cache_size;
}
 
// add page to cache
void LRUCache::add(int page) {

    // page not in cache
    if(cache_map.find(page) == cache_map.end()) {

        // cache is full
        if(cache_list.size() == cache_size) {
            //delete least recently used element
            int lru_page = cache_list.back();
            cache_list.pop_back();
            cache_map.erase(lru_page);
        }
    } else {
        cache_list.erase(cache_map[page]);
    }

    // update reference
    cache_list.push_front(page);
    cache_map[page] = cache_list.begin();
}
 
// display contents of cache
void LRUCache::display() {

    for(auto it = cache_map.begin(); it != cache_map.end(); it++) {
        cout << it->first << " ";
    }

    cout << endl;
}

int main() {

    // make cache object
    LRUCache cache(4);

    cache.add(1);
    cache.add(2);
    cache.add(3);
    cache.add(1);
    cache.add(4);
    cache.add(5);
    cache.display();

    return 0;
}


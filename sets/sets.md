Sets

- containers, each element has to be unique because the value of the element defines it

functions associated with set
- begin()
- end()
- size()
- max_size()
- empty()
- insert() [ pair <iterator, bool> insert(const g) ]
- iterator insert (iterator position, const g) – Adds a new element ‘g’ at the position pointed by iterator
- erase(iterator position) – Removes the element at the position pointed by the iterator
- erase(const g)- Removes the value ‘g’ from the set
- clear() – Removes all the elements from the set
- find(const g) – Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end
- count(const g) – Returns 1 or 0 based on the element ‘g’ is present in the set or not

Disjoint data sets
- disjoint-set data structure or union-find data structure, or merge-find set is a data structure that keeps track of a set of elements partitioned into a number of disjoint subsets
- provides near constant time operations:
  - add new sets
  - merge existing sets
  - determine whether elements are in the same set
- common operations:
  - makeSet - makes a new set by creating a new element with a unique id, rank 0, and parent pointer to itself, to show only element in set
  - find(x) - follows chain of parent pointers up till an element is a parent of itself. This is the root of the tree and representative of the set to which x belongs
  - union(x, y) - finds roots of trees x and y and combines them by rank


Implementation for sets:
```
#include <iostream>
#include <set>
#include <iterator>
 
using namespace std;
 
int main() {
    // empty set container
    set <int, greater <int> > gquiz1;
 
    // insert elements in random order
    gquiz1.insert(40);
    gquiz1.insert(30);
    gquiz1.insert(60);
    gquiz1.insert(50);
    gquiz1.insert(50); // only one 50 will be added to the set
    gquiz1.insert(10);
 
    // printing set gquiz1
    set <int, greater <int> > :: iterator itr;
    cout << "\nThe set gquiz1 is : ";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        cout << '\t' << *itr;
    }
    cout << endl;
 
    // assigning the elements from gquiz1 to gquiz2
    set <int> gquiz2(gquiz1.begin(), gquiz1.end());
 
    // remove all elements up to 30 in gquiz2
    cout << "\ngquiz2 after removal of elements less than 30 : ";
    gquiz2.erase(gquiz2.begin(), gquiz2.find(30));
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << *itr;
    }
 
    // remove all elements with value 50 in gquiz2
    int num;
    num = gquiz2.erase(50);
    cout << "\ngquiz2.erase(50) : ";
    cout << num << " removed \t" ;
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << *itr;
    }
 
    cout << endl;
 
    return 0;
}
```

// https://stackoverflow.com/questions/1106929/how-to-find-all-combinations-of-coins-when-given-some-dollar-value#comment15033239_1107115
// Infinite number of quarters, dime, nickles, and pennies.
// Number of ways of representing n cents

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int countWays_iterative(int total) {

    // memoize
    int table[total+1];

    memset(table, 0, sizeof(table));

    // base case - if total is 0
    table[0] = 1;

    for(int i = 1; i <= total; i++) {
        table[i] += table[i-1];
    }

    for(int i = 5; i <= total; i++) {
        table[i] += table[i-5];
    }

    for(int i = 10; i <= total; i++) {
        table[i] += table[i-10];
    }

    for(int i = 25; i <= total; i++) {
        table[i] += table[i-25];
    }

    return table[total];
}

int countWays_recursive(int total, int denominations[], int denom_len, int index, int sum) {

    // End of all possible denominations
    if((total == 0) || (index + 1 == denom_len) {
        // if total is not reached but all combinations are over
        if((left > 0) && ())
    }

    int denomAmount = denominations[index];

    // total ways
    return countWays_recursive(total

//def count_combs(left, i, comb, add):
//    if add: comb.append(add)
//    if left == 0 or (i+1) == len(denominations):
//        if (i+1) == len(denominations) and left > 0:
//            comb.append( (left, denominations[i]) )
//            i += 1
//        while i < len(denominations):
//            comb.append( (0, denominations[i]) )
//            i += 1
//        print " ".join("%d %s" % (n,names[c]) for (n,c) in comb)
//        return 1
//    cur = denominations[i]
//
//
//    return sum(count_combs(left-x*cur, i+1, comb[:], (x,cur)) for x in range(0, int(left/cur)+1))
}

int main() {

    // total value
    int total = 10;
    int denominations[] = {25, 10, 5, 1};

    unordered_map<int, string> names;
    names[1] = "pennies";
    names[5] = "nickels";
    names[10] = "dimes";
    names[25] = "quarters";

    cout << countWays_iterative(total) << endl;
    cout << countWays_recursive(total, denominations, 4, 0) << endl;
    return 0;
}


#include <unordered_map>
#include <vector>
#include <iostream>
#include <iterator>

std::vector<int> customSort(std::vector<int> const& arr) {
    std::unordered_map<int, int> frequencyMap;
    for (int val: arr) {
        ++frequencyMap[val];
    }

    using Val = std::pair<int, int>;
    std::vector<Val>  values(std::begin(frequencyMap), std::end(frequencyMap));
    std::sort(std::begin(values), std::end(values), [](Val const& lhs, Val const& rhs) {
            return (lhs.second < rhs.second) || (lhs.second == rhs.second && lhs.first < rhs.first);
          });

    std::vector<int> result;
    result.reserve(arr.size());
    for(auto const& val: values) {
        for(int loop = 0;loop < val.second; ++loop) {
            result.push_back(val.first);
        }
    }
    return result;
}

int main() {
    std::vector<int> arr;

    int n;
    std::cin >> n;
    std::copy_n(std::istream_iterator<int>(std::cin), n,
            std::back_inserter(arr));

    std::vector<int> sorted = customSort(arr);
    std::copy(std::begin(sorted), std::end(sorted),
              std::ostream_iterator<int>(std::cout, "\n"));
}



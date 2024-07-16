#include <vector>
#include <iostream>

template <typename T>
class Set {
private:
    std::vector<T> elements;

public:
    class Iterator {
    private:
        typename std::vector<T>::iterator current;

    public:
        Iterator(typename std::vector<T>::iterator iter) : current(iter) {}

        T& operator*() {
            return *current;
        }

        Iterator& operator++() {
            ++current;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    bool insert(const T& value) {
        if (contains(value)) {
            return false; 
        }
        elements.push_back(value);
        return true;
    }

    bool contains(const T& value) const {
        for (const auto& elem : elements) {
            if (elem == value) {
                return true;
            }
        }
        return false;
    }

    Iterator begin() {
        return Iterator(elements.begin());
    }

    Iterator end() {
        return Iterator(elements.end());
    }
};

int main() {
    Set<int> mySet;

    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);

    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
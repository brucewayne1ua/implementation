#include <iostream>
#include <algorithm>
#include <initializer_list> // C++11
#include <cstring>

class String {
private:
    char* arr = nullptr;
    size_t size = 0;
    size_t capacity = 0;
private:
    String(size_t n): arr(new char[n + 1]), size(n), capacity(n + 1) { // Delegating constructor (C++11)
        arr[size] = '\0';
    }
public:
    String() = default; // C++11
    
    String(size_t n, size_t c): String(n) {
        memset(arr, c, n);
    }

    String(std::initializer_list<char> list): String(list.size()) {
        std::copy(list.begin(), list.end(), arr);
    }

    String(const String& other): String(other.size) {
        memcpy(arr, other.arr, size + 1);
    }

    String& operator=(const String& other) {
        if (this == &other) return *this; 
        delete[] arr;
        size = other.size;
        capacity = other.capacity;
        arr = new char[other.capacity];
        memcpy(arr, other.arr, size + 1);
        return *this;
    }

    ~String() {
        delete[] arr;
    }
};

int main() {
    String s = {'a', 'b', 'c', 'd', 'e'};

    
}
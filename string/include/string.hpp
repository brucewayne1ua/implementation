
#pragma once

#include <iostream>
#include <algorithm>
#include <initializer_list> 
#include <cstring>


namespace rsl
{

    class String
    {
    private:

        char* arr = nullptr;
        size_t size = 0;
        size_t capacity = 0;

    private:

        String(size_t n): arr(new char[n + 1]), size(n), capacity(n + 1)
        {
            arr[size] = '\0';
        }

    public:
           
        String() = default;
    

        String(size_t n, size_t c): String(n)
        {
            std::memset(arr, c, n);
        }


        String(std::initializer_list<char> list): String(list.size())
        {
            std::copy(list.begin(), list.end(), arr);
        }


        String(const String& other): String(other.size)
        {
            std::memcpy(arr, other.arr, size + 1);
        }


        ~String()
        {
            delete[] arr;
        }


    public:
        
        String& operator=(const String& other)
        {
            if (this == &other) return *this; 
            delete[] arr;
            size = other.size;
            capacity = other.capacity;
            arr = new char[other.capacity];
            std::memcpy(arr, other.arr, size + 1);
            return *this;
        }


        String operator+(const String& other) const 
        {
            String result;
            result.size = size + other.size;
            result.capacity = result.size; 
            result.arr = new char[result.capacity + 1];
            std::memcpy(result.arr, arr, size);
            std::memcpy(result.arr + size, other.arr, other.size + 1);
            return result;
        }


    public:
        
        int length()
        {
            return size;
        }


    };


} 
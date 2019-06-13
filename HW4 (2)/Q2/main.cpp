#include <iostream>
#include <vector>
#include <memory>
#include <bits/unique_ptr.h>

template<typename T>
void capacity(std::vector<std::unique_ptr<T>>);
template<typename T>
void size(std::vector<T>);

int main()
{
    std::vector<std::unique_ptr<std::string>> vec[1000];
    for (int i{}; i <1000 ; i++) {
        std::unique_ptr<std::string> ptr(new std::string("STR "+std::to_string(i)));
        vec->push_back(std::move(ptr));
        capacity(vec);
        size(vec);
    }
    return 0;

}

template<typename T>
void capacity(std::vector<std::unique_ptr<T>>) {

}

template<typename T>
void size(std::vector<T>){

}

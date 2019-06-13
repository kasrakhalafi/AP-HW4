#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

template <class T>
void removingTwo(std::vector<T>& numbers);

template <class T>
void erasingTwo(std::vector<T>& numbers);

template <class T>
void multiplybyTwo(std::vector<T>& numbers);

template <class T>
void sortingAvg(std::vector<T>& numbers);

template <class T>
void removingDuplicate(std::vector<T>& numbers);

template <class T>
void setFunc(std::vector<T>&);

template <class T>
void setFuncRemove(std::vector<T>&);

int main(){

    std::vector<int> vec{1,2,3,4,5,4,3,2,1};
    //removingTwo(vec);//for alef
    //erasingTwo(vec);//for alef
    //multiplybyTwo(vec);//for be
    //removingDuplicate(vec);
    //setFunc(vec);
    setFuncRemove(vec);


    return 0;
}

template <class T>
void removingTwo(std::vector<T>& numbers)
{
    std::remove(begin(numbers),end(numbers), 2 );
    std::cout << "After Removing the Two : " ;
    for(auto x:numbers){
        std::cout << x << ", ";
    }
    std::cout << std::endl;

}

template <class T>
void erasingTwo(std::vector<T>& numbers)
{
    auto first_to_erase{ std::remove(begin(numbers),end(numbers), 2 )};
    numbers.erase(first_to_erase, end(numbers));
    std::cout << "After Erasing the Two : " ;
    for(auto x:numbers){
        std::cout << x << ", ";
    }
    std::cout << std::endl;
}


template <class T>
void multiplybyTwo(std::vector<T>& numbers){

    std::for_each(numbers.begin(), numbers.end(), [](int &i) { i *= 2; });
    std::cout << "After Erasing the Two : " ;
    for(auto x:numbers){
        std::cout << x << " ";
    }
    std::cout << std::endl;


}



template <class T>
void sortingAvg(std::vector<T>& numbers){
/*
auto nearer { [=](int x, int y) {
    return std::abs(x - number_to_search_for) < std::abs(y - number_to_search_for);
}*/};

template <class T>
void removingDuplicate(std::vector<T>& vec) {
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    for(auto x:vec){
        std::cout << x << " ";
    }
    std::cout << std::endl;

}


template <class T>
void setFunc(std::vector<T>& vec) {
    std::set<int, std::greater <T> > gquiz1;
    for(int i{};i<vec.size();i++)
    {
        gquiz1.insert(vec[i]);
    }

    for(auto x:gquiz1){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // std::set<int> g(vec.begin(), vec.end());
}


template <class T>
void setFuncRemove(std::vector<T>& vec){
    std::set<int, std::greater <T> > gquiz1;
    for(int i{};i<vec.size();i++)
    {
        gquiz1.insert(vec[i]);
    }

    vec.erase(std::find_if(vec.begin(), vec.end(), [](const int &i) { return i > 3; }), vec.end());

    for(auto x:vec){
        std::cout << x << " ";
    }
    std::cout << std::endl;

}
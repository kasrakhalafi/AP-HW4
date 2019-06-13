#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include <cmath>

template <typename T>
void printContainer(const T &, std::string);

template <typename T>
void setbRand(std::vector<T>&);

template <typename T>
void disp(std::vector<T>&,std::string);

template <typename T>
void erasing(std::vector<T>&);

template <typename T>
void cfilling(std::vector<T>&);

template <typename T>
void deducingAandB(std::vector<T>& ,std::vector<T>&,std::vector<T>&);


int main()
{
  std::vector<int> a(50);
  std::vector<int> b(50);
  std::vector<int> c(50);
  setbRand(b);
  disp(a,"a");
  disp(b,"b");
  erasing(b);//erasing duplicated numbers
  cfilling(c);//filling c with numbers from 1 to 50
  b.resize(50);//for deducing we have to have a same size
  deducingAandB(a,b,c);
  //std::for_each(b.begin(), b.end(), [](int &i) { i = rand() % 50 + 1; });

}


template <typename T>
void setbRand(std::vector<T>& numbers){
    srand(time(NULL));
    std::for_each(numbers.begin(), numbers.end(), [](int &i) { i = rand() % 50 + 1; });
}

template <typename T>
void disp(std::vector<T>& vec,std::string a){
    std::cout << "The vector " + a << std::endl;
    std::for_each(vec.cbegin(), vec.cend(), [](const auto &i) { std::cout << i << " "; });
    std::cout << std::endl;
}

template <typename T>
void erasing(std::vector<T>& vec){
    std::sort(vec.begin(), vec.end(), std::less<>());
    disp(vec,"befor erasing duplicate Numbers but sorted !");
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    disp(vec,"after erasing duplicate Numbers");
}

template <typename T>
void cfilling(std::vector<T>& vec){//filling
    int num{1};
    std::for_each(vec.begin(), vec.end(), [&num](int &i) {i = num; num++; });
    disp(vec,"The C vector is");
}


template <typename T>
void deducingAandB(std::vector<T>& vec1 ,std::vector<T>& vec2 ,std::vector<T>& vec3){//deducing pow(2) of b and c and saving it in a
    std::vector<int>::iterator iterb{vec2.begin()};
    std::vector<int>::iterator iterc{vec3.begin()};
    std::for_each(vec1.begin(), vec1.end(), [&iterb, &iterc](int &i) { i = std::pow(*(iterc++), 2) - std::pow(*(iterb++), 2); });
    disp(vec1,"The a vector is");
}
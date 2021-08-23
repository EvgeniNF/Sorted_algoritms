#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <random>

std::unique_ptr<std::vector<int>> set_rand(std::unique_ptr<std::vector<int>> a){
    for(int & i : *a){
        i = (rand() % 100) + 1;
    }
    return std::move(a);
}
std::unique_ptr<std::vector<int>> show(std::unique_ptr<std::vector<int>> a){
    for(int &i : *a){
        std::cout << i << " | ";
    }
    std::cout << std::endl;
    return std::move(a);
}
std::unique_ptr<std::vector<int>> gnom_sort(std::unique_ptr<std::vector<int>> a){
    int size = static_cast<int>(a->size());
    int n = 0;
    while (n < size - 1){
        if (a->at(n) > a->at(n+1)){
            std::swap(a->at(n), a->at(n+1));
            if (n != 0){
                n--;
            }
            else {
                n++;
            }
        }
        else {
            n++;
        }
    }
    return std::move(a);
}
std::unique_ptr<std::vector<int>> ripple_sort(std::unique_ptr<std::vector<int>> a){
    int size = a->size();
    int left = 1;
    int right = size - 1;
    while (left <= right){
        for (int i = right; i >= left; i--)
            if (a->at(i - 1) > a->at(i))
                std::swap(a->at(i), a->at(i - 1));
        left++;
        for (int i = left; i <= right; i++)
            if(a->at(i - 1) > a->at(i))
                std::swap(a->at(i), a->at(i - 1));
        right--;
    }
    return std::move(a);
}
std::unique_ptr<std::vector<int>> fast_sort(std::unique_ptr<std::vector<int>> a){

    return std::move(a);
}

int main() {
    auto vec = std::make_unique<std::vector<int>>();
    vec->resize(10);

    std::cout << "Gnom sort: " << std::endl;
    vec = set_rand(std::move(vec));
    vec = show(std::move(vec));
    vec = gnom_sort(std::move(vec));
    vec = show(std::move(vec));
    std::cout << std::endl;

    std::cout << "Ripple sort: " << std::endl;
    vec = set_rand(std::move(vec));
    vec = show(std::move(vec));
    vec = ripple_sort(std::move(vec));
    vec = show(std::move(vec));
    std::cout << std::endl;

    std::cout << "Fast sort: " << std::endl;
    vec = set_rand(std::move(vec));
    vec = show(std::move(vec));
    vec = fast_sort(std::move(vec));
    vec = show(std::move(vec));
    std::cout << std::endl;


    return 0;
}

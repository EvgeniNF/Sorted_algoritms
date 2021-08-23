#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> gnom_sort(std::vector<int> a){
    int size = static_cast<int>(a.size());
    int n = 0;
    while (n < size - 1){
        if (a.at(n) > a.at(n+1)){
            std::swap(a.at(n), a.at(n+1));
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
    for (int i = 0; i < size; i++){
        std::cout << a.at(i) << " | ";
    }
    std::cout << std::endl;
    return a;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

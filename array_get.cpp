#include <array>
#include <iostream>





int main(void) {
    constexpr std::array<int, 5> arr{1, 2, 3, 4, 5};
    std::cout << std::get<0>(arr) << "\n";  
    std::cout << std::get<1>(arr) << "\n";  
    std::cout << std::get<2>(arr) << "\n";  
    std::cout << std::get<3>(arr) << "\n";  
    std::cout << std::get<4>(arr) << "\n";  

}



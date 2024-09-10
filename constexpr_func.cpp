#include <array>
#include <iostream>


template <int N>
constexpr int Positive(const std::array<std::array<int, N>, N>& matrix) {
    return matrix[0][0] * matrix[1][1] * matrix[2][2] +
	    matrix[0][1] * matrix[1][2] * matrix[2][0] + 
	    matrix[1][0] * matrix[2][1] * matrix[0][2];
}

template <int N>
constexpr int Negative(const std::array<std::array<int, N>, N>& matrix) {
    return matrix[0][2] * matrix[1][1] * matrix[2][0] +
            matrix[0][1] * matrix[1][0] * matrix[2][2] +
            matrix[0][0] * matrix[1][2] * matrix[2][1];
}

template <int N>
constexpr int Det(const std::array<std::array<int, N>, N>& matrix) {
    return Positive<N>(matrix) - Negative<N>(matrix);
}


int main() {
    constexpr std::array<std::array<int, 3>, 3> matrix = {{
        {0, 1, 2},
        {1, 2, 3},
        {2, 3, 7}
    }};
    constexpr int result = Det<3>(matrix);
    std::cout << result << std::endl;
    return 0;
}

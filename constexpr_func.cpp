#include <array>
#include <iostream>


template <int N>
constexpr std::array<std::array<int, N - 1>, N - 1> FillSubMatrix(const std::array<std::array<int, N>, N>& matrix, int column) {
    std::array<std::array<int, N - 1>, N - 1> subMatrix{};
    unsigned long a = 0, b = 0;
    for (unsigned long i = 1; i < N; ++i) {
        for (unsigned long j = 0; j < N; ++j) {
	    if (j != column) {
		    (&std::get<0>((&std::get<0>(subMatrix))[a]))[b] = (&std::get<0>((&std::get<0>(matrix))[i]))[j];
		b++;
	    }
	}
	a++;
	b = 0;
    }
    return subMatrix;
}


template <int N>
constexpr int Det(const std::array<std::array<int, N>, N>& matrix) {
    if constexpr (N == 1) {
        return std::get<0>(std::get<0>(matrix));
    } else {
        int determinant = 0;
	unsigned long i = 0;
       	while (i < N) {
	    std::array<std::array<int, N - 1>, N - 1> subMatrix = FillSubMatrix<N>(matrix, i); 
            determinant += (&std::get<0>(std::get<0>(matrix)))[i] * (i & 1 ? -1 : 1) * Det<N - 1>(subMatrix);
	    ++i;
    	}

    	return determinant;
    }
}


int main() {
    constexpr std::array<std::array<int, 3>, 3> matrix = {{
        {0, 1, 2},
        {1, 2, 3},
        {2, 3, 7}
    }};

    constexpr std::array<std::array<int, 2>, 2> matrix2 = {{
        {1, 2},
	{3, 4}
    }};

    constexpr std::array<std::array<int, 1>, 1> matrix1 = {{
        {1}
    }};



    constexpr int result = Det<3>(matrix);
    std::cout << result << std::endl;
    return 0;
}

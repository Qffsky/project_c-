#include <array>
#include <iostream>


//https://stackoverflow.com/questions/59909712/how-to-compute-the-determinant-of-a-matrix-in-c-using-recursive-functions
template <int N>
constexpr std::array<std::array<int, N - 1>, N - 1> FillSubMatrix(const std::array<std::array<int, N>, N>& matrix, int column) {
    std::array<std::array<int, N - 1>, N - 1> subMatrix{};
    int a = 0, b = 0;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
	    if (j != column) {
	        subMatrix[a][b] = matrix[i][j];
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
        return matrix[0][0];
    } else {
        int determinant = 0, i = 0;
       	while (i < N) {
	    std::array<std::array<int, N - 1>, N - 1> subMatrix = FillSubMatrix<N>(matrix, i); 
            determinant += matrix[0][i] * (i % 2 ? 1 : -1) * Det<N - 1>(subMatrix);
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

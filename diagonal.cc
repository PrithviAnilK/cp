#include <bits/stdc++.h>
#include <functional>

using namespace std;
using ll = long long;

class Diagonal
{
private:
    unordered_map<int, int> diagonal_1, diagonal_2;
    vector<vector<int>> matrix;

public:
    Diagonal(const vector<vector<int>> &matrix)
    {
        this->matrix = matrix;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                diagonal_1[i - j] += matrix[i][j];
                diagonal_2[i + j] += matrix[i][j];
            }
        }
    }

    int get_X(int i, int j)
    {
        return diagonal_1[i - j] + diagonal_2[i + j] - matrix[i][j];
    }
};

int main()
{
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Diagonal diagonal(v);
    cout << diagonal.get_X(1, 1) << '\n';
    return 0;
}
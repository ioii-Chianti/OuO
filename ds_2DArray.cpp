using namespace std;

int newArray(int row, int col) {
    int **ret = new int *[row];
    for (int i = 0; i < row; i++)
        ret[i] = new int[col];
}

int deleteArray(int **arr, int row) {
    for (int i = 0; i < row; i++)
        delete[] arr[i];
    delete[] arr;
}
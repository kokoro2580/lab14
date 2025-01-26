#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void showMatrix(const bool B[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}

// ฟังก์ชันสำหรับรับค่าของเมทริกซ์
void inputMatrix(double A[N][N]) {
    for (int i = 0; i < N; i++) { // วนลูปแต่ละแถว
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < N; j++) { // วนลูปแต่ละคอลัมน์ในแถว
            cin >> A[i][j]; // รับค่าจากผู้ใช้แล้วเก็บในเมทริกซ์
        }
    }
}

void findLocalMax(const double matrix[][N], bool result[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                result[i][j] = false;
            } else {
                if (matrix[i][j] >= matrix[i - 1][j] &&
                    matrix[i][j] >= matrix[i + 1][j] &&
                    matrix[i][j] >= matrix[i][j - 1] &&
                    matrix[i][j] >= matrix[i][j + 1]) {
                    result[i][j] = true;
                } else {
                    result[i][j] = false;
                }
            }
        }
    }
}
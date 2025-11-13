#include <iostream>
#include <cstdlib>
using namespace std;


int RandomNumber(int From, int To) {


    return rand() % (To - From + 1) + From;

}


void Fill2DArrayWithRandomNum(int arr[3][3], short Rows, short Col) {

    short counter = 0;
    for (int i = 0; i < Rows; i++) {


        for (int j = 0; j < Col; j++) {
            counter++;
            arr[i][j] = counter;
            

        }
    }

}

void PrintMatrix(int arr[3][3], short Rows, short Col) {

    for (int i = 0; i < Rows; i++) {

        for (int j = 0; j < Col; j++) {

            cout << arr[i][j] << "   ";


        }
        cout << "\n";
    }


}


int main() {

    int arr[3][3];


    Fill2DArrayWithRandomNum(arr, 3, 3);


    cout << "\nThe following is a 3x3 ordered matrix:\n";

    PrintMatrix(arr, 3, 3);

    system("pause>0");



}

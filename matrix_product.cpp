/*
This program computes product of two square matrices

LIMITATIONS:
- it only works with square matrices
- the size of the square matrix has to be predefined before run time

*/

#include <iostream>

using namespace std;

// specify matrix dimensions here
#define ROW_SIZE 3
#define COL_SIZE 3

class Matrix{
private:
    int arr[ROW_SIZE][COL_SIZE];
public:
    // default c-tor
    Matrix()
    {
        for(int i = 0; i < ROW_SIZE; i++)
            for(int j = 0; j < COL_SIZE; j++)
                arr[i][j] = 0;
    }

    // overlaoded c-tor takes a simple array as its parameter list
    Matrix(int *p)  // pointer to an integer
    {
        for(int i = 0; i < ROW_SIZE; i++)
            for(int j = 0; j < COL_SIZE; j++)
            {
                arr[i][j] = *p;     // dereference p so that it points to array value
                p = p + 1;          // move on to next array address
            }
    }

    // setter
    void setElement(int i, int j, int val)
    {
        arr[i][j] = val;
    }

    // getter
    int getElement(int i, int j)
    {
        return arr[i][j];
    }

    void display()
    {
        for(int i = 0; i < ROW_SIZE; i++)
        {
            cout << "|\t";
            for(int j = 0; j < COL_SIZE; j++)
                cout << arr[i][j] << "\t";
            cout << "|\n\n\n";
        }
        cout << endl << endl;
    }

    // currently tested with square matrices only
    Matrix operator * (Matrix A)
    {
        Matrix product;

        int sum(0);

        // iterate along rows
        for(int i = 0; i < ROW_SIZE; i++)
        {
            // iterate along columns
            for(int j = 0; j < COL_SIZE; j++)
            {
                // capturing rows top to bottom from left operand (for arr) and
                // capturing columns left to right from right operand (for A.arr)
                for(int q = 0; q < COL_SIZE; q++)
                {
                    // the row index i for arr should change only when we move along rows whilst
                    // the column index q changes while in the same row to cover all columns (or, in other words, the elements of the current row);
                    // the column index j is an invariant for A.arr until the product of row by column has been exhausted
                    sum += arr[i][q] * A.arr[q][j];
                }

                product.arr[i][j] = sum;

                sum = 0;    // reset sum for next element
            }
        }
        return product;
    }

};

int main(int arg, char*argv[])
{
    // checking constant values
    //cout << ROW_SIZE << endl << COL_SIZE << endl;

    // creating and initializing two matrices explicitly
    int val1[] = {1,2,1,3,2,0,1,0,3};
    Matrix A(val1);
    A.display();

    int val2[] = {1,2,3,1,1,1,0,0,1};
    Matrix B(val2);
    B.display();

    Matrix C = A * B;
    C.display();

    return 0;
}

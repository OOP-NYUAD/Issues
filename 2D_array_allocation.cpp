#include <iostream>
#include <cstdlib>

int main(){
    int rows = 5, cols = 3;

    int **arr2D = new int*[rows];
    for(int i = 0; i < rows; i++)
        arr2D[i] = new int[cols]; // arr2D[i] for each i will hold an array of integers to store our data

    
    // we can use arr2D as a regular 2D array

    for(int i = 0; i < rows; i++){
        for(int x = 0; x < cols; x++){
            arr2D[i][x] = rand() % 10;
        }
    }

    
    for(int i = 0; i < rows; i++)
        delete[] arr2D[i];
        
    delete[] arr2D;
    return 0;
}

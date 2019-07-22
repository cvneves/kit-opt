#include "readData.h"
#include <fstream>
#include <iostream>

using namespace std;

double ** matrizAdj; // matriz de adjacencia
int dimension; // quantidade total de vertices

void printData();

int main(int argc, char** argv) {

    readData(argc, argv, &dimension, &matrizAdj);
    printData();
    return 0;

    

}

void printData() {
  cout << "dimension: " << dimension << endl;
  for (size_t i = 1; i <= dimension; i++) {
    for (size_t j = 1; j <= dimension; j++) {
      cout << matrizAdj[i][j] << " ";
    }
    cout << endl;
  }
}

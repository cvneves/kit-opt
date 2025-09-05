#include <iostream>
using namespace std;

#include "Data.h"
#include "hungarian.h"

int main(int argc, char** argv) {

	Data data = Data(argc, argv[1]);
	data.read();

	size_t n = data.getDimension();

	double **cost = new double*[n];
	for (int i = 0; i < n; i++){
		cost[i] = new double[n];
		for (int j = 0; j < n; j++){
			if (i == j) { // Banindo arcos para o proprio nó
				cost[i][j] = 99999999;
				continue;
			}
			cost[i][j] = data.getDistance(i+1,j+1);
		}
	}

	hungarian_problem_t p;
	int mode = HUNGARIAN_MODE_MINIMIZE_COST;
	hungarian_init(&p, cost, n, n, mode); // Carregando o problema

	double obj_value = hungarian_solve(&p);
	cout << "Obj. value: " << obj_value << endl;

	cout << "Assignment" << endl;
	hungarian_print_assignment(&p);

	hungarian_free(&p);
	for (int i = 0; i < n; i++) delete [] cost[i];
	delete [] cost;

	return 0;
}

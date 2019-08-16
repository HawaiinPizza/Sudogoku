#include <iostream>
#include "Header.h"

int main(){
	ofstream File("WOW.txt");
	SudGrid a(File, 9, 5);
	a.printGrid();

	ifstream Dab("WOW.txt");
	a.printGrid(3);
	SolveGrid A(Dab);


	

}

#include <iostream>
#include "Header.h"

int main(){
	ofstream File("File.dat");

	SudGrid a(File, 9, 15);
	a.printGrid();

	ifstream Dab("File.dat");
	if(!Dab.is_open()){
		cout << "THIS FILE DOESNT EXIST!";
		return -5;
	}
	else if(Dab.peek() == ifstream::traits_type::eof()){
		cout << "This file doesn't have anything in it.";
		return -8;
	}
	a.printGrid(3);
	SolveGrid A(Dab);


	

}

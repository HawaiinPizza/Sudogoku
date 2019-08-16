#include <iostream>
#include "Header.h"

int main(){
	ofstream File("WOW.txt");
	SudGrid a(File, 9, 5);
	a.printGrid();


	

}

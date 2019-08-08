#include <iostream>
#include "Header.h"

int main(){
	ofstream File("WOW.txt");
	SudGrid a(File, 9);
	a.Fill();
	a.printGrid();
	cout<<"\n\n";
	cout << a.usedInRow(Pos (0,0), 3);
	cout << a.usedInColumn(Pos (0,0), 3);
	cout << a.usedInRow(Pos (3,3), 3);
	cout << a.usedInColumn(Pos (3,3), 3);

	

}

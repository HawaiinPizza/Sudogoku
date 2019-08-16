#include <iostream>
#include "Header.h"

int main(){
	ofstream File("WOW.txt");
	SudGrid a(File, 9);
	a.Fill();
	cout<<"\n\n";
	//cout << a.usedInRow(Pos (0,0), 3);
	//cout << a.usedInColumn(Pos (0,0), 3);
	//cout << a.usedInRow(Pos (3,3), 3);
	//cout << a.usedInColumn(Pos (3,3), 3);

	//a.usedInSubGrid(Pos(0,0), 0);
	//a.usedInSubGrid(Pos(1,0), 0);
	//a.usedInSubGrid(Pos(2,0), 0);
	//a.usedInSubGrid(Pos(3,0), 0);
	//a.usedInSubGrid(Pos(4,0), 0);
	//out << a.usedInSubGrid(Pos(0,0), 0);
	//out << a.usedInSubGrid(Pos(1,0), 0);
	//out << a.usedInSubGrid(Pos(2,0), 0);
	//out << a.usedInSubGrid(Pos(0,1), 0);
	//out << a.usedInSubGrid(Pos(1,1), 0);
	//out << a.usedInSubGrid(Pos(2,1), 0);
	//out << a.usedInSubGrid(Pos(0,2), 0);
	//out << a.usedInSubGrid(Pos(1,2), 0);
	//out << a.usedInSubGrid(Pos(2,2), 0);
	//out << '\n';
	//out << a.usedInSubGrid(Pos(3,0), 0);
	//out << a.usedInSubGrid(Pos(4,0), 0);
	//out << a.usedInSubGrid(Pos(5,0), 0);
	//out << a.usedInSubGrid(Pos(3,1), 0);
	//out << a.usedInSubGrid(Pos(4,1), 0);
	//out << a.usedInSubGrid(Pos(5,1), 0);
	//out << a.usedInSubGrid(Pos(3,2), 0);
	//out << a.usedInSubGrid(Pos(4,2), 0);
	//out << a.usedInSubGrid(Pos(5,2), 0);
	//out << '\n';
	//a.usedInSubGrid(Pos(6,0), 0);
	//a.usedInSubGrid(Pos(7,0), 0);
	//a.usedInSubGrid(Pos(8,0), 0);

	a.Test();


	

}

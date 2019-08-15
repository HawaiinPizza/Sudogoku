#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <random>
using namespace std;

struct Pos{
	int x;
	int y;
	Pos(int x=0, int y=0): x(x), y(y){}

	Pos& operator=(const Pos& Other){
		x=Other.x;
		y=Other.x;
		return *this;
	}

	Pos operator+(const Pos& a) const{
		return Pos(a.x+x, a.y+y);
	}

	bool operator==(const Pos& a) const {
		return (x == a.x && y == a.y);
	}

};


class SudGrid{
	public:
		//ObjSize is the size of the grid
		//ouptut is where the outptu will be written in
		//seed is used to generate random values
		SudGrid (ofstream &output, int seed) : File(output), Seed(seed) {
			Size=Pos(9,9);
			TotalSize=Size.x*Size.y;
			Length=sqrt(TotalSize);
			string wow=to_string(seed);
			seed_seq SampleSeed(wow.begin(), wow.end());
			Dice.seed(SampleSeed);
		}


		void Fill(){
			int Length=sqrt(TotalSize);
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					Grid[i][j]=0;
				}
			}


			for(int i=0; i<Length; i++){
				for(int j=0; j<Length; j++){
					//selectUnassignedLocation(i,j);
				}
			}

		}

		void selectUnassignedLocation(int i, int j){
			int Val[]={4, 5, 6, 7, 8, 9, 1, 2, 3};
			int Index=0;
			int Start=Dice()%9;
			while(Grid[i][j]==0 && Index<10){
				if (validToPlace(Pos(i,j), Val[(Index+Start)%9])){
					Grid[i][j]=Val[(Index+Start)%9];
					return;
				}
				else{
					Index++;
				}
			}
		}

		bool usedInRow(Pos Loc, int Check){
			//If Check used in the row return true
			for(int i=0; i<9; i++){
				if (Grid[Loc.x][(Loc.y+i)%9] == Check)
					return false;
			}
			//If Check not used in the row return true
			return true;
		}
		bool usedInColumn(Pos Loc, int Check){
			//If Check used in the column return true
			for(int i=0; i<9; i++){
				if (Grid[(Loc.x+i)%9][Loc.y] == Check)
					return false;
			}
			//If Check not used in the column return true
			return true;
		}
		bool usedInSubGrid(Pos Loc, int Check){
			int Gridx=Loc.x/3  ;
			int Gridy=Loc.y/3 ;
			for(int i=0; i<3; i++){
				for(int j=0; j<3; j++){
					if(Grid[i+3*Gridx][j+3*Gridy] == Check)
						return false;
				}
			}
			//If Check not used in the subgrid return true
			return true;
		}
		bool validToPlace (Pos Loc, int Check){
			if( usedInSubGrid(Loc,Check)){
				if(usedInRow(Loc,Check)){
					if (usedInColumn(Loc,Check)){
					return true;
					}
				}
			}
			return false;

		}
		void printGrid(){
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					string N= (j%3==2) ? "| " : " ";
					File << Grid[i][j] <<' ' << N;
				}
				if(i%3==2){
					File <<endl;
					for(int s=0; s<29; s++)
						File<<'-';
					File<<endl;
				}
				else{
					File << endl;
				}
			}
		}
	private:
		ofstream& File;
		int Grid[9][9];
		Pos Size;
		int TotalSize;
		int Seed;
		int Length;
		minstd_rand0 Dice;
		

	
};

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
		y=Other.y;
		return *this;
	}

	Pos operator+(const Pos& a) const{
		return Pos(a.x+x, a.y+y);
	}

	bool operator==(const Pos& a) const {
		return (x == a.x && y == a.y);
	}

};

class SolveGrid{
	public:
		//SudGrid (ofstream &output, int seed) : File(output), Seed(seed) {
		SolveGrid(ifstream &Read) : File(Read){
			GenGrid();
		}

		void GenGrid(){
			//Read through File.
			//Each line interpet as Line
			//Split up the line as an array

			string Line;
			int x=0;
			while(getline(File, Line)){
				
				int Arr[8];
				File >> 
					Arr[0] >> 
					Arr[1] >> 
					Arr[2] >> 
					Arr[3] >> 
					Arr[4] >> 
					Arr[5] >> 
					Arr[6] >> 
					Arr[7] >>
					Arr[8];
				for(int i=0; i<9; i++){
					cout << x << ':' << i <<'/'<< Arr[i] << '\t';
					Grid[x][i]=Arr[i];
				}
				cout << "\n\n";
				x++;
			}
			cout << "\n\n";
			Solve();
			printGrid();

		}

		bool Solve(){
			Pos Index;
			if(!selectUnassignedLocation(Index)){
				return true;
			}
			srand (time(NULL));
			int ran=rand()%10+1;
			for(int i=0; i<9; i++){
				int val=(i+ran)%9+1;	
				if (validToPlace(Index,val)){
					Grid[Index.x][Index.y]=val;
					if(Solve())
						return true;
					Grid[Index.x][Index.y]=0;
				}
					
			}
				return false;
		}
		  
		  
		//Find an unused location
		bool selectUnassignedLocation(Pos &Index){
			for (int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					if(Grid[i][j]==0){
						Index=Pos(i,j);
						return true;
					}
				}
			}
			return false;
		}
				
		//
		
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
			for(int s=0; s<29; s++)
				cout<<'-';
			cout << '\n';
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					string N= (j%3==2) ? "| " : " ";
					cout << Grid[i][j] <<' ' << N;
				}
				if(i%3==2){
					cout <<endl;
					for(int s=0; s<29; s++)
						cout<<'-';
					cout<<endl;
				}
				else{
					cout << endl;
				}
			}
		}
	private:
		int Grid[9][9];
		ifstream& File;

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
			Fill();
		}

		SudGrid (ofstream &output, int seed, int Hint) : File(output), Seed(seed) {
			Size=Pos(9,9);
			TotalSize=Size.x*Size.y;
			Length=sqrt(TotalSize);
			string wow=to_string(seed);
			seed_seq SampleSeed(wow.begin(), wow.end());
			Dice.seed(SampleSeed);
			Fill(Hint);
		}




		void Fill(int Hint){
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					Grid[i][j]=0;
				}
			}
			
			Solve();
			for(int Index=0; Index<Hint; Index++){
				Pos Rand(rand()%9,rand()%9);
				while(Grid[Rand.x][Rand.y]==0){
					 Rand=Pos(rand()%9,rand()%9);
				}
				Grid[Rand.x][Rand.y]=0;

			}

			int Index=0;
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					if(Grid[i][j]==0){
						Index++;
					}
				}
			}
		}

		void Fill(){
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					Grid[i][j]=0;
				}
			}
			
			Solve();
			for(int Index=0; Index<17; Index++){
				Pos Rand(rand()%9,rand()%9);
				while(Grid[Rand.x][Rand.y]==0){
					 Rand=Pos(rand()%9,rand()%9);
				}
				Grid[Rand.x][Rand.y]=0;

			}

			int Index=0;
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					if(Grid[i][j]==0){
						Index++;
					}
				}
			}
		}

		bool Solve(){
			Pos Index;
			if(!selectUnassignedLocation(Index)){
				return true;
			}
			srand (time(NULL));
			int ran=rand()%10+1;
			for(int i=0; i<9; i++){
				int val=(i+ran)%9+1;	
				if (validToPlace(Index,val)){
					Grid[Index.x][Index.y]=val;
					if(Solve())
						return true;
					Grid[Index.x][Index.y]=0;
				}
					
			}
				return false;
		}
		  
		  
		//Find an unused location
		bool selectUnassignedLocation(Pos &Index){
			for (int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					if(Grid[i][j]==0){
						Index=Pos(i,j);
						return true;
					}
				}
			}
			return false;
		}
				
		//
		
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
					File << Grid[i][j] <<' ' << ' ';
				}
					File << endl;
			}
		}

		void printGrid(int x){
			for(int s=0; s<29; s++)
				cout<<'-';
			cout << '\n';
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					string N= (j%3==2) ? "| " : " ";
					cout << Grid[i][j] <<' ' << N;
				}
				if(i%3==2){
					cout <<endl;
					for(int s=0; s<29; s++)
						cout<<'-';
					cout<<endl;
				}
				else{
					cout << endl;
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

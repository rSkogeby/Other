#include <iostream>
#include <string>
using namespace std;
int main(){
	string R = "AquaVitae";
	string C = "AruTaVae";
	
	int strl;
	int LCS[R.length()+1][C.length()+1];

	for( int i = 0; i < R.length()+1; i++){
		for( int j = 0; j < C.length()+1; j++){
			if ( i < 1 || j < 1 ){
				LCS[i][j] = 0;
			} else if ( R[i-1] == C[j-1]  ) {
				LCS[i][j] = LCS[i-1][j-1] + 1;
			} else if ( R[i-1] != C[j-1]  ) {
				LCS[i][j] = LCS[i][j-1]>LCS[i-1][j]?LCS[i][j-1]:LCS[i-1][j];
			}
		}
	}
	
	int RL = R.length();
	int CL = C.length();
	int i = RL;
	int j = CL;
	int index = LCS[RL][CL];
	char lcs[index];
	lcs[index] = '\0';
	while( i > 0 && j > 0) {
		// If same go diagonal
		if ( R[i-1] == C[j-1]){
			lcs[index-1] = R[i-1];
			i--; j--; index--;
		} else if ( LCS[i-1][j] > LCS[i][j-1] ) { // Else go up or left
			i--;
		} else {
			j--;
		}
	}


	cout << "\nLCS of " << R << " and " << C << " is " << lcs << "\n\n";



	cout << "L * ";	
	for( int j = 0; j < R.length(); j++){
		cout << C[j] << " ";
	}
	cout << "\n";
	for( int i = 0; i < R.length()+1; i++){
		if(i<1) cout << "* ";
		else cout << R[i-1] << " ";

		for( int j = 0; j < C.length()+1; j++){
			
			cout << LCS[i][j] << " ";
		}
		cout << "\n";
	}

}

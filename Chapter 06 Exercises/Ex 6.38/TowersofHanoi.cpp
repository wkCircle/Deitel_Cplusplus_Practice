#include "TowersofHanoi.hpp"


inline void Hanoi(const int n, int k, char local, char targetlocal, char peg_temp){
	if (k==1){
		cout << n << ": "<< local << " -> " << targetlocal << endl;
	}
	else {
		Hanoi(n, k-1 , local, peg_temp, targetlocal);
		cout << n-(k-1) <<": "<< local << " -> " << targetlocal << endl;
		Hanoi(n, k-1, peg_temp, targetlocal, local);
	}
}
void TowersofHanoi(){
	// pegs label: A,B,C
	// n: total disks.
	// local: these disks' position (in peg A, B or C).
	// targetlocal: these disks' new position.
	// peg_temp: used as a temporary holding area.
	int n=0, totalstep=0;

	while(true){
		char local = 'A', targetlocal = 'C', peg_temp = 'B';
		cout << "Inupt total number of disks(>=1), or -1 to quit.\n";
		cin >> n;

		while (n < 1){
			if (n == -1)
				return;
			else{
				cout << "Invalid input. Try again.\n";
				cin >> n;
			}
		}

		totalstep =0;
		for (int i=1; i<=n; i++){
			totalstep = totalstep*2 + 1;
		}

		Hanoi( n, n, local, targetlocal, peg_temp);
		cout << "Total steps = " << totalstep << endl;

	}
}

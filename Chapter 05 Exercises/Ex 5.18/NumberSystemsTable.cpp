#include "NumberSystemsTable.hpp"

int NumberSystemsTable(){

	for(int group=1; group <=256; group+=10 ){
		int Num = group;
		int i = 0; //for loop 專用
		int copyNum=0, count=0;

		//decimal
		cout << "decimal: \t";
		for ( i = 0; i <= 9; i++){
			if(Num>256)
				break;

			cout << Num << "\t";
			Num++;
		}
		cout << endl;


		//to octal
		cout << "octal: \t\t";
		Num=group;
		for ( i = 0; i <= 9; i++){
			int toOctal=0;
			copyNum=0, count=0;
			if (Num>256)
				break;

			copyNum = Num;
			while (copyNum != 0){
				toOctal += (copyNum % 8) * pow(10, count);
				copyNum /= 8;
				count++;
			}

			cout << toOctal << "\t";
			Num++;
		}
		cout << endl;


		//to Hexidecimal
		cout << "Hexideci\t";
		Num = group;
		const string alpha = "0123456789ABCDEF";

		for ( i = 0; i <= 9; i++){
			int rema = 0;
			string rema_Str = "";
			string toHexidecimal = "";

			copyNum = 0, count = 0;
			if (Num>256)
				break;

			copyNum = Num;
			while (copyNum != 0){
				rema = (copyNum % 16);

				switch (rema) {
					case 0:
						rema_Str = '0';
						break;
					case 1:
						rema_Str = '1';
						break;
					case 2:
						rema_Str = '2';
						break;
					case 3:
						rema_Str = '3';
						break;
					case 4:
						rema_Str = '4';
						break;
					case 5:
						rema_Str = '5';
						break;
					case 6:
						rema_Str = '6';
						break;
					case 7:
						rema_Str = '7';
						break;
					case 8:
						rema_Str = '8';
						break;
					case 9:
						rema_Str = '9';
						break;
					case 10:
						rema_Str = 'A';
						break;
					case 11:
						rema_Str = 'B';
						break;
					case 12:
						rema_Str = 'C';
						break;
					case 13:
						rema_Str = 'D';
						break;
					case 14:
						rema_Str = 'E';
						break;
					case 15:
						rema_Str = 'F';
						break;
				} //對照 rema_Str.


				toHexidecimal = rema_Str + toHexidecimal; //stacking.
				copyNum /= 16;
			}
			cout << toHexidecimal << "\t";
			Num++;
		}
		cout << endl << endl;


	}


	return 0;
}

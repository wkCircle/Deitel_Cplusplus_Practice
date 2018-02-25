//
//  Chapter6_Exercises.cpp
//  20170510 Chapter 6 Exercises
//
//  Created by ntueconRA on 2017/5/9.
//  Copyright © 2017年 Kai. All rights reserved.
//


#include "Chapter6_Exercises.hpp"
using namespace std;

inline double calculateCharges6_12(double m){
	double chargem = 0.0;
	
	if (m <= 3)
		chargem = 2.00;
	else
		chargem = min(  2.00 + (m-3)*0.50 , 10.00);
	return chargem;
}
void ExerCh6::ParkingCharges6_12(){
	double x, y, z;
	
	cout << "Enter the hours parked yesterday in the park for these 3 customer.\n";
	cin >> x >> y >> z;
	
	cout << setw(5) << left << "Car" << right << setw(8) << "Hours" << setw(10) << "Charge" << endl;
	cout << setw(5) << left << "1"   << right << fixed << setw(8) << setprecision(1) << x << setw(10) << setprecision(2) << calculateCharges6_12(x) << endl;
	cout << setw(5) << left << "2"   << right << fixed << setw(8) << setprecision(1) << y << setw(10) << setprecision(2) << calculateCharges6_12(y) << endl;
	cout << setw(5) << left << "3"   << right << fixed << setw(8) << setprecision(1) << z << setw(10) << setprecision(2) << calculateCharges6_12(z) << endl;
	cout << setw(5) << left << "Total"<< right << fixed<< setw(8) << x+y+z << setw(10) << calculateCharges6_12(x)+calculateCharges6_12(y)+calculateCharges6_12(z) << endl;

}

void ExerCh6::RoundingNumbers6_13(){
	double x = 0.0, y= 0.0;
	while (true) {
		cout << "Input a real number or -1 to quit.\n";
		cin >> x;
		
		if (x==-1)
			break;
		
		y = floor( x + .5 );
		cout << "The nearest intteger of "<< x << " is: " << y << endl;
	}
}
void ExerCh6::noTitle6_17(){
	unsigned int x=0;
	srand( static_cast<int>(time(0)) );
	x = (rand()%5 + 1)*2;
	cout << "a) " << x << endl;
	
	x = (rand()%5 +1)*2 +1 ;
	cout << "b) " << x << endl;
	
	x = (rand()%5 +1 ) * 4 +2;
	cout << "c) " << x << endl;

}

inline long long int integerPower6_18(long long int base, long long unsigned int power){
	if(power == 0)
		return 0;
	else if (power == 1)
		return base;
	else if (power%2 ==0) //even
		return integerPower6_18(base*base, power/2);
	else
		return integerPower6_18(base*base, (power-1)/2 )*base ;
}
void ExerCh6::Exponentiation6_18(){
	int base=0;
	unsigned int power=0;
	while (true){
		cout << "Input two ordered pair of integers as base and power, respectively.)\nOr -1 to quit\n";
		cin >> base >> power;
		if ( base == -1 )
			break;
		
		cout << "The resule of base^power is: " << integerPower6_18(base, power) << endl;
		
	}
}

void ExerCh6::Multiples6_20(){
	int num1=1, num2=2;
	while (true){
		cout << "Input a pair of integers to determine if the second is a mutilple of the first.\n";
		cout << "or put 0 on the second to quit.\n";
		cin >> num1 >> num2;
		if ( num2 ==0 ){
			cout << "End of execution\n";
			break;
		}
		
		cout << "A: " << boolalpha << (num2 % num1 == 0) << endl;
	}
}
void ExerCh6::SquareofAnyCharacter6_23(){
	unsigned int side=1;
	string fillcharacter;
	string temp="";
	
	while (true){
		cout << "Input a natural number.\nOr 0 to quit.\n";
		cin >> side;
		if (side==0)
			break;
		cout << "Input a tmeplate of a character.\n";
		cin >> temp;
		fillcharacter = ( temp.substr(0, 1) );
		
		for (int i=1; i<=side ; i++){
			for (int j=1; j <= side; j++){
				cout << fillcharacter;
			}
			cout << endl;
		}
	}

}

inline char isPerfect6_28(const int n){
	int total = 0;
	int counter=1;
	string factors;
	char result;
	
	while(total < n && counter < n){
		if (n % counter == 0){
			total += counter;
			factors = factors + to_string(counter) + ' ' ; ///<string>
		}
		counter++;
	}
	if (total == n){
		result = 'T';
		cout << setw(4) << left << n << " is perfect.\n";
		cout << "The factors of " << fixed << setw(4) << left << n << " are: " << setw(30) <<factors << endl << endl;
	}
	else{
		result = 'F';
		cout << setw(2) << left << n << " is not perfect.\n";
		cout << "The factors of " << fixed << setw(4) << left << n << " are: " << setw(30) <<factors << endl << endl;
	}
	
	return result;
}
void ExerCh6::PerfectNumbers6_28(){
	//test
	int n=1;
	while( n != -1){
		cout << "Input an integer.\n";
		cin >> n;
		if (n== -1)
			break;
		isPerfect6_28(n);
	}
	//end test
	
//	for (int i=1 ; i <= 1000; i++){
//	isPerfect6_28(i);
//	}

}

void ExerCh6::ReverseDigits6_30(){
	int n=0, rev_n=0; //This even works for negative integer.
	int temp=0, digits=0;
	
	while ( n!=-1){
		cout << "Input an integer to be reversed.(or -1 to quit.)\n";
		cin >> n;
		if (n== -1)
			break;
		
		//calculate total digits.
		temp = n;
		while(temp != 0){
			temp/=10;
			digits++;
		}
		
		temp=0, rev_n=0;
		while(n != 0){
			temp = n%10 ;
			rev_n += temp * pow(10, (digits-1));
			digits--;
			n/=10;
		}
		cout << "Its reverse is: " << rev_n << endl;
	}

}
void ExerCh6::GreatestCommonDivisor6_31(){
	int x=1, y=1;
	while(true){
		int temp=0, quotient=0;
		
		cout << "Input two integers to find their GCD.(or 0 to quit) \n";
		cin >> x >> y;
		x = abs(x); ///<stdlib>
		y = abs(y);
		if (x==0 || y==0)
			break;
		
		temp =0;
		do{
			temp = y; //Initialize temp = min-value.
			// x is always largest and reinitialize temp = min-value.
			if (x<y){
				temp = x;
				x = y;
				y = temp;
			}
			quotient = x/y; //automatically truncated for int types.
			if( x - quotient*y == 0)
				break;
			else
				x -= (quotient*y) ;
			
		}while( x - quotient*y != 0);
		cout << temp << endl;
		
		
	}

}

inline int flips6_33(){
	return rand()%2 ;
}
void ExerCh6::CoinTossing6_33(){
	int s=0, Head=0, Tail=0;
	srand(static_cast<int>(time(0))); ///<ctime>
	for (int i=1; i <= 100 ; i++){
		
		s = flips6_33();
		if (s==1)
			Head++;
		else
			Tail++;
	}
	cout << "Head: " << Head << "\t" << "Tail: " << Tail << endl;
}

void ExerCh6::GuesstheNumberGame6_34(){
	char willing='y';
	
	while (willing=='y'){
		
		int s=0, guess=0;;
		
		srand( static_cast<int>( time(0) ) );
		s = rand()%1000 +1;
		
		cout << "I have number btw 1 and 1000. \nCan you guess my number?\nPlease type your first guess.\n";
		
		do {
			
			cin >> guess;
			if (guess==s){
				cout << "Excellent! You guess the number.\n";
				break;
			}
			else if (guess > s)
				cout << "Too high. Try again.\n";
			else
				cout << "Too low. Try again.\n";
			
		} while( guess != s);
		
		cout << "Would you like to play again?[y;n]\n";
		cin >> willing;
		
		while (willing != 'y' && willing != 'n'){
			cout << "Invalid input. Try again.[y;n]\n";
			cin >> willing;
		}
		
		
	}
	
}

inline double power3_36(double base, unsigned int exponent){
	if (exponent ==1)
		return base;
	else if (exponent % 2 == 0)
		return power3_36(base * base, exponent/2);
	else
		return base * power3_36(base * base, (exponent-1) /2 );

}
void ExerCh6::RecursiveExponentiation6_36(){
	unsigned int exponent=1;
	double base=1;
	
	cout << "Input base(double) and exponent(int>=1) values, or enter 0 in any value to quit.\n";
	cin >> base >> exponent;
	while(base !=0 && exponent != 0){
		cout << "The result is: " << power3_36(base, exponent) << endl;
		
		cout << "Input base(double) and exponent(int>=1) values, or enter 0 in any value to quit.\n";
		cin >> base >> exponent;
	}
	

}

template <class T6_37>
inline T6_37 fibonacci6_37(T6_37 n){
	// The (int ) max n = 48 so that val_n = 2971215073
	// The (double) max n = 1477 so that val_n = 1.30699e+308
	if (n==1)
		return 0;
	else if (n==2)
		return 1;
	
	T6_37 val_n=1, pre_val=0, helprmb=0;
	
	for(int i = 3; i <= n; i++){
		helprmb = val_n;
		val_n += pre_val;
		pre_val = helprmb;
	}
	return val_n;
}
void ExerCh6::FibonacciSeries6_37(){
	unsigned int n=1;
	
	while (true) {
		cout << "Input an integer representing th nth term of fibanacci series.(or 0 to quit.)\n";
		cin >> n;
		if (n==0)
			break;
		else {
			cout << "The value is:" << fibonacci6_37(n) << endl;
			cout << "The value under double is: " << fibonacci6_37(static_cast<double>(n)) << endl;
		}
	}
}

inline void Hanoi6_38(const int n, int k, char local, char targetlocal, char peg_temp){
	if (k==1){
		cout << n << ": "<< local << " -> " << targetlocal << endl;
	}
	else {
		Hanoi6_38(n, k-1 , local, peg_temp, targetlocal);
		cout << n-(k-1) <<": "<< local << " -> " << targetlocal << endl;
		Hanoi6_38(n, k-1, peg_temp, targetlocal, local);
	}
}
void ExerCh6::TowersofHanoi6_38(){
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
		
		cout << "Total steps = " << totalstep << endl;
		Hanoi6_38( n, n, local, targetlocal, peg_temp);
		
	}
}

inline int GCD6_41(int x, int y){
	if (y==0)
		return x;
	else
		return GCD6_41(y, x % y);
}
void ExerCh6::RecursiveGCD6_41(){
	int x, y, temp;
	while (true){
		cout << "Input two integers to calculate their GCD.(or 0 on any value to quit.)\n";
		cin >> x >> y;
		x = fabs(x);
		y = fabs(y);
		if (x==0 || y==0){
			cout << " GCD = 0 end system ended.\n";
			return;
		}
		
		// x is always largest and reinitialize temp = min-value.
		if (x<y){
			temp = x;
			x = y;
			y = temp;
		}
		
		
		cout << GCD6_41(x, y) << endl;
	}
}

//void ExerCh6::RecursiveMain6_42(){
//	//Copy and paste following codes into main.cpp
//	int main(void){
//		static int count=1;
//		++ count;
//		cout << count << endl;
//		main();
//	
//		return 0;
//	}
int tripleByValue6_51(int x){
	x *= 3;
	return x;
}
int tripleByReference6_51( int &x){
	x *= 3;
	return x;
}
void ExerCh6::PassbyValuevsPassbyReference6_51(){
	int count = 1;
	
	count =1;
	cout << "Original is: " << count << " tripleByValue6_51(count): " << tripleByValue6_51(count) << " Final: " << count  << endl;
	
	count =1;
	cout << "Original is: " << count << " tripleByReference6_51(count): " << tripleByReference6_51(count) << " Fianl: " << count << endl;
}

template <typename T6_53>
inline T6_53 minimum6_53(T6_53 x, T6_53 y){
	if (x>=y)
		return y;
	else
		return x;
}
void ExerCh6::FuncTemplateminimum6_53(){
	int x=5, y=4;
	string xs="5.43", ys="-5.42";
	float xf = 5.43, yf = 5.42;
	
	cout << minimum6_53(x, y) << endl;
	cout << minimum6_53(xs, ys) << endl;
	cout << minimum6_53(xf, yf) << endl;

}






















#include "Invoice.hpp"

Invoice::Invoice(int Num, string Dsp, int q, int p){
	setpartNumber(Num);
	setpartDsp(Dsp);
	setpartQuant(q);
	setpartSinglePrice(p);
}

void Invoice::setpartNumber(int num){
	partNumber = num;
}
void Invoice::setpartDsp(string dsp){
	partDsp = dsp;
}
void Invoice::setpartQuant(int q){
	if (q <0){
		q=0;
		cout << "Invalid value. Please set a nonnegative quantity.\n";
	}
	else
		partQuant = q;
}
void Invoice::setpartSinglePrice(int p){
	if (p <0){
		p=0;
		cout << "Invalid value. Please set a nonnegative quantity.\n";
	}
	else
		partSinglePrice = p;
}
int Invoice::getpartNumber(){
	return partNumber;
}
string Invoice::getpartDsp(){
	return partDsp;
}
int Invoice::getpartQuant(){
	return partQuant;
}
int Invoice::getpartSinglePrice(){
	return partSinglePrice;
}
int Invoice::getInvoiceAmount(){
	int totalPrice=0;
	totalPrice = partQuant * partSinglePrice;
	return totalPrice;
}






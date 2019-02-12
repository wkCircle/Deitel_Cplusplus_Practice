#include "Invoice.hpp"

int main(){
	Invoice invoiceEX(03734301, "Hard Drive- Synology", 2, 8888);
	Invoice invoiceDF(03732265, "Airplane ticket for busniess class including fwd and bwd trip", 1, 150000);

	//	Test only
	cout << "Your input for invoiceEX is: \n"
	<< "Invoice Number: "	<< invoiceEX.getpartNumber() << endl
	<< "Item Description: "	<< invoiceEX.getpartDsp()	 << endl
	<< "Item Quantity: "	<< invoiceEX.getpartQuant()	 << endl
	<< "Price per Item: "	<< invoiceEX.getpartSinglePrice() << endl;
	cout << "The total amount on the invoiceEX is: " << invoiceEX.getInvoiceAmount() << endl << endl;

	cout << "Your input for invoiceDF is: \n"
	<< "Invoice Number: "	<< invoiceDF.getpartNumber() << endl
	<< "Item Description: "	<< invoiceDF.getpartDsp()	 << endl
	<< "Item Quantity: "	<< invoiceDF.getpartQuant()	 << endl
	<< "Price per Item: "	<< invoiceDF.getpartSinglePrice() << endl;
	cout << "The total amount on the invoiceDF is: " << invoiceDF.getInvoiceAmount() << endl << endl;

}

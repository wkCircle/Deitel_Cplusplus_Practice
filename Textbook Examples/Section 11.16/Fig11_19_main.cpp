#include "Fig11_17_Interface.hpp"

int main(){
	Interface i( 5 ); // create Interface object
	cout << "Interface contains: " << i.getValue() << " before setValue" << endl;
	i.setValue( 10 );
	cout << "Interface contains: " << i.getValue() << " after setValue" << endl;
}


/**<�p��: 1. proxy class �n�B�O�i�H��user���ïu����class Implementation�������F��
 	2. ����#include"TextbookExamples.hpp"(class Implementation�Q�ŧi���a��)�A�]��class Interface �O�Q��pointer���V��l����A
 	   �ҥHcompiler���ݧ�Ŷ����O�d�A�u�n�b�e���[�Wclass Implementation;�Y�i(Line 16)
 	3. User �u�|#include"Proxy.hpp"�ӯu����class���b�t�~�@��.hpp���Y���|�Quser�ݨ��A�ҥH�z�Q�Wuser�ä����Dclass Implementation���s�b >**/

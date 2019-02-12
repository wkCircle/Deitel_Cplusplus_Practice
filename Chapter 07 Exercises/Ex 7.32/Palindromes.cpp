#include "Palindromes.hpp"

// prototype
bool testPalindrome( char [], size_t, int );
inline int getSize( string str){
	return static_cast<int>( str.length() );
	//or strlen(str);
	//or str.size();
}
inline void putStrIntoArr( char arr[], size_t arrSize, string str){
	for (int temp = 0; temp < arrSize; temp++){
		arr[temp] =  str.at(temp);
	}
//	or strcpy(arr, str.c_str() );
}


void Palindromes(){
	string text = "     Hello H  olleH ";
	string Msg = "I have no idea";

	const int len_text = getSize(text);
	const int len_Msg = getSize(Msg);
	char textArr[ len_text ];
	char MsgArr[ len_Msg ];
	putStrIntoArr(textArr, len_text, text );
	putStrIntoArr(MsgArr, len_Msg, Msg);

	cout << "text string: \""<< text <<"\" is a palindrome?\t" << boolalpha << testPalindrome( textArr, 0, len_text-1 ) << endl;
	cout << "Msg string: \""<< Msg << "\" is a palindrome?\t " << testPalindrome( MsgArr, 0, len_Msg-1 ) << endl;
}

bool testPalindrome( char arr[], size_t startIndex, int endIndex){
	if ( endIndex+1 == 0)
		return true;
	else if (endIndex- startIndex == 0 )
		return true;

	//start checking palindrome
	//neglect null character
	while ( arr[startIndex] == ' ' && startIndex < endIndex )
		startIndex++;
	while ( arr[endIndex] == ' ' && startIndex < endIndex )
		endIndex--;
	//case1 nothing can be compared.
	if (endIndex == startIndex )
		return true;
	//case2 compare
	else if (arr[startIndex] == arr[endIndex]){
		return testPalindrome(arr, startIndex+1, endIndex-1 );
	}
	//if incorrect otherwise, return false
	else
		return false;
}

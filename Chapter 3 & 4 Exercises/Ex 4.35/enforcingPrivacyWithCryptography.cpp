#include "enforcingPrivacyWithCryptography.hpp"


inline int enCrypt(int object){
	double enc_object = 0;
	int temp = 0, count = 0;
	//the easiest way:  additional var enc_object as a container. Meanwhile, execute (m+7) mod 10 & swap().
	while (count<=3){
		temp = (object + 7) % 10;
		enc_object += (  temp * ( pow( 10, (count+2) % 4 ) )  );
		object /= 10;
		count++;
	}
	return static_cast<int>(enc_object);
}
inline int deCrypt( int object){
	double dec_object = 0;
	int temp = 0, count = 0;

	while (count<=3) {
		temp = (object - 7) % 10;
		if (temp<0)
			temp += 10;

		dec_object += (  temp * ( pow( 10, (count+2) % 4 ) )  );
		object /= 10;
		count++;
	}

	return static_cast<int>(dec_object);
}
void enforcingPrivacyWithCryptography(){
	//int enCrypt(int);
	//int deCrypt(int);
    int obJect = 1111;

    while (obJect>=0){
        cout << "Input a four-digit integer to encrypt.\n";
        cin >> obJect;
        if (obJect<0)
            return;
        cout << "The integer after encrypting is: " << enCrypt(obJect) << endl;


        obJect = 1111;
        cout << "Input a four-digit integer to decrypt.\n";
        cin >> obJect;
        if (obJect<0)
            return;
        cout << "The integer after decrypting is: " << deCrypt(obJect) << endl;
    }
}




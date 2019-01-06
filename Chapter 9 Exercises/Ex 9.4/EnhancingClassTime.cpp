#include "EnhancingClassTime.hpp"

Time9_4::Time9_4(){ //initialize private data to current time
	time_t t = 0;
	time(&t); //same as t = time(0); OR, t = time(NULL);

	struct tm tinfo = *localtime(&t);
	year = tinfo.tm_year +1990 ; //tm_year returns years since 1990
	month = tinfo.tm_mon + 1; //tm_mon returns months since January(0~11)
	mday =tinfo.tm_mday;
	hour = tinfo.tm_hour;
	minute = tinfo.tm_min;
	second = tinfo.tm_sec;
}

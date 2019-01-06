#include "TimeClassModification.hpp"

Time::Time( int hr, int min, int sec){
    this -> second = 0;
    setTime(hr, min, sec);
}
Time & Time::setTime(int h , int m , int s ){
    setHour(h);
    setMinute(m);
    setSecond(s);
    return *this; /**<enables cascading>**/
};
Time & Time::setHour(int h ){
    second %= 3600; //remove hours and preserve minutes and seconds.
    second += (h >= 0 && h < 24)? h*3600 : 0 ; //reset/add on hours
    return *this; /**<enables cascading>**/
}
Time & Time::setMinute(int m ){
    second = (second %60) + (second/3600)*3600;
    second += ( m >= 0 && m < 60)? m*60 : 0;
    return *this; /**<enables cascading>**/
}
Time & Time::setSecond(int s){
    second -= (second%60); //preserve hours and minute
    second += ( s >= 0 && s < 60)? s: 0;
    return *this; /**<enables cascading>**/
}
int Time::getHour() const{
    return (second/3600);
}
int Time::getMinute() const{
    return (second%3600)/60;
}
int Time::getSecond() const{
    return (second%60);
}
void Time::printUniversal() const{
    cout << setfill('0') << setw(2) << second/3600 << ":" <<setw(2) << (second%3600)/60 << ":" <<setw(2) << (second%60);
}
void Time::printStandard() const{
    cout << (( second/3600 == 0 || second/3600 == 12 )? 12 :  (second/3600)%12  )
        << ":" << setfill('0') << setw(2) << ( second%3600 )/60
        << ":" << setw(2) << second%60 << ( second/3600 < 12 ? " AM" : " PM" );
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>  
using namespace std;

int main(){
    string time;
    cin >> time;
    
    int afternoon = 0;
    // read the last two chars
    if( (time.find("PM") != string::npos) || (time.find("pm") != string::npos)) {
        afternoon = 1;
    }
    
    int hours, mins, seconds;
    
    // extract hours
    string hours_str = time.substr(0, 2);
    string mins_str = time.substr(3, 2);
    string seconds_str = time.substr(6, 2);
    
    hours = atoi(hours_str.c_str());
    mins = atoi(mins_str.c_str());
    seconds = atoi(seconds_str.c_str());

	cout << setfill('0') << setw(2) ;
    if(afternoon){
        // pm
        hours += 12;
        if(hours >=24) hours -= 12;
        
    }else {
        // am
        hours = (hours >= 12) ? hours - 12 : hours;
    }

        cout << setfill('0') << setw(2)<< hours << ":" 
		  <<  setfill('0') << setw(2) << mins << ":" 
		  << setfill('0') << setw(2) << seconds<< endl;
    
    return 0;
}
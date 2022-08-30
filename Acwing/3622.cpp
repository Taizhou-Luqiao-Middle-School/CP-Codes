// Date: 2022-07-18 22:32:21
// Problem: 日期
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3622/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
const string week[] = {
			"Sunday",
			"Monday",
			"Tuesday",
			"Wednesday",
			"Thursday",
			"Friday",
			"Saturday"
};

const int months[] = {
	    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int month, date;
	cin>> month >> date;
	
	int m = 4, d = 12, day = 4;
	while(m < month || d < date){
		d ++;
		if(d > months[m]){
			d = 1;
			m ++;
		}
		day = (day + 1) % 7;
	}
	
	cout<< week[day] <<endl;
	return 0;
}

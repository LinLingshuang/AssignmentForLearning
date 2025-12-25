#include "Joseph.h"
#include<iostream>
#include<vector>
using namespace std;


void Joseph::simulate(int startnum) {
	vector<int>id(peoplenum);
	vector<bool>eluminate(peoplenum);
	for (int i = 0; i < peoplenum; i++) {
		id[i] = i + 1;
		eluminate[i] = false;
	}
	int eluminatenum = 0;
	int eluminateid = (startnum-1 + leapnum - 1) % (peoplenum);
	
	while (eluminatenum != peoplenum) {
		int hadleap = 0;
		if (!eluminate[eluminateid]) {
			cout << id[eluminateid] << " ";
			eluminate[eluminateid] = true;
			eluminatenum += 1;

			while (hadleap != leapnum) {
				eluminateid += 1;
				if (eluminateid == peoplenum)eluminateid = 0;
				if (eluminate[eluminateid] == false) {
					hadleap += 1;
				}
				if (eluminatenum == peoplenum)break;
			}
		}
	}



}
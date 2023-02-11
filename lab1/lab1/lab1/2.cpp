#include <iostream> 
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define PI 3.1415926535 
using namespace std;

double tan(double input) {
	try {
		if (cos(input) < 0.000000001) throw input;
		cout << "tan value: " << sin(input) / cos(input) << endl;
	}
	catch(double err){
		cerr << "Input error: division by 0" << endl;
	}
}

int main(int argc, char* argv[])
{
	tan(PI / 2);
	return 0;
}

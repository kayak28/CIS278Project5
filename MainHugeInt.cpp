#include<iostream>
#include "HugeInt.h"
#include "stdio.h"
using namespace std;

int main()
{
	HugeInt bigInt1();
	cout << bigInt1;
	
	HugeInt bigInt2();
	cout << bigInt2;
	
	printf("BigInt1 contains: %d digits\n", bigInt1.numDigits());
	printf("BigInt2 contains: %d digits\n", bigInt2.numDigits());

	if(bigInt1 == bigInt2) 
	{
		cout << "BigInt1 and BigInt2 have the same value\n";
	}	
	if(bigInt1 != bigInt2)
	{
		cout << "BigInt1 and BigInt2 are the different value\n";
	}
	
	HugeInt a("1345");
	HugeInt b("999");
	cout << "before pre-increment\n";
	cout << a << "\n"; 
	cout << b << "\n"; 
	
	a = ++b; 

	cout << "After pre-increment\n";	
	cout << a << "\n"; 
	cout << b << "\n"; 
	
	
	cout << "before post-increment\n";
	cout << a << "\n"; 
	cout << b << "\n"; 
	
	a = b++; 

	cout << "After post-increment\n";	
	cout << a << "\n"; 
	cout << b << "\n"; 
	
	cout << "a + b = " <<  a + b;
	
	int index = 0;
	cout << "which digits would you like to know?\n";	
	cin >> index;
	cout << "index : " << index << "\n";
	cout << "element: "  << BigInt1[index];
	BigInt1[index]* = 6;//insert 6 where user want to see


	return 0;
}//main

#include <iostream>
#include "math.h"
#include "HugeInt.h"

using namespace std; 

HugeInt::HugeInt()
{
	for(int i = digit.length(); i >= 0; i--)
	{
		if(i < 4)
		{
			digit[i] = 5;
		}
		else
		{
			digit[i] = 0;
		}

	}
}
HugeInt::HugeInt(string value)
{
	int scalar; 
	if(allDigit(value))
	{
		scalar = atoi(value);
		for(int i = value.length()-1; i >= 0; i--)
		{
			digit[i] =(int)( scalar/pow(10, i) )% 10;
			//insrat each digit into array with back word..
		}
	}

}
int HugeInt::numDigits() const
{//return the num of digits in this HugeInt array 


} 
int HugeInt::operator[] (int n)
{
	return digit[n];
}

HugeInt HugeInt::operator++()
{//operator overloading with pre-increment 
	

}
HugeInt HugeInt::operator++(int)
{//opeartor overloading with post-increment 


}
bool HugeInt::operator==(const HugeInt& operand)const
{ 
	for(int k = 0; k < SIZE; k++)
	{
		if(this.digit[k] != operand.digit[k])
		{
			return false;
		}
	}
	return true; 

}
bool HugeInt::operator!= (const HugeInt& operand)const
{
	for(int index = 0; index < SIZE; index++)
	{
		if(this.digit[index] == operand.digit[index])
		{
			return false;
		}
	}
	return true;
}
friend ostream& HugeInt::operator <<(ostream& out, const HugeInt& obj)
{
	int hugeInt = 0;//store actual value of integer. 
	for(int n = digit.length()-1; n >= 0; n--)
	{
		hugeInt += digit[n] * pow(10,n); 
	}
	out << "HugeInt: " << hugeInt; 
}
friend HugeInt operator+ (const HugeInt& operand1, const HugeInt& operand2)
{
	
}
static bool allDigits(string str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(!isDigit(str[i]))
		{
			return false;	
		}
	}
	return true; 
}

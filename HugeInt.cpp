#include <iostream>
#include "math.h"
#include "HugeInt.h"

using namespace std; 

HugeInt::HugeInt()
{
	length = 4;
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
	for(int n = 0; n < SIZE; n++)
	{//initialize array 
	 //in order to avoid to enter unknow value automatically 
		digit[n] = 0;
	}
	int scalar; 
	if(allDigit(value))
	{
		scalar = atoi(value);
		for(int i = value.length()-1; i >= 0; i--)
		{
			digit[i] =(int)(scalar/pow(10, i) )% 10;
			//insrat each digit into array with back word..
			length++; 
		}
	}

}
int HugeInt::numDigits() const
{//return the num of digits in this HugeInt array 
	
	return length; 

} 
int HugeInt::operator[] (int n)
{
	if(n >= 0 && n < length)
	{
		return digit[n];
	}
	else
	{
		return -1;
	}
}

HugeInt HugeInt::operator++()
{//operator overloading with pre-increment 
	HugeInt preIncrement;
	int index = 0;	
	
	preIncrement.digit[index] = this.digit[index] + 1;
	
	while(preIncrement.digit[index] == 10 && index < length)
	{
		preincrement.digit[index + i] = this.digit[i] + 1;
		index++;  
	}
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
	HugeInt sumInt;
	for(int i = 0; i < length ; i++)
	{
		sumInt.digit[i] = opeeand1.digit[i] + operand2.digit[i];
		if(sumInt.digit[i] >= 10)
		{
			sumInt.digit[i] = (int) (sumInt.digit[i] % 10);
			sumInt.digit[i+1] = (int)(sumInt.digit[i]/10);
		}
	}
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

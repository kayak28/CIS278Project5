#include <iostream>
#include "math.h"
#include "HugeInt.h"
#include "stdlib.h"//where atoi is tored 
using namespace std; 

HugeInt::HugeInt()
{
	length = 4;
	for(int i =0; i < SIZE; i++)
	{
		if(i < 4)
		{
			digits[i] = 5;
		}
		else
		{
			digits[i] = 0;
		}

	}
}

HugeInt::HugeInt(string value)
{
	cout << "1st";
	for(int n = 0; n < SIZE; n++)
	{//initialize array 
	 //in order to avoid to enter unknow value automatically 
		digits[n] = 0;
		//cout << digits[n] << "\n";
	}
	cout << "2nd";
	int scalar; 
	if(allDigits(value))
	{
		cout << "3rd\n";
		for(int i = 0; i < value.length() + 1; i++)
		{
			
			digits[i] = atoi(&value[value.length() - i]);
			value[value.length() - i] = 0x00; 
			//digits[i] = atoi(value[value.length() - i].c_str());
			//digits[i] = atoi(value[i].c_str());
			//digits[i] = value[value.length() - i];
			//digits[i] = atoi(value.at(value.length() - i));
			//digits[i] = atoi(value[value.length() - i]);
			//scalar = atoi(value.c_str());
			cout << "i = " << i << "\n" ;
			cout << "digit = " << digits[i]<< "\n"; 
		}
		/*cout << "scalar = "  << scalar ;
		cout << "\n";
		for(int i = value.length()-1; i >= 0; i--)
		{
			digits[i] =(int)(scalar/pow(10, i) )% 10;
			//insrat each digit into array with back word..
			length++; 
		}
		for(int i = value.length )
		*/
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
		return digits[n];
	}
	else
	{
		return -1;
	}
}

HugeInt HugeInt::operator++()
{//operator overloading with pre-increment 
	int index = 0;	
	
	this->digits[index]++;
	
	while(index < length)
	{ 
		if(this->digits[index] == 10)
		{
			this->digits[index] = 0;
			this->digits[index + 1] += 1;
			if(index == length + 1)
			{
				this -> length += 1;
				
			}
			index++;
			 
		}
		else
		{
			return (*this);
		} 
	}
	return (*this);
}

HugeInt HugeInt::operator++(int)
{//opeartor overloading with post-increment 

	HugeInt postIncrement = *this;
	int index = 0;	
	
	postIncrement.digits[index] = digits[index] + 1;
	while(index < length)
	{
		if(postIncrement.digits[index] == 10)
		{
			postIncrement.digits[index] = 0;
			postIncrement.digits[index + 1] += 1;
			index++;
		}
		else
		{
			return (postIncrement);
		}
	
	}
	/*
	while(postIncrement.digits[index] == 10 && index < length)
	{
		postIncrement.digits[index] = 0;
		postIncrement.digits[index + 1] += 1;
		index++;  
	}
	return (postIncrement);
	*/
}

bool HugeInt::operator==(const HugeInt& operand)const
{ 
	for(int k = 0; k < SIZE; k++)
	{
		if(digits[k] != operand.digits[k])
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
		if(digits[index] == operand.digits[index])
		{
			return false;
		}
	}
	return true;
}
//should not define 'frind' here(only with .h file)
//do not need class name since it is not member function(?)
ostream& operator<<(ostream& out, const HugeInt& obj)
{
	char buffer[50];
	int hugeInt = 0;//store actual value of integer. 
	/*for(int n = obj.length; n >= 0; n--)
	{
		hugeInt +=obj.digits[n] * pow(10,n); 
	}
	//out << "HugeInt: " << hugeInt; 
	*/
	for(int i = obj.length; i > 0; i++ )
	{
		buffer[i] = itoa( obj.digits[i], buffer[i],10);
	}
}

HugeInt operator+ (const HugeInt& operand1, const HugeInt& operand2)
{	
	HugeInt sumInt;
	for(int i = 0; i < operand1.length && i < operand2.length ; i++)
	{
		sumInt.digits[i] = operand1.digits[i] + operand2.digits[i];
		if(sumInt.digits[i] >= 10)
		{
			sumInt.digits[i] = (int) (sumInt.digits[i] % 10);
			sumInt.digits[i+1] += 1;
		}
	}
	return sumInt;
}
bool HugeInt::allDigits(string str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(!isdigit(str[i]))
		{
			return false;	
		}
	}
	return true; 
}


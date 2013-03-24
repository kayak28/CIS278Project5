#include <iostream>
#include "math.h"
#include "HugeInt.h"

using namespace std; 

HugeInt::HugeInt()
{

}
HugeInt::HugeInt(string value)
{

}
int HugeInt::numDigits() const
{

} 
int HugeInt::operator[] (int n)
{
	return digit[n];
}

HugeInt HugeInt::operator++()
{//operator overloadinf with pre-increment 


}
HugeInt HugeInt::operator(int)
{//opeartor overloading with post-increment 


}
bool HugeInt::operator==(const HugeInt& operand)const
{

}
bool HugeInt::operator!= (const HugeInt& operand)const
{

}
friend ostream& HugeInt::operator <<(ostream& out, const HugeInt& obj)
{

}
friend HugeInt operator+ (const HugeInt& operand1, const HugeInt& operand2)
{

}
static bool allDigits(string str)
{
	if(isDigit())
}

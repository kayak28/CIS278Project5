#include <ostream>
using namespace std;
class HugeInt 
{
	public:
		HugeInt();
		HugeInt(string value);
		
		int numDigits() const;
		int operator[] (int n);
		HugeInt operator ++();
		HugeInt operator ++(int);
		bool operator ==(const HugeInt& operand) const;
		bool operator !=(const HugeInt& operand) const;
		friend ostream& operator <<(ostream& out, const HugeInt& obj);
		friend HugeInt operator+(const HugeInt& operend1, const HugeInt& obj);
		static bool allDigits(string str);

	private:
		int digits[];
		int length;
	

};

/* 

Author: Aditya Upadhye

A simple program to convert binary to equivalent decimal. It works for upto 32-bit binary number.

*/


#include <iostream>
#include <cmath>


unsigned int binary_to_decimal(const std::string& n, int ln)
{

	ln = ln - 1;
	unsigned int tc = ln;
	unsigned int ansd = 0;

	while (ln >= 0)
	{

		if (n[tc - ln] == '1')
			ansd = ansd + 1 * std::pow(2, ln);

		ln--;

	} 

	return ansd;
}



int main()
{
	std::string user_input;

	std::cout << "Enter the valid binary number: " << std::endl;
	std::cin >> user_input;

	int length = user_input.length();

	std::cout << "\nLength: " << length << std::endl;

	if (length <= 32)
		std::cout << "To Decimal: " << binary_to_decimal(user_input, length) << "\n\n";
	else
		std::cout << "Length exceeds the 32 bit allowed range." << std::endl;

	return 0;

}

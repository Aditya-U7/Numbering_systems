/* 

Author: Aditya Upadhye

A simple program to convert a valid decimal number to an equivalent hexadecimal number using a map. It works correctly for decimal values from 0 to 18446744073709551615.

*/


#include <iostream>
#include <cmath>
#include <map>


std::string decimal_to_hex(unsigned long dec_num)
{

	std::string hex = "";

	if (dec_num == 0)
		return "0";

        std::map<short, char> dec_to_hex {{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'},
                                          {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, 
                                          {8, '8'}, {9, '9'}, {10,'A'}, {11, 'B'},
                                          {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}};

	unsigned long tmp = 0;  

	while (dec_num)
	{

		tmp = (dec_num % 16);
		hex = dec_to_hex[tmp] + hex;  
		dec_num /= 16;

	} 

	return hex;
}


int main()
{
	unsigned long user_input;

	std::cout << "Enter a valid decimal number: " << std::endl;
	std::cin >> user_input;


	std::cout << "To Hexadecimal: " << decimal_to_hex(user_input) << "\n\n";

	return 0;

}

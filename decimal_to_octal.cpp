/* 

Author: Aditya Upadhye

A simple program to convert a valid decimal number to an equivalent octal number.

*/


#include <iostream>
#include <cmath>
#include <map>


unsigned long decimal_to_octal(unsigned long dec_num)
{

	unsigned long oct_num = 0;

	unsigned long octal_place = 1;

	unsigned long tmp = 0;  

	while (dec_num)
	{

		tmp = (dec_num % 8) * octal_place;

		oct_num = tmp + oct_num;
		dec_num /= 8;

		octal_place *= 10;
	} 

	return oct_num;
}


int main()
{
	unsigned long user_input;

	std::cout << "Enter a valid decimal number: " << std::endl;
	std::cin >> user_input;


	std::cout << "To Octal: " << decimal_to_octal(user_input) << "\n\n";

	return 0;

}

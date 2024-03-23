/* 

Author: Aditya Upadhye

A simple program to convert binary to equivalent decimal. It works for upto 32-bit binary number.

*/


#include <iostream>
#include <cmath>


unsigned int binary_to_decimal(std::string& bin_num, int length)
{

	length -= 1;
	int current_pos = length;
	unsigned int dec_num = 0;
      
	while (current_pos >= 0)
	{

		if (bin_num[length - current_pos] == '1')
			dec_num = dec_num + 1 * std::pow(2, current_pos);
                
                current_pos--;

	} 

	return dec_num;
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

/* 

Author: Aditya Upadhye

A simple program to convert decimal to equivalent binary. It works for upto six digit decimal number, i.e. from 0 to 999999.

*/


#include <iostream>
#include <cmath>


unsigned long decimal_to_binary(unsigned long dec_num)
{
         
	unsigned long bin_num = 0;
	
        unsigned long exponent = 0;
        
        unsigned long tmp = 0;  
	
	while (dec_num > 0)
	{
                
                tmp = ((dec_num % 2) * pow(10, exponent));
		
		bin_num = tmp + bin_num;
		dec_num = dec_num / 2;
		
                ++exponent;
	} 

	return bin_num;
}


int main()
{
	unsigned long user_input;

	std::cout << "Enter the valid decimal number: " << std::endl;
	std::cin >> user_input;

	
        std::cout << "To Binary: " << decimal_to_binary(user_input) << "\n\n";
	
	return 0;

}

/* 

Author: Aditya Upadhye

A simple program to convert decimal to equivalent binary. It correctly works for six digits from 0 to 999999.

*/


#include <iostream>
#include <cmath>


unsigned long decimal_to_binary(unsigned long oct_num)
{
         
	unsigned long dec_num = 0;
	
        unsigned long oct_place = 1;
        
        unsigned long tmp = 0;  
	
	while (oct_num)
	{
                
                tmp = (oct_num % 10) * oct_place;
		
		dec_num = tmp + dec_num;
		oct_num /= 10;
	        oct_place *= 8;
	} 

	return dec_num;
}


int main()
{
	unsigned long user_input;

	std::cout << "Enter a valid octal number: " << std::endl;
	std::cin >> user_input;

	
        std::cout << "To decimal: " << decimal_to_binary(user_input) << "\n\n";
	
	return 0;

}

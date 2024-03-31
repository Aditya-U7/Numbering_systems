/*

Author: Aditya Upadhye

A program to convert a valid hexadecimal number given as input to an equivalent binary number using a map.

*/


#include <iostream>
#include <map>


std::string hexadecimal_to_binary(const std::string& hex_num)
{

	std::map<std::string, std::string> hex_to_bin {{"0", "0000"}, {"1", "0001"}, {"2", "0010"}, {"3", "0011"}, 
	                                               {"4", "0100"}, {"5", "0101"}, {"6", "0110"}, {"7", "0111"},
		                                       {"8", "1000"}, {"9", "1001"}, {"A", "1010"}, {"B", "1011"},
		                                       {"C", "1100"}, {"D", "1101"}, {"E", "1110"}, {"F", "1111"}};
		                                       

	int length = hex_num.length();
	int cur_pos = 0;
	bool first_iteration = true;

	std::string bin_num = "";
	std::string str = "";

	while (length)
	{


		str = hex_num.substr(cur_pos, 1); 
		str = hex_to_bin[str];
		cur_pos++;

		if (first_iteration)
		{
			if (str == "0000")
			{
				if (length == 1)
					bin_num = "0";

			}
			else
			{
				first_iteration = false;

				if (str == "0001")
					bin_num = str.substr(3, 1);
				else if (str == "0010" || str == "0011") 
					bin_num = str.substr(2, 2);
				else if (str == "0100" || str == "0101" || str == "0110" || str == "0111")
					bin_num = str.substr(1,3); 
				else
					bin_num = str;	
			}


		}
		else
		{

			bin_num += str;
		}

		--length;

	}

	return bin_num; 
}


int main()
{


	std::cout << "Enter the  hexadecimal number: " << std::endl;
	std::string user_input;
	std::cin >> user_input;

	std::cout << "\nTo Binary:  " << hexadecimal_to_binary(user_input) << "\n\n";

	return 0;
}

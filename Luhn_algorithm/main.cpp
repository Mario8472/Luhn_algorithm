#include <iostream>

unsigned long long card_num = 0;
unsigned long long divider = 1000000000000000;
unsigned long long digits[15] = { 0 };
unsigned int first_num = 0;
unsigned int second_num = 0;
unsigned int sum = 0;
unsigned int first_digit = 0;
unsigned int last_digit = 0;


int main()
{
	//std::cout << "Unesi broj kartice (bez zadnje znamenke) " << std::endl;
	//std::cin >> card_num;
	//std::cout << card_num;

	//card_num = 462765390853591; // last number is 8
	//card_num = 462765385035704; // last number is 8
	card_num = 462765390970578; // last number is 3
	
	// separate the digits of card number
	for (int i = 0; i < 15; i++)
	{
		divider = divider / 10;
		digits[i] = (card_num / divider ) % 10;
		std::cout << digits[i] << std::endl;
	}

	std::cout << "---------------" << std::endl;

	// multiply every second digits by 2
	for (int i = 0; i < 15; i++)
	{
		if (i % 2 == 0)
		{
			digits[i] = digits[i] * 2;			
		}
		std::cout << digits[i] << std::endl;
	}

	std::cout << "---------------" << std::endl;

	// process double digits
	for (int i = 0; i < 15; i++)
	{
		if (digits[i] > 9)
		{
			first_num = digits[i] / 10;
			second_num = digits[i] % 10;
			digits[i] = first_num + second_num;
		}
		std::cout << digits[i] << std::endl;
	}

	std::cout << "---------------" << std::endl;

	// the sum
	for (int i = 0; i < 15; i++)
	{
		sum += digits[i];		
	}
	std::cout << sum << std::endl;

	std::cout << "---------------" << std::endl;

	// get the last digit
	first_digit = sum / 10;
	std::cout << first_digit << std::endl;
	std::cout << "---------------" << std::endl;
	last_digit = (first_digit + 1) * 10 - sum;
	std::cout << last_digit << std::endl;
}

//------------------------ INCLUDES --------------------------- 
#include <iostream>

//------------------------- MACROS ----------------------------
#define CREDIT_CARD_NUMBERS				15

//-------------------- GLOBAL VARIABLES ----------------------- 
unsigned long long card_num = 0;
unsigned long long divider = 1000000000000000;
unsigned long long digits[15] = { 0 };
unsigned int first_num = 0;
unsigned int second_num = 0;
unsigned int sum = 0;
unsigned int first_digit = 0;
unsigned int last_digit = 0;

//---------------- PRIVATE FUNCTION PROTOTYPES ----------------
static void separate_digits (void);
static void multiply_digits (void);
static void process_double_digits (void);
static void get_sum (void);
static void get_last_digit (void);

int main()
{
	std::cout << "Unesi broj kartice (bez zadnje znamenke) " << std::endl;
	std::cin >> card_num;	

	// separate the digits of card number
	separate_digits();
	// multiply every second digits by 2
	multiply_digits();
	// process double digits
	process_double_digits();
	// get the sum
	get_sum();
	// get the last digit
	get_last_digit();
}

//------------------- PRIVATE FUNCTIONS ---------------------
static void separate_digits (void) 
{	
	for (int i = 0; i < CREDIT_CARD_NUMBERS; i++)
	{
		divider = divider / 10;
		digits[i] = (card_num / divider) % 10;		
	}
}

static void multiply_digits (void)
{
	for (int i = 0; i < CREDIT_CARD_NUMBERS; i++)
	{
		if (i % 2 == 0)
		{
			digits[i] = digits[i] * 2;
		}
	}
}

static void process_double_digits (void)
{
	for (int i = 0; i < CREDIT_CARD_NUMBERS; i++)
	{
		if (digits[i] > 9)
		{
			first_num = digits[i] / 10;
			second_num = digits[i] % 10;
			digits[i] = first_num + second_num;
		}
	}
}

static void get_sum (void)
{
	for (int i = 0; i < CREDIT_CARD_NUMBERS; i++)
	{
		sum += digits[i];
	}
}

static void get_last_digit (void)
{
	first_digit = sum / 10;
	last_digit = (first_digit + 1) * 10 - sum;
	std::cout << "The last digit of this card number is: " << last_digit << std::endl;
}
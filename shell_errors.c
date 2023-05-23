#include "main.h"
/**
 * conv_str_int - converts string to integer
 * @n:string to be converted
 *
 * Return:converted number, -1 otherwise
 */
int conv_str_int(char *n)
{
	int sign = 1;
	int j = 0;
	long int num = 0;

	if (*n == '+')
		n++;
	else if (*n == '-')
	{
		sign = -1;
		n++;
	}

	for (j = 0; n[j] != '\0'; j++)
	{
		if (n[j] >= '0' && n[j] <= '9')
		{
			num = num * 10 + (n[j] - '0');

			if (sign == 1 && num > INT_MAX)
				return (-1);
			else if (sign == -1 && -num < INT_MIN)
				return (-1);
		}
		else
		{
			return (-1); /* invalid character, return error */
		}
	}
	return (sign * num);
}
/**
 * print_msg - prints error message
 * @data:parameter
 * @strngs:string with error type
 *
 * Return:0 on success, -1 otherwise
 */
void print_msg(data_s *data, char strngs)
{
	_inputs(data->filename);
	_inputs(": ");
	print_deci(data->err_count, STDERR_FILENO);
	_inputs(": ");
	_inputs(data->argv[0]);
	_inputs(": ");
	_inputs(strngs);
}
/**
 * print_deci -prints a decimal number
 * @input: input
 * @filed:filedescriptor to write to
 *
 * Return:characters printed
 */
int print_deci(int input, int filed)
{
	FILE *stream = (filed == STDERR_FILENO) ? stderr : stdout;
	int count = 0;

	if (input < 0)
	{
		fputc('-', stream);
		count++;
		input = -input;
	}

	if (input == 0)
	{
		fputc('0', stream);
		count++;
		return (count);
	}

	int div = 1;

	while (div <= input / 10)

		div *= 10;

	while (div > 0)
	{
		int digit = input / div;

		fputc('0' + digit, stream);
		count++;
		input %= div;
		div /= 10;
	}

	return (count);
}
/**
<<<<<<< HEAD
 * remove_comms - replaces first instance '#' with '\0'
 * @addr:address of the string
 *
 * Return:0
 */
void remove_comms(char *addr)
{
	int j = 0;
	bool commentf = false;

	while (addr[j] != '\0')
	{
		if (addr[j] == '#' && (j == 0 || addr[j - 1] == ' '))
		{
			addr[j] = '\0';
			commentf = true;
			break;
		}
		j++;
	}
	if (commentf)
	{
		int i = j - 1;
=======
 * _numcon - converter function
 * @num:number
 * @base:base
 * @flags:argument flags
 *
 * Return:string
 */
char *_numcon(long int num, int base, int flags)
{
	static char fer[50];
	const char *digits = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
	bool isNegative = false;
	int index = 49;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		isNegative = true;
		num = -num;
	}

	fer[index--] = '\0';

	do {
		fer[index--] = digits[num % base];
		num /= base;
	} while (num != 0);

	if (isNegative)
		fer[index--] = '-';

	return (&fer[index + 1]);
}

>>>>>>> b7701f740093fc6e37d7170be051f52faac376a2

		while (i >= 0 && addr[i] == ' ')
		{
			addr[i] = '\0';
			i--;
		}
	}
}

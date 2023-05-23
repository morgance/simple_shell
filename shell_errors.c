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


#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome
 * @n: pointer to head
 * Return: 1 if palindrome 0 if not
 */

int is_palindrome(unsigned long n)
{
	unsigned long reverse = 0, reminder, temp;

	temp = n;
	while (temp != 0)
	{
		reminder = temp % 10;
		reverse = reverse * 10 + reminder;
		temp /= 10;
	}
	if (n == reverse)
		return (1);

	return (0);
}

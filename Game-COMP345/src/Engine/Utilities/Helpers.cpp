#include "Helpers.h"

int utilities::Helpers::mod(int num, int div)
{
	while (num > div)
		num -= div;

	while (num < div)
		num += div;

	return num;
}
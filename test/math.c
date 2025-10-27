#include <stdio.h>
#include "math_utils.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("missing argument:");
		return 1;
	}
	int radius = *argv[1] - '0';
	printf("Radius: %i\n", radius);
	printf("Cirumference: %i\n", circumference(radius));
	printf("Area of Circle: %i", circle_area(radius));
}

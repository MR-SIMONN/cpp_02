#include <iostream>

// int to_fixed (float c)
// {
// 	return (c * 256);
// }
// float to_float (int c)
// {
// 	return (c / 256.0);
// }

// int to_fixed (float c)
// {
// 	return (c << 8);
// }

// float to_float (int c)
// {
// 	return (c / 256.0);
// }

int main ()
{
	// int fixed = dicimal * (1 << 8);
	// int fixed = dicimal * ;
	float dicimal = 2.1;
	float hh =  dicimal;
	hh = hh << 8;
	std::cout << hh << std::endl;
}

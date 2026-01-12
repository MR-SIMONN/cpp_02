/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 10:07:33 by moel-hai            #+#    #+#             */
/*   Updated: 2026/01/10 13:42:35 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	std::cout << "a is declared like this ---> Fixed a;\n\n";
	Fixed a;
	std::cout << "b is declared like this ---> Fixed b(a);\n\n";
	Fixed b(a);
	std::cout << "c is declared like this ---> Fixed c;\n\n";
	Fixed c;
	std::cout << "c is inisilised like this ---> c = b\n\n";
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << "\n";
	std::cout << b.getRawBits() << std::endl;
	std::cout << "\n";
	std::cout << c.getRawBits() << std::endl;
	std::cout << "\n";
	return 0;
}

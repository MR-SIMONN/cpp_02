/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 10:14:31 by mihowk            #+#    #+#             */
/*   Updated: 2026/01/12 11:19:40 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->fixedPointValue / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->fixedPointValue >> fractionalBits;
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
    o << fixed.toFloat();
    return o;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:58:43 by moel-hai          #+#    #+#             */
/*   Updated: 2026/01/17 02:57:20 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0) {}

Fixed::Fixed(const int value)
{
    fixedValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    fixedValue = roundf(value * 256);
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    setRawBits(other.getRawBits());
    return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
    return (fixedValue);
}

void Fixed::setRawBits(int const raw)
{
    fixedValue = raw;
}

float Fixed::toFloat(void) const
{
    return (getRawBits() / 256.0f);
}

int Fixed::toInt(void) const
{
    return (getRawBits() >> fractionalBits);
}

bool Fixed::operator>(const Fixed& other) const
{
    return (getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
    return (getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
    return (getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (Fixed(toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++()
{
    fixedValue++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    fixedValue++;
    return (temp);
}

Fixed& Fixed::operator--()
{
    fixedValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    fixedValue--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
    o << fixed.toFloat();
    return (o);
}
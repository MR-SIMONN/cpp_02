/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 10:14:48 by mihowk            #+#    #+#             */
/*   Updated: 2026/01/12 11:19:37 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 fixedPointValue;
        static const int    fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif
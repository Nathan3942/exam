/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:25:36 by njeanbou          #+#    #+#             */
/*   Updated: 2025/05/22 12:17:37 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

bigint::bigint()
{
    _digits.push_back(0);
}

bigint::bigint(unsigned int n)
{
    if (n == 0)
        _digits.push_back(0);
    else
    {
        while (n > 0)
        {
            _digits.push_back(n % 10);
            n /= 10;
        }
    }
}

bigint::bigint(const bigint& copy) : _digits(copy._digits)
{

}

bigint::~bigint()
{

}

bigint& bigint::operator=(const bigint& equal)
{
    if (*this != equal)
        _digits = equal._digits;
    return (*this); 
}

bigint  bigint::operator+(const bigint& other) const
{
    bigint res;
    res._digits.clear();

    size_t  max_size = _digits.size() > other._digits.size() ? _digits.size() : other._digits.size();
    unsigned int carry = 0;

    for (size_t i = 0; i < max_size || carry; ++i)
    {
        unsigned int sum = carry;
        if (i < _digits.size())
            sum += _digits[i];
        if (i < other._digits.size())
            sum += other._digits[i];
        res._digits.push_back(sum % 10);
        carry = sum / 10;
    }
    return (res);
}

bigint& bigint::operator+=(const bigint& other)
{
    *this = *this + other;
    return (*this);
}

bigint& bigint::operator++()
{
    *this += bigint(1);
    return (*this);
}

bigint  bigint::operator++(int)
{
    bigint tmp(*this);
    ++(*this);
    return (tmp);
}

bigint  bigint::operator<<(unsigned int n) const
{
    bigint result(*this);
    for (unsigned int i = 0; i < n; ++i)
    {
        result._digits.insert(result._digits.begin(), 0);
    }
    return (result);
}

void    bigint::remove_leading_zero()
{
    while (_digits.size() > 1 && _digits.back() == 0)
        _digits.pop_back();
}

bigint bigint::operator>>(unsigned int n) const 
{
    bigint result(*this);
    if (n >= result._digits.size())
        return (bigint(0));
    result._digits.erase(result._digits.begin(), result._digits.begin() + n);
    result.remove_leading_zero();
    return (result);
}

bigint& bigint::operator>>=(const bigint& other)
{
    unsigned int n = 0;
    for (int i = other._digits.size() - 1; i >= 0; --i)
        n = n * 10 + other._digits[i];
    *this = *this >> n;
    return (*this);
}

bool    bigint::operator<(const bigint& other) const
{
    if (_digits.size() != other._digits.size())
        return (_digits.size() < other._digits.size());
    for (int i = _digits.size() - 1; i >= 0; --i)
    {
        if (_digits[i] != other._digits[i])
            return (_digits[i] < other._digits[i]);
    }
    return (false);
}

bool    bigint::operator>(const bigint& other) const
{
    return (other < *this);
}

bool    bigint::operator<=(const bigint& other) const
{
    return !(other < *this);
}

bool    bigint::operator>=(const bigint& other) const
{
    return !(*this < other);
}

bool    bigint::operator==(const bigint& other) const 
{
    return (_digits == other._digits);
}

bool    bigint::operator!=(const bigint& other) const 
{
    return !(*this == other);
}

std::ostream&   operator<<(std::ostream& out, const bigint& n)
{
    for (int i = n._digits.size() - 1; i >= 0; --i)
        out << static_cast<char>('0' + n._digits[i]);
    return (out);
}

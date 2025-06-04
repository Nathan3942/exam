/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:25:44 by njeanbou          #+#    #+#             */
/*   Updated: 2025/05/22 12:15:06 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <vector>


class bigint
{
    private:
        std::vector<unsigned char> _digits;

        void    remove_leading_zero();

    public:
        bigint();
        bigint(unsigned int n);
        bigint(const bigint& copy);
        ~bigint();

        bigint& operator=(const bigint& equal);

        bigint  operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);
        bigint& operator++();   //prefix
        bigint  operator++(int);

        bigint  operator<<(unsigned int n) const;
        bigint  operator>>(unsigned int n) const;
        bigint& operator>>=(const bigint& other);

        bool    operator<(const bigint& other) const;
        bool    operator>(const bigint& other) const;
        bool    operator<=(const bigint& other) const;
        bool    operator>=(const bigint& other) const;
        bool    operator==(const bigint& other) const;
        bool    operator!=(const bigint& other) const;

        friend std::ostream&   operator<<(std::ostream& out, const bigint& n);
        
};





#endif 
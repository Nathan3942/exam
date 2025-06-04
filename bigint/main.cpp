/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:12:34 by njeanbou          #+#    #+#             */
/*   Updated: 2025/05/22 12:12:43 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

int main(void)
{
    const bigint a(42);
    bigint b(21), c, d(1337), e(d);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "(c += a) = " << (c += a) << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "++b = " << ++b << std::endl;
    std::cout << "b++ = " << b++ << std::endl;
    std::cout << "(b << 10) + 42 = " << (b << 10) + 42  << std::endl;
std::cout << "d = " << d << std::endl;
    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "(d < a) = " << (d < a) << std::endl;
    std::cout << "(d > a) = " << (d > a) << std::endl;
    std::cout << "(d == a) = " << (d == a) << std::endl;
    std::cout << "(d != a) = " << (d != a) << std::endl;
    std::cout << "(d <= a) = " << (d <= a) << std::endl;
    std::cout << "(d >= a) = " << (d >= a) << std::endl;

    return 0;
}
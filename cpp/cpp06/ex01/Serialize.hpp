/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialize.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 10:42:06 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/09 10:42:07 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <cstdint>

# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[m"

typedef struct s_Data {
    std::string name;
    int age;
} Data;

// uintptr_t: an unsigned integer type with the property that any valid pointer to void can be converted to this type,
// then converted back to pointer to void, and the result will compare equal to the original pointer
// Usage: primarily for bitwise operations on pointers.

uintptr_t serialize(Data *ptr);

Data *deserialize(uintptr_t raw);

#endif //SERIALIZE_HPP

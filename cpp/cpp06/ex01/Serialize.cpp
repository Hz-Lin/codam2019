/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialize.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 10:41:59 by hlin          #+#    #+#                 */
/*   Updated: 2022/06/09 10:42:01 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

// reinterpret cast: converts any pointer type to any other pointer type, even of unrelated classes.
// usually use it when you want to change the type of raw data

uintptr_t serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}

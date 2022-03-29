/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 22:12:03 by hlin          #+#    #+#                 */
/*   Updated: 2022/03/22 22:56:56 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {

public:
	Contact();
	~Contact();
	int     index;
	void    displayColumns() const;
	void    displayAllInfo() const;
	void    update(int i);

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNum;
	std::string _darkestSecret;
};

#endif

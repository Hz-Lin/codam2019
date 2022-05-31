/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 17:42:15 by hlin          #+#    #+#                 */
/*   Updated: 2022/05/26 17:42:16 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &obj);
	virtual ~Intern();

	Intern &operator=(const Intern &obj);

	AForm *makeForm(const std::string &formName, const std::string &target) const;

	class NonExistenceFormException : public std::exception {
	public:
		const char *what() const throw();
	};
};

#endif //INTERN_HPP

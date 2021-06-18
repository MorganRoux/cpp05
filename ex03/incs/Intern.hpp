/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 22:52:00 by mroux             #+#    #+#             */
/*   Updated: 2021/06/18 23:17:01 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		class 			FormTypeUnknown : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "Form type unknown";
			}
		};

		Intern();
		~Intern();
		Intern(Intern const&);
		Intern&			operator=(Intern const&);
		Form* 			makeForm(std::string const& type, std::string const& target) throw(FormTypeUnknown);

	protected:
		typedef struct	s_builders {
			std::string	formType;
			Form* 		(*f)(std::string const& target);
		}				t_builders;

};

#endif

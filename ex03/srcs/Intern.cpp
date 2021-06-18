/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 22:51:57 by mroux             #+#    #+#             */
/*   Updated: 2021/06/18 23:21:26 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

static Form*		createPresidentialPardonForm(std::string const& target);
static Form*		createRobotomyRequestForm(std::string const& target);
static Form*		createShrubberyCreationForm(std::string const& target);

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(Intern const& cl)
{
	operator=(cl);
}

Intern&	Intern::operator=(Intern const& cl)
{
	(void) cl;
	return (*this);
}

Form* 	Intern::makeForm(std::string const& formType, std::string const& target) throw(FormTypeUnknown)
{
	t_builders	builders[3] = {
		{"PresidentialPardonForm", &createPresidentialPardonForm},
		{"RobotomyRequestForm", &createRobotomyRequestForm},
		{"ShrubberyCreationForm", &createShrubberyCreationForm}
	};
	Form*		f;
	int			i;

	for (i = 0; i < 3; i++)
	{
		if (formType.compare(builders[i].formType) == 0)
		{
			f = builders[i].f(target);
			std::cout << "Intern create " << *f << std::endl;
			return f;
		}
	}
	throw FormTypeUnknown();
	return NULL;
}


Form*		createPresidentialPardonForm(std::string const& target)
{
	return (new PresidentialPardonForm(target));
}

Form*		createRobotomyRequestForm(std::string const& target)
{
	return (new RobotomyRequestForm(target));
}

Form*		createShrubberyCreationForm(std::string const& target)
{
	return (new ShrubberyCreationForm(target));
}

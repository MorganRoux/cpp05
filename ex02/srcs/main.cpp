/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:28:42 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 21:41:39 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	ShrubberyCreationForm 	f("maison");
	RobotomyRequestForm		r("humain");
	PresidentialPardonForm	p("voleur");

	Bureaucrat 				b("Morgan", 146), a("Eric", 7);

	a.signForm(r);
	a.executeForm(r);
	a.executeForm(p);
	a.signForm(p);
	a++;a++;a++;a++;
	std::cout << a << std::endl;
	a.executeForm(p);
	b.executeForm(f);
	b.signForm(f);
	b++;
	b.signForm(f);
	b.executeForm(f);
	b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;
	std::cout << b << std::endl;
	b.executeForm(f);

}

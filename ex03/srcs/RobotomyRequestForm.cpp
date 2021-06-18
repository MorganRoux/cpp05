/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:19:32 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 21:28:22 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	Form("RobotomyRequestForm", 72, 45, "cible inconnu")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	Form("RobotomyRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& cl)
{
	operator=(cl);
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& cl)
{
	Form::operator=(cl);
	return (*this);
}

void					RobotomyRequestForm::do_execute()
{
	std::cout << "BZZ bZZZ BZZ " << getTarget() << " a été robotomisé." << std::endl;
}

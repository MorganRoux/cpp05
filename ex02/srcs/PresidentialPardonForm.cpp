/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 21:37:18 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 21:38:12 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	Form("PresidentialPardonForm", 25, 5, "cible inconnu")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	Form("PresidentialPardonForm", 25, 5, target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& cl)
{
	operator=(cl);
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& cl)
{
	Form::operator=(cl);
	return (*this);
}

void					PresidentialPardonForm::do_execute()
{
	std::cout << getTarget() << " a été pardonné par Zafod Beeblebrox" << std::endl;
}

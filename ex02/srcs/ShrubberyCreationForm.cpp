/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:19:32 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 20:55:13 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	Form("ShrubberyCreationForm", 145, 137), _target("cible inconnu")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string cible):
	Form("ShrubberyCreationForm", 145, 137), _target(cible)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& cl)
{
	operator=(cl);
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& cl)
{
	_target = cl._target;
	return (*this);
}

std::string const&		ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void					ShrubberyCreationForm::do_execute()
{
	std::fstream strm;
	strm.open(_target, std::ios::out);
	strm << "arbre" << std::endl;
}

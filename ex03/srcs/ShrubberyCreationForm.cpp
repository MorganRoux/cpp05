/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:19:32 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 21:28:22 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	Form("ShrubberyCreationForm", 145, 137, "cible inconnu")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	Form("ShrubberyCreationForm", 145, 137, target)
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
	Form::operator=(cl);
	return (*this);
}

void					ShrubberyCreationForm::do_execute()
{
	std::fstream strm;
	strm.open(getTarget(), std::ios::out);
	strm << "arbre" << std::endl;
}

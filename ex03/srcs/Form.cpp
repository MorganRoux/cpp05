/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:18:45 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 21:24:16 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default Form"), _signGrade(150), _execGrade(150), _signed(false), _target("cible inconnue")
{
}

Form::Form(std::string name, int signGrade, int execGrade, std::string target) throw(Form::GradeTooHighException, Form::GradeTooLowException) :
	_name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false), _target(target)
{
	if (_signGrade < 1 || _execGrade < 1)
	{
		throw GradeTooHighException();
	}
	if (_signGrade > 150 || _execGrade > 150)
	{
		throw GradeTooLowException();
	}
}

Form::~Form()
{
}

Form::Form(Form const &cl) throw(Form::GradeTooHighException, Form::GradeTooLowException) : _name(cl._name), _signGrade(cl._signGrade), _execGrade(cl._execGrade), _signed(cl._signed)
{
	if (_signGrade < 1 || _execGrade < 1)
	{
		throw GradeTooHighException();
	}
	if (_signGrade > 150 || _execGrade > 150)
	{
		throw GradeTooLowException();
	}
}

Form&				Form::operator=(Form const &cl)
{
	(void)cl;
	std::cout << "Formulaire infalsifiable" << std::endl;
	return (*this);
}

void 				Form::display(std::ostream &stream) const
{
	stream << "Form " << _name << " - grade : " << _signGrade << " / " << _execGrade << " - " << (_signed ? "SIGNED" : "NOT SIGNED") << std::endl;
}

std::string const&	Form::getName() const
{
	return _name;
}

bool 				Form::isSigned() const
{
	return _signed;
}

int 				Form::getSignGrade() const
{
	return _signGrade;
}

int 				Form::getExecGrade() const
{
	return _execGrade;
}

std::string	const&	Form::getTarget() const
{
	return _target;
}

void 				Form::beSigned(Bureaucrat const &b) throw(Form::GradeTooHighException)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooHighException();
	_signed = 1;
}

void 				Form::execute(Bureaucrat const &executor) throw(Form::NotSignedException, Form::GradeTooHighException)
{
	if (_signed == false)
		throw NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooHighException();
	do_execute();
}

std::ostream 		&operator<<(std::ostream &stream, Form const &cl)
{
	cl.display(stream);
	return (stream);
}

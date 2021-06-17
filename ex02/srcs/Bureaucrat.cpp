/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:02:48 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 21:11:21 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	_grade = 150;
	_name = "Pion";
}

Bureaucrat::Bureaucrat(std::string name, int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException) :
	_name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}
Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &cl)
{
	operator=(cl);
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &cl)
{
	_name = cl._name;
	_grade = cl._grade;
	return (*this);
}

void Bureaucrat::display(std::ostream &stream) const
{
	stream << _name << ", bureaucrat grade " << _grade;
}

std::string const& 	Bureaucrat::getName() const
{
	return _name;
}
int 			Bureaucrat::getGrade() const
{
	return _grade;
}
void 			Bureaucrat::operator++(int) throw(Bureaucrat::GradeTooHighException)
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void 			Bureaucrat::operator--(int) throw(Bureaucrat::GradeTooLowException)
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void			Bureaucrat::signForm(Form& f) const
{
	try {
		f.beSigned(*this);
		std::cout << _name << " succesfully signs " << f.getName() << std::endl;
	}
	catch(std::exception& e) {
		std::cout << _name << " can't sign " << f.getName() << " because " << e.what()  << std::endl;
	}
}

void			Bureaucrat::executeForm(Form& f) const
{
	try {
		f.execute(*this);
		std::cout << _name << " executes " << f.getName() << std::endl;
	}
	catch(std::exception& e) {
		std::cout << _name << " can't execute form because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &cl)
{
	cl.display(stream);
	return (stream);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:18:49 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 19:58:57 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	class 				GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Form Grade too high";
		}
	};

	class 				GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Form Grade too low";
		}
	};

	Form();
	Form(std::string name, int signGrade, int execGrade) throw(Form::GradeTooHighException, Form::GradeTooLowException);
	~Form();
	Form(Form const &) throw(GradeTooHighException, GradeTooLowException);
	Form &operator=(Form const &);
	void display(std::ostream &stream) const;
	std::string const&	getName();
	bool				isSigned();
	int					getSignGrade();
	int					getExecGrade();
	void				beSigned(Bureaucrat& b) throw(GradeTooHighException);

private:
	const std::string 	_name;
	const int 			_signGrade;
	const int 			_execGrade;
	bool 				_signed;


};

std::ostream &operator<<(std::ostream &stream, Form const &cl);

#endif


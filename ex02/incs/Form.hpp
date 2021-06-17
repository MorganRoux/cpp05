/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:18:49 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 21:21:07 by mroux            ###   ########.fr       */
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

	class 				NotSignedException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Form not signed";
		}
	};

	Form();
	Form(std::string name, int signGrade, int execGrade, std::string target) throw(Form::GradeTooHighException, Form::GradeTooLowException);
	~Form();
	Form(Form const &) throw(GradeTooHighException, GradeTooLowException);
	Form &operator=(Form const &);
	void display(std::ostream &stream) const;
	std::string const&	getName() const;
	bool				isSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	std::string const&	getTarget() const;
	void				beSigned(Bureaucrat const& b) throw(GradeTooHighException);
	void				execute(Bureaucrat const& executor) throw (Form::NotSignedException, Form::GradeTooHighException);
	virtual void		do_execute() = 0;
private:
	const std::string 	_name;
	const int 			_signGrade;
	const int 			_execGrade;
	bool 				_signed;
	std::string			_target;


};

std::ostream &operator<<(std::ostream &stream, Form const &cl);

#endif


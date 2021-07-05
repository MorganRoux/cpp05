/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:02:44 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 19:33:55 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
public:
	class 			GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Grade too high";
		}
	};

	class 			GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Grade too low";
		}
	};

	Bureaucrat(std::string name, int grade) throw(GradeTooHighException, GradeTooLowException);
	virtual ~Bureaucrat();
	Bureaucrat(Bureaucrat const &);
	Bureaucrat 			&operator=(Bureaucrat const &);
	void 				display(std::ostream &stream) const;
	std::string const& 	getName() const;
	int 				getGrade() const;
	void 				operator++(int) throw(GradeTooHighException);
	void 				operator--(int) throw(GradeTooLowException);

protected:
	Bureaucrat();
	std::string const	_name;
	int 				_grade;
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &cl);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:02:44 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 19:58:32 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	class 			GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Bureaucrat Grade too high";
		}
	};

	class 			GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return " Bureaucrat Grade too low";
		}
	};

	Bureaucrat();
	Bureaucrat(std::string name, int grade) throw(GradeTooHighException, GradeTooLowException);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &);
	Bureaucrat 		&operator=(Bureaucrat const &);
	void 			display(std::ostream &stream) const;
	std::string& 	getName();
	int 			getGrade();
	void 			operator++(int) throw(GradeTooHighException);
	void 			operator--(int) throw(GradeTooLowException);
	void			signForm(Form& f);

protected:
	std::string _name;
	int 		_grade;
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &cl);

#endif

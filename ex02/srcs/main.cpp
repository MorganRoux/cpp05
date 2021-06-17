/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:28:42 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 21:11:48 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	ShrubberyCreationForm f("maison");
	Bureaucrat b("Morgan", 146);

	b.executeForm(f);
	b.signForm(f);
	b++;
	b.signForm(f);
	b.executeForm(f);
	b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;b++;
	std::cout << b << std::endl;
	b.executeForm(f);

}

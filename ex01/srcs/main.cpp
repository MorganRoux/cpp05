/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:46:00 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 20:01:49 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{

		Form f1("F1", 10, 10);
		Form f2("F2", 20, 20);
		Bureaucrat b("Jacky", 15);

	try {
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << b << std::endl;
		b.signForm(f2);
		b.signForm(f1);
	}
	catch(std::exception& e) {
		std::cout << "Erreur : " << e.what() << std::endl;
	}
	std::cout << f1.isSigned() << std::endl;
	std::cout << f2.isSigned() << std::endl;
}

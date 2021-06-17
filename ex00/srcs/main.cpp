/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:02:50 by mroux             #+#    #+#             */
/*   Updated: 2021/06/17 19:10:58 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b("Eric", 4);
	Bureaucrat b2("Javier", 149);

	std::cout << b << std::endl;
	b--;
	std::cout << b << std::endl;
	try {
		b++;
		b++;
		b++;
		b++;
		b++;
	}
	catch(std::exception& e) {
		std::cout << "Erreur : " << e.what() << std::endl;
	}
	std::cout << b.getGrade() << std::endl;
	std::cout << b.getName() << std::endl;

	try {
		std::cout << b2 << std::endl;
		b2--;
		std::cout << b2 << std::endl;
		b2--;
	}
	catch(std::exception& e) {
		std::cout << "Erreur : " << e.what() << std::endl;
	}
}

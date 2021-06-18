#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <string>
# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string _cible);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const&);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& cl);
		virtual void			do_execute();
};

std::ostream&	operator<<(std::ostream& stream, ShrubberyCreationForm const& cl);

#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:34:30 by nikitos           #+#    #+#             */
/*   Updated: 2024/01/25 22:02:25 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default_name"), _gradeSign(1) , _gradeExec(1) , _sign(false), _correctCreation(0)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form( std::string name, int gSign, int gExec ) : _name(name), _gradeSign(gSign) , _gradeExec(gExec) , _sign(false), _correctCreation(0)
{
	std::cout << "Form constructor called" << std::endl;
	try
	{
		if (gSign < 1 || gExec < 1)
			throw Form::GradeTooHighException();
		else if (gSign > 150 || gExec > 150)
			throw Form::GradeTooLowException();
		else
		{
			std::cout << "Form creation with name: " << _name << " and grade sign: "<< _gradeSign;
			std::cout << " and also with grade exec: " << _gradeExec << " is made !" << std::endl;
		}
	}
	catch(const std::exception &er)
	{
		std::cout << "Creation exception thrown: " << er.what() << std::endl;
		_correctCreation = 1;
	}
}

Form::~Form()
{
	std::cout << "Form destructor is called" << std::endl;
}

Form::Form(Form const &src) : _name(src.getName()), _gradeExec(src.getGradeExec()), _gradeSign(src.getGradeSign()), _correctCreation(src.getCorrectCreation())
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

Form &Form::operator=(Form const &src)
{
	if (this == &src)
		return *this;
	this->_sign = src.getSign();
	std::cout << "Form copy assignment constructor called" << std::endl;
	return *this;
}

const char 	*Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char	*Form	::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char 	*Form::AlreadySigned::what() const throw()
{
	return "Already signed!";
}

const char 	*Form::incorrectCreation::what() const throw()
{
	return "Incorrect form creation :( ";
}

std::ostream& operator<<(std::ostream &os, const Form &src)
{
	os << "--- You are requested information about Form ---" << std::endl;
	os << "-> Name: "<< src.getName() << std::endl;
	os << "-> Grade sign: " << src.getGradeSign() << std::endl;
	os << "-> Grade execution: " << src.getGradeExec() << std::endl;
	os << "-> Sign: " << src.getSign() << std::endl;
	os << "------------------------------------------------" << std::endl;
	return ( os );
}

std::string	Form::getName() const
{
	return ( this->_name );
}

int	Form::getGradeSign() const
{
	return ( this->_gradeSign );
}

int			Form::getGradeExec() const
{
	return ( this->_gradeExec );
}

bool	Form::getSign() const
{
	return ( this->_sign );
}

int	Form::getCorrectCreation() const
{
	return this->_correctCreation;
}

void	Form::beSigned( Bureaucrat &obj )
{
	try
	{
		if (this->_sign == 1)
			throw Form::AlreadySigned();
		else if (this->getCorrectCreation())
			throw Form::incorrectCreation();
		else if (obj.getGrade() > this->getGradeSign())
			throw Form::GradeTooLowException();
		else
			this->_sign = true;
	}
	catch(const std::exception& e)
	{
		std::cout << "Can not be sign because: " << e.what() << std::endl;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/28 10:12:26 by spyun         #+#    #+#                 */
/*   Updated: 2025/07/28 11:22:43 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade)
	: _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	if (signGrade < MAX_GRADE || executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (signGrade > MIN_GRADE || executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade), _isSigned(other._isSigned) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const
{
	return _name;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}


bool Form::getIsSigned() const
{
	return _isSigned;
}

void Form::beSigned(int bureaucratGrade)
{
	if (bureaucratGrade < _signGrade)
	{
		_isSigned = true;
		std::cout << _name << " has been signed by bureaucrat with grade " << bureaucratGrade << std::endl;
	}
	else
	{
		throw GradeTooLowException();
	}
}

const char *Form::GradeTooHighException::what() const noexcept
{
	return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName()
	   << ", Sign Grade: " << form.getSignGrade()
	   << ", Execute Grade: " << form.getExecuteGrade()
	   << ", Signed: " << (form.getIsSigned() ? "Yes" : "No");
	return os;
}

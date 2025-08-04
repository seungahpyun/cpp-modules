/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/30 08:59:57 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/04 09:00:09 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < MAX_GRADE || executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (signGrade > MIN_GRADE || executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
		// _name, _signGrade, and _executeGrade are const, so they cannot be assigned
	}
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm: " << form.getName()
	<< ", Signed: " << (form.isSigned() ? "Yes" : "No")
	<< ", Sign Grade: " << form.getSignGrade()
	<< ", Execute Grade: " << form.getExecuteGrade();
	return os;
}

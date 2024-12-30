/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ): _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << this->getName() << ", bureaucrat grade " << this->getGrade() << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Time to clockout! See you tomorrow morning, Linda!" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& ref ): _name(ref._name), _grade(ref._grade)
{
	std::cout << "Copy constructor of bureaucrat " << _name << std::endl;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat& ref )
{
	if (this != &ref)
		this->_grade = ref.getGrade();
	return (*this);
}

void	Bureaucrat::changeGrade( int8_t grade )
{
	if (grade > 0)
		this->_grade += -grade;
	else
		this->_grade -= grade;
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        if (form.getSignature() == false) 
        {
            if (this->getGrade() > form.getSignatureGrade())
            {
                std::cerr << this->getName() << " couldn't sign " << form.getName() << " because signature grade is too low" << std::endl;
                throw GradeTooLowException();
            }
            form.beSigned(*this);
            std::cout << this->getName() << " signed " << form.getName() << std::endl;
        }
        else
            throw AForm::AlreadySigned();
    }
    catch (GradeTooLowException &error)
    {
        std::cerr << "Exception: " << error.what() << std::endl;
    }
    catch (AForm::AlreadySigned &error)
    {
        std::cerr << "Exception: " << error.what() << std::endl;
    }
}


std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int16_t	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::ostream	&operator<<(std::ostream &other, const Bureaucrat& ref)
{
	other << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return (other);
}

void	Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        if (this->getGrade() > form.getExecutionGrade())
            throw GradeTooLowException();
        if (form.getSignature() == false)
            throw AForm::NotSigned();
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (GradeTooLowException &error)
    {
        std::cerr << "Officer could not execute: " << error.what() << std::endl;
    }
    catch (AForm::NotSigned &error)
    {
        std::cerr << "Form not signed: " << error.what() << std::endl;
    }
}


const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("You're really good at your job! And in the public sector that means you are fired!");
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("This is outrageous! I demand your immediate official office removal!");
}
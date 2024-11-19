/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#pragma once

#include <iostream>

/** 
 * ### ABOUT PARTIALLY AND PURELY ABSTRACT CLASSES
 * 
 * When talking about abstract classes, we need to separate what is a purely
 * abstract class and what is a partially abstract class.
 * 
 * #### PARTIALLY ABSTRACT CLASSES
 * 
 * Partially abstract classes can have functionalities within themselves, which
 * means that you can still customize the class itself, such as our Animal class.
 * However, what we wanted at the end of the day is to create a base for the `Dog`
 * and `Cat` classes to inherit and use.
 * 
 * Because of the nature of partial abstract classes, they should not have member
 * variables at all. It is expected that the derived classes (`Dog` or `Cat`)
 * should provide these variables.
 * 
 * #### PURE ABSTRACT CLASSES
 * 
 * Pure abstract classes should contain no member variables and just pass on functionalities
 * to the derived classes.
 * 
 * To exemplify, if you imagine that we have a class called `Cars` and a derived class `SUVS`
 * you imagine that all cars share some core functionalities: `MoveForward()`, `MoveBackwards()`,
 * `Turn()`, and so on. But our derived class `SUV` will have those and extra functionalities,
 * such as `OffRoad()` or something like that. 
 * 
 * #### OTHER INTERESTING STUFF
 * 
 * The objective of this exercise seems silly, but it has a genuine intention of showing 
 * that one cannot simply have a "generic animal" instantiated. One cannot simply have a
 * "standard animal" as a pet. Therefore, we need to make it impossible for `AAnimal` to
 * be instantiated (initialized in `main()`).
 * 
 * However, keep in mind that does not mean we cannot initialize `AAnimal` if we use
 * polymorphism.
 */
class AAnimal
{
	private:
		std::string _type;
	protected:
		// Constructor
		AAnimal();
		AAnimal( std::string );
	public:
		// Destructor
		virtual ~AAnimal() = 0;
		
		// Orthodox Canonical Form
		AAnimal( const AAnimal &other );
		AAnimal &operator=( const AAnimal &other );
		
		// Public methods
		virtual void makeSound() const = 0; // pure virtual function
		
		// Getter
		virtual std::string getType() const;
};

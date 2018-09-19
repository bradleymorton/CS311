//Definitions of Product class
//By Bradley Morton

#include "product.h" //Prototypes declared in other file
#include <sstream> //for ostringstream
	//Default constructor, initializes string and integer to zero
	//Preconditions-none
	//Postconditions-product name is left empty, inventory is set to zero
	Product::Product()
	{
		_inventory=0;
		_product="";
	}


	//Constructor that takes a name and number
	//Preconditions-none
	//Postconditions-product name is set to string given, inventory is set to number given
	Product::Product(std::string name, int number)
	{
		_product=name;
		_inventory=number;
	}


	//Gives name of the product
	//No pre or post conditions- if no name has been given, it is defaulted to being empty
	std::string Product::getName()const
	{
		return _product;
	}


	//Returns the inventory
	//Precondition-inventory must be greater than or equal to zero
	//No postconditions
	int Product::getInventory()const
	{
		return _inventory;
	}


	//Sets name of product
	//No preconditions
	//Postcondition-name of product is set to string being passed in
	void Product::setName(std::string name)
	{
		_product=name;
	}


	//Sets inventory to incoming number
	//Precondition-incoming number must be greater than or equal to zero
	//Postcondition-inventory is equal to incoming number
	void Product::setInventory(int number)
	{
		_inventory=number;
	}


	//Tells whether or not inventory is empty-returns 0 if inventory==0,
	//returns 1 otherwise
	//Precondition-inventory must be greater than or equal to zero
	//No postconditions
	bool Product::empty()const
	{
		if(_inventory==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}


	//Returns string giving product name and number held in inventory\
	//No pre or post conditions
	std::string Product::toString()const
	{
		std::ostringstream output;
		output<<_product<<" ("<<_inventory<<")";//<<;std::endl;
		return output.str();
	}


	//Returns a 1 if both the product name and inventory are equal
	//Otherwise returns 0
	//No pre or post conditions
	bool Product::operator == (const Product & otherProduct)const
	{
		if((this->_product==otherProduct._product)&&(this->_inventory==otherProduct._inventory))
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	//Returns a 0 if both the product name and inventory are equal
	//Otherwise returns 1
	//No pre or post conditions
	bool Product::operator != (const Product & otherProduct)const
	{
		return !(*this == otherProduct);
	}


	//Preincrement, increases value of inventory by 1, then returns the Product
	//No precondition, postcondition is inventory is 1 higher than before
	Product & Product::operator++()
	{
		++this->_inventory;
		return *this;
	}


	//Postincrement-makes copy, increases inventory by 1, then returns copy
	//No precondition, postcondition is inventory is 1 higher than before
	Product Product::operator++(int dummy)
	{
		Product temp(*this);
		++*this;
		return temp;
	}


	//Decrement inventory by 1, then return
	//No precondition, postcondition is that inventory cannot be below 0; if already zero, remains zero
	Product & Product::operator--()
	{
		if(this->_inventory==0)
		{
			return *this;
		}
		else
		{
			this->setInventory(getInventory()-1);
			return *this;
		}
	}


	//Create copy, then reduce inventory by 1, then return copy
	//No precondition, postcondition is inventory cannot be below zero; if already zero, value is not reduced
	Product Product::operator--(int dummy)
	{
		Product temp(*this);
		if(_inventory==0)
		{
			return *this;
		}
		else
		{
			--*this;
			return temp;
		}
	}



	//This is the overloaded insertion operator, which allows printing with a standard cout object. 
	//There are no preconditions or postconditions. 
	std::ostream& operator<<(std::ostream& os, const Product & product)
	{
		os<<product.toString();
		return os;
	}


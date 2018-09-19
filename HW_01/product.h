//Prototypes of Product class
//By Bradley Morton
#ifndef product_h
#define product_h 

#include <string>
#include <iostream>


class Product 
{
private: 
	std::string _product;
	int _inventory;
public: 
	//Big five default functions
	~Product()=default;
	Product(const Product & otherProduct)=default;
	Product(Product && otherProduct)=default;
	Product & operator = (const Product & otherProduct)=default;
	Product & operator = (Product && otherProduct)=default;


	//Default constructor, initializes string and integer to zero
	//Preconditions-none
	//Postconditions-product name is left empty, inventory is set to zero
	Product();


	//Constructor that takes a name and number
	//Preconditions-none
	//Postconditions-product name is set to string given, inventory is set to number given
	Product(std::string name, int number);


	//Gives name of the product
	//No pre or post conditions- if no name has been given, it is defaulted to being empty
	std::string getName() const;


	//Returns the inventory
	//Precondition-inventory must be greater than or equal to zero
	//No postconditions
	int getInventory()const;


	//Sets name of product
	//No preconditions
	//Postcondition-name of product is set to string being passed in
	void setName(std::string name);


	//Sets inventory to incoming number
	//Precondition-incoming number must be greater than or equal to zero
	//Postcondition-inventory is equal to incoming number
	void setInventory(int number);


	//Tells whether or not inventory is empty-returns 0 if inventory==0,
	//returns 1 otherwise
	//Precondition-inventory must be greater than or equal to zero
	//No postconditions
	bool empty()const;


	//Returns string giving product name and number held in inventory\
	//No pre or post conditions
	std::string toString()const;


	//Returns a 1 if both the product name and inventory are equal
	//Otherwise returns 0
	//No pre or post conditions
	bool operator == (const Product & otherProduct)const;


	//Returns a 0 if both the product name and inventory are equal
	//Otherwise returns 1
	//No pre or post conditions
	bool operator != (const Product & otherProduct)const;


	//Preincrement, increases value of inventory by 1, then returns the Product
	//No precondition, postcondition is inventory is 1 higher than before
	Product & operator++();


	//Postincrement-makes copy, increases inventory by 1, then returns copy
	//No precondition, postcondition is inventory is 1 higher than before
	Product operator++(int temp);


	//Decrement inventory by 1, then return
	//No precondition, postcondition is that inventory cannot be below 0; if already zero, remains zero
	Product & operator--();


	//Create copy, then reduce inventory by 1, then return copy
	//No precondition, postcondition is inventory cannot be below zero; if already zero, value is not reduced
	Product operator--(int temp);


	
};

//String insertion operator to convert contents to a string
	std::ostream& operator<<(std::ostream& os, const Product & );


#endif
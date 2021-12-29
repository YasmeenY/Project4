/****************************************************************************************************************************
Title        : ShoppingCart.hpp
Auhors       : Nursima Donuk & Nigel Ferrer
Description  : header/interface file of a ShoppingCart class which inherits from the ArrayBag class
Dependencies : ArrayBag.hpp, Grocery.hpp
****************************************************************************************************************************/

#ifndef SHOPPING_CART_
#define SHOPPING_CART_

#include "ArrayBag.hpp"
#include "Grocery.hpp"

#define CARRYING_CAP 350 // capacity of the cart in lbs

class ShoppingCart : public ArrayBag<Grocery *>
{
public:
    /* Default Constructor */
    ShoppingCart();

    /* Destructor */
    ~ShoppingCart();

    /**
        adds new_entry to the caller; if the entry already exists in 
                        the caller, increment quantity_ in the object
        @pre    :   the addition of the weight of 
                        new_entry does not bring the
                        curr_contents_weight_ over the 
                        carrying capacity
        @return :   true if the addition was successful; false otherwise            
    */
    bool add(Grocery *new_entry);

    /**
        removes an_item to the caller; if the entry already exists in the 
                        caller, decrement quantity_ in the object
                        -> Calls garbageClear() <-
            @return :   true if the removal was successful; false otherwise         
        */
    bool remove(Grocery *an_item);

    /**
        displays shopping cart contents in required format
        @post : called ArrayBag::clear()
    */
    double checkout();

    /** 
        iterates through caller and removes items that have quantity_ == 0   
        @post : every item in the caller has quantity_ >= 1
    */
    void garbageClear();

    /* Getter: curr_contents_weight_ */
    double getCurrentWeight();

    /* Getter: items_ */
    Grocery **getItems();

    /**  
        Implements Greater Than Comparison  
        A ShoppingCart is greater than another ShoppingCart if the total cost of its items is greater.  
        @param a_cart to be compared with this (the calling) cart  
        @return true if the total cost of this (the calling) cart is greater than the total cost of items in 
        a_cart.  
    **/
    bool operator>(ShoppingCart a_cart);

    /**  
        Implements Less Than Comparison  
        A ShoppingCart is less than another ShoppingCart if the total cost of its items is less.  
        @param a_cart to be compared with this (the calling) cart  
        @return true if the total cost of this (the calling) cart is less than the total cost of items in 
        a_cart.  
    **/
    bool operator<(ShoppingCart a_cart);

private:
    double curr_contents_weight_;
}; // end ShoppingCart

#endif

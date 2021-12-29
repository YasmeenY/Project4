/****************************************************************************************************************************
Title          :   ArrayBag.cpp
Modified By    :   Yasmeen Yousef
Description    :   implementation file of a array bag class
Dependencies   :   ArrayBag.hpp
****************************************************************************************************************************/

#include "ArrayBag.hpp"
/**  
    Default Constructor  
    item_count_ <- 0  
**/
template <class ItemType>
ArrayBag<ItemType>::ArrayBag() : item_count_(0)
{
}

/**  
    @return item_count_ : the current size of the bag  
**/
template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return item_count_;
}

/**
 * 
    @return true if item_count_ == 0, false otherwise  
**/
template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return item_count_ == 0;
}

/**  
    @return true if new_entry was successfully added to items_,  
            false otherwise  
**/
template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType &new_entry)
{
    if (item_count_ < DEFAULT_CAPACITY)
    {
        items_[item_count_++] = new_entry;
        return true;
    }
    return false;
}

/**  
    @return true if an_entry was successfully removed from items_,  
        false otherwise  
**/
template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &an_entry)
{
    int index = getIndexOf(an_entry);
    if (index == -1)
    {
        return false;
    }
    items_[index] = items_[--item_count_];
    return true;
}

/**  
    @post item_count_ == 0  
**/
template <class ItemType>
void ArrayBag<ItemType>::clear()
{
    item_count_ = 0;
}

/**  
    @return true if an_entry is found in items_, false otherwise  
            -> THIS METHOD MUST CALL getIndexOf() <-  
**/
template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &an_entry) const
{
    return getIndexOf(an_entry) != -1;
}

/**  
    @return the number of times an_entry appears in items_  
**/
template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &an_entry) const
{
    int counter = 0;
    for (int i = 0; i < item_count_; ++i)
    {
        if (items_[i] == an_entry)
            ++counter;
    }
    return counter;
}

/**  
    @param target to be found in items_  
    @return either the index target in the array items_ or -1,  
            if the array does not containthe target.  
**/
template <class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &target) const
{
    for (int i = 0; i < item_count_; ++i)
    {
        if (items_[i] == target)
            return i;
    }
    return -1;
}

/**  
    Implements Set Union. The union of two sets A and B is the set of  
    elements, which are in A, in B, or in both A and B.  
    @param a_bag to be combined with the contents of this (the calling) bag  
    @post adds as many items from a_bag as space allows lhs += rhs,  
    the left hand side (the calling side) of the operator will be modified.  
**/
template <class ItemType>
void ArrayBag<ItemType>::operator+=(const ArrayBag<ItemType> &a_bag)
{
    for (int i = 0; i < a_bag.item_count_; ++i)
    {
        if (!contains(a_bag.items_[i])) {
            if (add(a_bag.items_[i]) == false)
                break;
        }        
    }
}

/**  
    Implements Set Difference  
    The (set) difference between two sets A and B is the set that  
    consists of the elements in A which are not elements of B.  
    @param a_bag to be subtracted from this (the calling) bag  
    @post removes all the data from items_ that is also found in a_bag  
    lhs -= rhs, the left hand side (the calling side) of the operator  
    will be modified, remove elements from lhs that are also elements  
    of the rhs (a_bag).  
**/
template <class ItemType>
void ArrayBag<ItemType>::operator-=(const ArrayBag<ItemType> &a_bag)
{
    for (int i = 0; i < a_bag.item_count_; ++i)
    {
        remove(a_bag.items_[i]);
    }
}

/**  
    Implements Set Intersection  
    The intersection of two sets A and B is the set that  
    consists of the elements that are in both A and B.  
    @param a_bag to be intersected with this (the calling) bag  
    @post items_ no longer contains elements not found in a_bag  
    lhs /= rhs, the left hand side (the calling side) of  
    the operator will be modified, remove elements from  
    lhs that are NOT elements of the rhs (a_bag).  
**/
template <class ItemType>
void ArrayBag<ItemType>::operator/=(const ArrayBag<ItemType> &a_bag)
{
    for (int i = 0; i < item_count_; ++i)
    {
        if (!a_bag.contains(items_[i]))
            remove(items_[i--]);
    }
}

/**  
    Implements Equal Comparison  
    Two ArrayBags are equal to each other if they contain the same elements  
    the order of the elements do not matter.  
    @param a_bag to be compared with this (the calling) bag  
    @return true if the two bags contain the same elements, false otherwise  Note that in order for two bags to be equal the must be of equal sizes.  
**/
template <class ItemType>
bool ArrayBag<ItemType>::operator==(const ArrayBag<ItemType> &a_bag)
{
    for (int i = 0; i < item_count_; ++i)
    {
        if (!a_bag.contains(items_[i]) || getFrequencyOf(items_[i]) != a_bag.getFrequencyOf(items_[i]))
            return false;
    }
    return true;
}

/**  
    Implements Not Equal Comparison Opposite of the == operator, if two bags  
    have at least one element different they are not equal  
    @param a_bag to be compared with this (the calling) bag  
    @return true if two bags have a differing element, false if they are equal  
    In this case we can be sure that two arrays are not equal if they have  
    different sizes.  
**/
template <class ItemType>
bool ArrayBag<ItemType>::operator!=(const ArrayBag<ItemType> &a_bag)
{
    return !(*this == a_bag);
}
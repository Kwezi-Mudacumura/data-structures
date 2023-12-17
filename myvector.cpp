#include "myvector.h"
#include <iostream>
bool Thing::verbose = false;
size_t Thing::last_alloc = 0;

/**
 * @brief MyVector::MyVector Construct a vector with size 0
 *
 * Remember that the data pointer should point to nothing, and
 * counter variables should be initialised.
 */


MyVector::MyVector()//constructor.
{
      data = nullptr  ;//pointer to storage buffer
      n_items=0;//no of items stored
      n_allocated = 0;//amount of memory allocated

}

/**
 * @brief MyVector::~MyVector Free any memory that you have allocated do this last
 */
MyVector::~MyVector()//destructor
{
    // Do this last - if you have an error in your destructor it can crash your program
    delete[] data;

}


/**
 * @brief MyVector::size
 * @return The number of items in the vector
 */
size_t MyVector::size() const

{
   // n_items = 0;


    return (n_items);
}

/**
 * @brief MyVector::allocated_length
 * @return The length of the allocated data buffer
 */
size_t MyVector::allocated_length() const

{
    return (n_allocated);

}

/**
 * @brief MyVector::push_back
 * @param t The thing to add
 *
 * Add a thing to the back of the vector.
 * Remember to check if there is enough space to insert it first.
 * If there is not enough space, then you should reallocate the buffer
 * and copy each thing accross. When expanding the buffer, double the
 * allocated size.
 */
void MyVector::push_back(const Thing &t)
{
    if (n_allocated == 0){
        n_allocated+=1;
        reallocate(n_allocated);
    }else{
       if (n_allocated==n_items){
                reallocate(n_allocated*2);
            }
    }
    n_items += 1;
    data[n_items-1] = t;//the address of t is stored.
}

/**
 * @brief MyVector::pop_back
 * Remove the last item from the back.
 * Reallocate with half the space if less than a quarter of the vector is used.
 */
void MyVector::pop_back()
{
    if (n_allocated >0 || n_items > 0){
    n_items -= 1;
    if(n_items < 0.25*(n_allocated)){
       // n_allocated = 1/2*(n_allocated);
        reallocate(0.5*n_allocated);
        }
    else{
        reallocate(n_allocated);
    }
    }
    else{
        exit(0);
    }




}

/**
 * @brief MyVector::front
 * @return A reference to the first item in the array.
 * I will never call this on an empty list.
 */
Thing &MyVector::front()
{


    if (begin()==end()){
        exit (0);
    }else{
        Thing &s = data[0];

        return (s);
    }


}

/**
 * @brief MyVector::back
 * @return A reference to the last item in the array.
 *
 * Note that this might not be the back of the data buffer.
 * I will never call this on an empty list.
 */
Thing &MyVector::back()
{
    if (begin()==end()){
        exit(0);
    }else{
        Thing &s = data[n_items-1];
        return (s);
    }



}

/**
 * @brief MyVector::begin
 * @return A pointer to the first thing.
 */
Thing *MyVector::begin()
{
    Thing *re = &data[0];
    return (re);

}

/**
 * @brief MyVector::end
 * @return A pointer to the memory address following the last thing.
 */
Thing *MyVector::end()

{
    Thing *re = &data[n_items];
    return (re);

}

/**
 * @brief MyVector::operator []
 * @param i
 * @return A reference to the ith item in the list.
 */
Thing &MyVector::operator[](size_t i)
{

   Thing &re = data[i];
   return (re);

}

/**
 * @brief MyVector::at
 * @param i
 * @return A reference to the ith item in the list after checking
 * that the index is not out of bounds.
 */
Thing &MyVector::at(size_t i)
{
    if ((i < n_items) ){
        return (operator[](i));
    }
    else
    {
        throw std::out_of_range("Requested index out of bounds") ;
    }

}

/**
 * @brief MyVector::reallocate
 * @param new_size
 * Reallocate the memory buffer to be "new_size" length, using new Thing[new_size]
 * Copy all items from the old buffer into the new one.
 * Delete the old buffer using delete[]
 */
void MyVector::reallocate(size_t new_size)

{
    Thing *buffer = new Thing[new_size];

    for (size_t i = 0; i < n_items && i < new_size; i++){//checking something
        buffer[i] = data[i];
    }
    delete [] data;
    data = buffer;
    n_allocated = new_size;



}


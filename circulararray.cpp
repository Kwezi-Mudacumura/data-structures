#include "circulararray.h"
#include <cmath>

using std::cout;
using std::endl;

CircularArray::CircularArray()
{
    data = nullptr;
    n_allocated =0;
    n_items =0;
    idx_front =0;

}

/**
 * @brief CircularArray::print
 * Print the objects stored in the array separated by commas, starting at the "front" of the circular array. The content should be enclosed by square brackets.
 * The format should be: [1,2,3,4]
 * You can use cout as usual inside this function: "cout << myThing;"
 */
void CircularArray::print(std::ostream &cout) const
{
    cout<<'[';
    int i =idx_front;
    int count =1;
    while (data[i].value != -1){
        cout<<data[i].value;
        if (count<n_items){
            cout<<',';
        }
        i+=1;
        count+=1;
        i = i%n_allocated;


    }
    cout<<']';



}


/**
 * @brief CircularArray::size
 * @return The number of items actually stored in the array.
 */
int CircularArray::size() const
{
    return n_items;

}

/**
 * @brief CircularArray::allocated
 * @return The amount of space allocated - i.e. the number of Things that we could store in the current memory buffer.
 */
int CircularArray::allocated() const
{
    return n_allocated;

}

/**
 * @brief CircularArray::reallocate
 * @param new_size
 *
 * Allocate a new memory buffer that can store new_size number of Thing objects.
 * Remember that Thing at the "front" of the circular array should be copied to data[0] in the new memory.
 * Remember to free the old memory buffer and update all relevant variables in the class.
 */
void CircularArray::reallocate(int new_size)
{
    Thing*buffer = new Thing[new_size];
    if (n_allocated != 0){
        int k =0;
        int i = idx_front;
        while (data[i].value !=-1){
            buffer[k]=data[i];
            k+=1;
            k=k%new_size;
            i+=1;
            i=i%n_allocated;

        }


    }
    delete[]data;
    data=buffer;
    n_allocated= new_size;
    idx_front=0;


}

/**
 * @brief CircularArray::push_front
 * @param t
 *
 * Push Thing t to the front of the circular array.
 * If the array is full, then fist reallocate with twice the size.
 * If there is no memory allocated, then reallocate(1)
 */
void CircularArray::push_front(const Thing &t)
{
   if (n_allocated==0){
        reallocate(1);
    }
    else if (n_items == n_allocated){
        reallocate(n_allocated*2);
    }


  if (idx_front != 0){
    data[idx_front-1]=t;
    idx_front-=1;
  }
    else if ((n_items == 0) && (idx_front ==0)){
      data[n_allocated-1] = t;
      idx_front=n_allocated-1;
   }
    n_items+=1;//idk bruh


}

/**
 * @brief CircularArray::push_front
 * @param t
 *
 * Push Thing t to the back of the circular array.
 * If the array is full, then fist reallocate with twice the size.
 * If the array is empty (n_items == 0), then place the item at data[0].
 * If there is no memory allocated, then reallocate(1)
 */
void CircularArray::push_back(const Thing &t)
{
//    if (n_allocated==0){
//         reallocate(1);
//     }
//     else if (n_items == n_allocated){
//         reallocate(n_allocated*2);
//     }
//    if (n_items ==0){
//        data[0]=t;
//    }
//    data[(idx_front+n_items)%n_allocated] =t;
//    n_items +=1;



}

/**
 * @brief CircularArray::pop_front
 * Pop the object from the "front" of the circular array.
 * You don't need to delete the actual Thing object, but to mark it as deleted, you should set its value to -1
 *  i.e. data[something].value = -1
 * If the number of items in the array is < n_allocated/4.0 then reallocate with half the allocated space
 */
void CircularArray::pop_front()
{
    /*
    data[idx_front].value=-1;
    idx_front=(idx_front+1)%n_allocated;
    n_items -=1;
    if (n_items <n_allocated/4){
        reallocate(n_allocated/2);
    }
    */


}

/**
 * @brief CircularArray::pop_back
 * Pop the object from the "back" of the circular array.
 * You don't need to delete the actual Thing object, but to mark it as deleted, you should set its value to -1
 *  i.e. data[something].value = -1
 * If the number of items in the array is < n_allocated/4.0 then reallocate with half the allocated space
 */
void CircularArray::pop_back()
{
    /*
    int back = (idx_front+n_items)%n_allocated;
    data[back].value=-1;
    n_items-=1;
    if (n_items <n_allocated/4){
        reallocate(n_allocated/2);
    }
    */


}

/**
 * @brief CircularArray::operator []
 * @param index
 * @return the Thing object that is index units from the "front"
 */
Thing &CircularArray::operator[](int index)
{
    int re = (idx_front+index)%n_allocated;
    return data[re];

}

CircularArray::~CircularArray()
{
    delete []data;

}

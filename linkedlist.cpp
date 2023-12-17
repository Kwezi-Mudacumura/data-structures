#include "linkedlist.h"

/**
 * @brief LinkedListIterator::operator*
 * @return Return a reference to the thing in the link that we're pointing to
 */
Thing &LinkedListIterator::operator*()
{
   // Thing &ref = ptr -> value;
    return ptr ->value;
}

/**
 * @brief LinkedListIterator::operator++
 * Make the current iterator point to the next link in the list.
 * @return Return a reference to this object.
 */
LinkedListIterator &LinkedListIterator::operator++()
{
   //LinkedListIterator *next = new LinkedListIterator;
   ptr = ptr ->next;
   return *this;




}


/**
 * @brief LinkedList::LinkedList
 * Already correct as head is set to nullptr in the header file.
 */
LinkedList::LinkedList()
{
    // This is already correct.
}

/**
 * @brief LinkedList::~LinkedList
 * Free every link in the list. Do this function last.
 */
LinkedList::~LinkedList()
{
    // Consider using functions that already exist.
    size_t i = 0;
    size_t size1 = size();
    while (i < size1){
        pop_front();
        ++i;

    }
   // head = nullptr;


}

/**
 * @brief LinkedList::push_front
 * @param t
 * Push t to the front of the list
 */
void LinkedList::push_front(Thing t)
{

    Link *tmp = new Link(t);
    tmp->next = head;
    head = tmp;

}

/**
 * @brief LinkedList::pop_front
 * Remove the front item in the list
 */
void LinkedList::pop_front()

{
    Link *hold = head;
    head = head->next;
    delete hold;


}

/**
 * @brief LinkedList::push_back
 * @param t
 * Add t to the back of the list
 */
void LinkedList::push_back(Thing t)
{
    Link *move = head;
    Link *a = new Link(t);
    if (head != nullptr){
        while (move->next != nullptr){
            move=move->next;
        }
        move->next = a;


    }
    else
    {

        head = a;
    }


}

/**
 * @brief LinkedList::pop_back
 * Remove the last link in the list
 */
void LinkedList::pop_back()
{
    if (( head != nullptr)&&(head ->next != nullptr)){


        Link *curr = head;
        while (curr->next->next != nullptr){
            curr = curr->next;
        }
          delete curr->next ;
          curr->next = nullptr;
    }
    else if (head == nullptr){

        exit (0);


    }
    else if (head ->next == nullptr){
        //Link *temp = head;
        delete head;
        head = nullptr;

    }

}

/**
 * @brief LinkedList::size
 * @return number of items in the list
 */
size_t LinkedList::size()
{
   Link *curr = head;
   int count =0;
   while (curr != nullptr){
       curr = curr -> next;
       count ++;
   }
   return count;
}

/**
 * @brief LinkedList::front
 * @return a reference to the first item in the list
 */
Thing &LinkedList::front()
{
    if (head != nullptr){
        Thing &ref = head ->value;
        return ref;
    }
    else
    {
        exit (0);
    }

}

/**
 * @brief LinkedList::back
 * @return a reference to the last item in the list
 */
Thing &LinkedList::back()
{
    if (head != nullptr){
        Link *move = head;


            while (move->next != nullptr){
                move=move->next;
            }
            Thing &ref = move->value;
            return ref;




    }else
    {
        exit (0);
    }

}

/**
 * @brief LinkedList::get_link
 * @param i
 * @return A pointer to the ith link
 * @throws std::out_of_range("i out of bounds") - try do this without calling size()
 */
Link *LinkedList::get_link(int i)
{
    if (i >= 0){
        Link *move = head;
        int c =0;
        while (move != nullptr){
            if (c == i){
                return move;
            }
            move = move ->next;
            ++c;
        }
        throw std::out_of_range("i out of the bounds");

    }
    else
    {
        throw std::out_of_range("i out of bounds");
    }

}

/**
 * @brief LinkedList::at
 * @param i
 * @return A reference to the thing at index i
 * @throws std::out_of_range("i out of bounds") - try do this without calling size()
 */
Thing &LinkedList::at(int i)
{
    if (i >= 0){
       Link *move = head;
       int c =0;
       while (move != nullptr){
           if (c == i){
               return move -> value;
           }
           else
               move = move -> next;
               ++c;
       }
       throw std::out_of_range("i out of the bounds");
    }
    else
    {
        throw std::out_of_range("i out of the bounds");
    }



}

/**
 * @brief LinkedList::begin
 * @return a LinkedListIterator object referencing the first item
 */
LinkedListIterator LinkedList::begin()
{
    // Remember to implemente both LinkedListIterator::operator* and
    //   LinkedListIterator::operator++ in order to pass the test cases.
    // They are at the top of this file.


    LinkedListIterator first;
    first.ptr = head;
    return first;


}

/**
 * @brief LinkedList::end
 * @return a LinkedListIterator representing one past the last item
 * Let this be a LinkedLIstIterator with ptr equal to the nullptr
 */
LinkedListIterator LinkedList::end()
{
    LinkedListIterator last;
    last.ptr = nullptr;
    return last;

}

/**
 * @brief LinkedList::copy
 * @return A pointer to a copy of the list
 * Allocate a new list on the heap, then add all the items to the list.
 * Do not allocate the list on the stack, because it would be destroyed when the function ends.
 *  - See the C++ Concepts PDF example.
 */
LinkedList *LinkedList::copy()
{
    LinkedList *copy = new LinkedList();
    Link *curr = head;
    while (curr != nullptr){
        copy->push_back(curr->value);
        curr = curr ->next;


    }
    return copy;

}

/**
 * @brief LinkedList::reverse
 * Reverse the list.
 *  half marks: all the values are reversed
 *  remaining marks: list is reversed by changing link pointers *only*
 *    - if it was expensive to copy Thing objects, then reversing the values would take
 *       a lot of time. If you can do it by only changing the link pointers, then it will
 *       always be fast no matter how big the thing objects are.
 *  You can do this in O(n^2) time quite easily. Try think about how you could do this in O(n) time.
 */
void LinkedList::reverse()
{
   //LinkedList hold ;
   Link *m1 = head;
   Link *m2 = nullptr;
   Link *m3 = nullptr;
   //hold.head = head;

   while (m1 != nullptr){

       m2 = m1->next;
       m1 -> next = m3;
       m3 = m1;
       m1 = m2;



   }
   head = m3;













}


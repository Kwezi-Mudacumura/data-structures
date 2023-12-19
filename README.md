 <h1>Data structures coded in c++ :</h1></br>
<ul>
  <li><h2>Vector</h2>
  <p>Vectors in C++ are sequence containers representing arrays that can change their size during runtime. They use contiguous storage locations for their elements just as efficiently as in arrays, which means that their elements can also be accessed using offsets on regular pointers to its elements.When I coded this program, I used the implementation of a vector to create my own vector with the following functions:
  <ul>
  <li>  <h3>Constructor:</h3> A vector is constructed with size 0 and the data pointer points to nothing, and counter variables is initialised.
   </li>
   <li> <h3>Destructor:</h3>The destructor frees any memory that is allocated. </li>
   <li><h3>Size:</h3>This function returns the size of the vector.          </li>
   <li><h3>Allocated_length():</h3>This function returns the length of the allocated data buffer. </li>
   <li><h3>Push_back:</h3>This function is responsible for adding a "thing" to the back of the vector.It checks if there is enough space to insert it first.If there is not enough space, then the function calls the reallocate function to reallocate the buffer and copy each thing accross. When the function is expanding the buffer, the allocated size is doubled.</li>
   <li><h3>Pop_back:</h3>This function is responsible for removing the last item from the back. It also reallocates the vector with half the space if less than a quarter of the vector is used. </li>
   <li><h3>Front():</h3> This function returns a reference to the first item in the array.Note:This function cant be called on an empty list.                  </li>
   <li><h3>Back():</h3>This function returns a reference to the last item in the array. Note that this may not necessarily be the back of the data buffer.Note: This function cant be called on an empty list.</li>
   <li><h3>Begin():</h3> This function returns a pointer to the first thing in the vector.                   </li>
   <li><h3>End():</h3> The following function returns a pointer to the memory address following the last thing.                                                   </li>
   <li><h3>operator[]:</h3>This function returns a reference to the ith(parameter) item in the list.    </li>
   <li><h3>at:</h3>The following function returns a reference to the ith(parameter) item in the list after checking that the index is not out of bounds.               </li>
   <li><h3>reallocate:</h3> This function reallocates the memory buffer to be "new_size"(parameter) length, using new Thing[new_size]By:<ul><li>1. Copying all items from the old buffer into the new one.</li>
 <li>2. Deleting the old buffer using delete[] </li>    </ul>                            </li>
  
  </ul>
   
  </p>  
  </li>

  
  <li><h2>Linked list</h2><p>A linked list is a set of dynamically allocated nodes, arranged in such a way that each node contains one value and one pointer. The pointer always points to the next member of the list. If the pointer is nullptr, then it is the last node in the list.When I coded this program, I used the implementation of a linked list to create my own linked list with the following functions:
  <ul>
  <li><h3>operator*():</h3> This function returns a reference to the "thing" in the link that the linked list is pointing to.                                                                      </li>
  <li><h3>operator++():</h3>This function makes the current iterator point to the next link in the list.
 and returns a reference to this object.                                                 </li>
 <li><h3>Constructor:</h3> The head is set to nullptr in the header file thus it is left empty. </li>
 <li><h3>Destructor:</h3> This function frees every link in the list. </li>
 <li><h3>Push_front:</h3> This function pushes t(parameter) to the front of the list.  </li>
 <li><h3>Pop_front:</h3> This function removes the front item in the list. </li>
 <li><h3>Push_back:</h3>This function adds t(parameter) to the back of the list. </li>
 <li><h3>Pop_back:</h3>This function removes the last link in the list.  </li>
 <li><h3>Size():</h3>This function returns the number of items in the list.                                               </li>
 <li><h3>front():</h3>This function returns a reference to the first item in the list.  </li>
 <li><h3>back():</h3>This function returns a reference to the last item in the list.       </li>
 <li><h3>get_link:</h3>This function returns a pointer to the ith(parameter) link and it will throw std::out_of_range("i out of bounds") if i is out of bounds.                       </li>
 <li><h3>at():</h3>This function returns a reference to the thing at index i(parameter) and it will throw std::out_of_range("i out of bounds") if i is out of bounds</li>
 <li><h3>begin():</h3>This function returns a LinkedListIterator object referencing the first item.</li>
 <li><h3>end():</h3>This function returns a LinkedListIterator representing one past the last item.                                         </li>
 <li><h3>copy:</h3>This function returns a pointer to a copy of the list by:<ul>
   <li>1.Allocating a new list on the heap</li> 
   <li>2.Adding all the items to the list.</li>
   </ul>
 Please note:The copy of list is not allocated on the stack because it would be destroyed when the function ends.</li>
 <li><h3>reverse:</h3>This function reverses the list by changing link pointers *only*(pointer arithemetic).</br>
 Please note:it is expensive to copy Thing objects, then reversing the values would take a lot of time. Thus by only changing the link pointers, then it will always be fast no matter how big the thing objects are.This function takes O(n) time.</li>
    
  </ul>
  </p>
  </li>

  
  <li><h2>Circular array</h2>
    <p>
  A circular array is a data structure that is used to represent a collection of data in a circular manner,where the end of the array is connected to the beginning.This allows for efficient access and manipulation of the data elements.In a circular array,when the end of the array is reached,the next element is considered to be the first element of the array.When I coded this program, I used the implementation of a circular array to create my own circular array with the following functions:
  <ul>
  <li><h3>Constructor:</h3> This function sets the values to its default values used throughout the rest of the program.       </li>
  <li><h3>print:</h3> This function prints the objects stored in the array separated by commas, starting at the "front" of the circular array. The content is enclosed by square brackets.</br>
 -The format is : [1,2,3,4]   </li>
 <li><h3>size:</h3> This function returns the number of items actually stored in the array.</li>
 <li><h3>allocated:</h3>This function returns the amount of space allocated - i.e. the number of Things that we actually stored in the current memory buffer.</li>
 <li><h3>reallocate:</h3>This function allocates a new memory buffer that can store new_size number of Thing objects.</br>
 Please note:<ul><li>the Thing at the "front" of the circular array is copied to data[0] in the new memory.</li>
   <li>The old memory buffer is freed and all relevant variables is updated in the class.</li>
   </ul>
 </li>
 <li><h3>push_front</h3> This function pushes Thing t(parameter) to the front of the circular array. If the array is full, then the function first reallocates the memory buffer with twice the size.If there is no memory allocated, the function then reallocate(1) </li>
   
 <li><h3>push_back:</h3>This function pushes Thing t(parameter) to the back of the circular array.If the array is full, the funcction first reallocates the memory buffer with twice the size.If the array is empty (n_items == 0), then the function places the item(parameter) at data[0].If there is no memory allocated, then the function reallocate(1) . </li>
 <li><h3>pop_front:</h3>This function pops the object from the "front" of the circular array.The actual Thing(parameter) isnt deleted rather it is marked as deleted by setting its value to -1 eg) data[something].value = -1.If the number of items in the array is < n_allocated/4.0 then this function reallocates with half the allocated space.</li>
 <li><h3>pop_back:</h3>This function pops the object from the "back" of the circular array.The actual Thing(parameter) isnt deleted rather it is marked as deleted by setting its value to -1 eg) data[something].value = -1.If the number of items in the array is < n_allocated/4.0 then this function reallocates with half the allocated space.
 </li>
 <li><h3>operator[]:</h3>This function returns the Thing(parameter) object that is index units from the "front". </li>
 <li><h3>destructor:</h3>This function deletes data[].              </li>
   
  </ul>  
   </p>
  </li>

  
  <li><h2>Binary Search Tree</h2></li>
  <p>
  Binary Search Tree is a node-based binary tree data structure which has the following properties:<ul>

<li>The left subtree of a node contains only nodes with keys lesser than the node’s key.</li>
<li>The right subtree of a node contains only nodes with keys greater than the node’s key.</li>
<li>The left and right subtree each must also be a binary search tree.</li>
</ul>

  </p>
</ul>
<p>Basically these programs are the background to how the data structures are created. <br>I didnt use said data structure to implement the data structure but other data structures and algorithms.
</br>The code also takes into account the time complexity for the best compilation time. </br> Please note that the code is in c++ 11.</p>

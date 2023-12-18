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
  <li>-Linked list</li>
  <li>-Circular array</li>
  <li>-Binary Search Tree</li>
</ul>
<p>Basically these programs are the background to how the data structures are created. <br>I didnt use said data structure to implement the data structure but other data structures and algorithms.
</br>The code also takes into account the time complexity for the best compilation time. </br> Please note that the code is in c++ 11.</p>

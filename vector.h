/***********************************************************************
 * Header:
 *    VECTOR
 * Summary:
 *    Our custom implementation of std::vector
 *
 *      __       ____       ____         __
 *     /  |    .'    '.   .'    '.   _  / /
 *     `| |   |  .--.  | |  .--.  | (_)/ /
 *      | |   | |    | | | |    | |   / / _
 *     _| |_  |  `--'  | |  `--'  |  / / (_)
 *    |_____|  '.____.'   '.____.'  /_/
 *
 *
 *    This will contain the class definition of:
 *        vector                 : A class that represents a Vector
 *        vector::iterator       : An interator through Vector
 * Author
 *    Michael Johnson, James Gassaway, Brayden Jones
 ************************************************************************/

#pragma once

#include <cassert>  // because I am paranoid
#include <new>     // std::bad_alloc
#include <memory>   // for std::allocator
#include <initializer_list>
#include <utility>

class TestVector; // forward declaration for unit tests
class TestStack;
class TestPQueue;
class TestHash;

namespace custom
{

   /*****************************************
    * VECTOR
    * Just like the std :: vector <T> class
    ****************************************/
   template <typename T>
   class vector
   {
      friend class ::TestVector; // give unit tests access to the privates
      friend class ::TestStack;
      friend class ::TestPQueue;
      friend class ::TestHash;
   public:

      // 
      // Construct
      //

      vector();
      vector(size_t numElements);
      vector(size_t numElements, const T& t);
      vector(const std::initializer_list<T>& l);
      vector(const vector& rhs);
      vector(vector&& rhs);
      ~vector();

      //
      // Assign
      //

      void swap(vector& rhs)
      {

         // ---------- Michael Johnson Code to be completed ----------
         std::swap(data, rhs.data);
         std::swap(numCapacity, rhs.numCapacity);
         std::swap(numElements, rhs.numElements);
      }
      vector& operator = (const vector& rhs);
      vector& operator = (vector&& rhs);

      //
      // Iterator
      //

      class iterator;
      iterator      begin()
      {
         // ---------- Michael Johnson Code to be completed ----------
         return iterator(data);
      }
      iterator      end()
      {
         // ---------- Michael Johnson Code to be completed ----------
         return iterator(data ? data + numElements : nullptr);
      }

      //
      // Access
      //

      T& operator [] (size_t index);
      const T& operator [] (size_t index) const;
      T& front();
      const T& front() const;
      T& back();
      const T& back() const;

      //
      // Insert
      //

      void push_back(const T& t);
      void push_back(T&& t);
      void reserve(size_t newCapacity);
      void resize(size_t newElements);
      void resize(size_t newElements, const T& t);

      //
      // Remove
      //

      void clear()
      {
         // ---------- Michael Johnson Code to be completed ----------
         numElements = 0;
      }
      void pop_back()
      {
         // ---------- Michael Johnson Code to be completed ----------
         if (numElements)
            --numElements;
      }
      void shrink_to_fit();

      //
      // Status
      //

      size_t  size()        const
      {
         // ---------- Michael Johnson Code to be completed ----------
         return numElements;
      }
      size_t  capacity()     const
      {
         // ---------- Michael Johnson Code to be completed ----------
         return numCapacity;
      }
      bool empty()         const
      {
         // ---------- Michael Johnson Code to be completed ----------
         return numElements == 0;
      }

      // adjust the size of the buffer

      // vector-specific interfaces

   private:

      T* data;             // user data, a dynamically-allocated array
      size_t  numCapacity;      // the capacity of the array
      size_t  numElements;      // the number of items currently used
   };

   /**************************************************
    * VECTOR ITERATOR
    * An iterator through vector.  You only need to
    * support the following:
    *   1. Constructors (default and copy)
    *   2. Not equals operator
    *   3. Increment (prefix and postfix)
    *   4. Dereference
    * This particular iterator is a bi-directional meaning
    * that ++ and -- both work.  Not all iterators are that way.
    *************************************************/
   template <typename T>
   class vector <T> ::iterator
   {
      friend class ::TestVector; // give unit tests access to the privates
      friend class ::TestStack;
      friend class ::TestPQueue;
      friend class ::TestHash;
   public:
      // constructors, destructors, and assignment operator
      iterator()
      {
         // ---------- Michael Johnson Code to be completed ----------
         this->p = nullptr;
      }
      iterator(T* p)
      {
         // ---------- Michael Johnson Code to be completed ----------
         this->p = p;
      }
      iterator(const iterator& rhs)
      {
         // ---------- Michael Johnson Code to be completed ----------
         this->p = rhs.p;
      }
      iterator(size_t index, vector<T>& v)
      {
         // ---------- Michael Johnson Code to be completed ----------
         this->p = (v.data ? v.data + index : nullptr);
      }
      iterator& operator = (const iterator& rhs)
      {

         // ---------- Michael Johnson Code to be completed ----------
         this->p = rhs.p;
         return *this;
      }

      // equals, not equals operator
      bool operator != (const iterator& rhs) const
      {
         // ---------- Michael Johnson Code to be completed ----------
         return this->p != rhs.p;
      }
      bool operator == (const iterator& rhs) const
      {
         // ---------- Michael Johnson Code to be completed ----------
         return this->p == rhs.p;
      }

      // dereference operator
      T& operator * ()
      {
         // ---------- Michael Johnson Code to be completed ----------
         return *p;
      }

      // prefix increment
      iterator& operator ++ ()
      {
         // ---------- Michael Johnson Code to be completed ----------
         ++p;
         return *this;
      }

      // postfix increment
      iterator operator ++ (int postfix)
      {
         // ---------- Michael Johnson Code to be completed ----------
         iterator temp(*this);
         ++p;
         return temp;
      }

      // prefix decrement
      iterator& operator -- ()
      {
         // ---------- Michael Johnson Code to be completed ----------
         --p;
         return *this;
      }

      // postfix decrement
      iterator operator -- (int postfix)
      {
         // ---------- Michael Johnson Code to be completed ----------
         iterator temp(*this);
         --p;
         return temp;
      }

   private:
      T* p;
   };

   /*****************************************
    * VECTOR :: DEFAULT constructors
    * Default constructor: set the number of elements,
    * construct each element, and copy the values over
    ****************************************/
   template <typename T>
   vector <T> ::vector()
   {

      // ---------- Michael Johnson Code to be completed ----------
      data = nullptr;
      numCapacity = 0;
      numElements = 0;
   }

   /*****************************************
    * VECTOR :: NON-DEFAULT constructors
    * non-default constructor: set the number of elements,
    * construct each element, and copy the values over
    ****************************************/
   template <typename T>
   vector <T> ::vector(size_t num, const T& t)
   {

      // ---------- James Gassaway completed ----------
      // Set data as null for now
      data = nullptr;

      // Set capacity and elements to the correct values 
      numCapacity = num;
      numElements = num;

      // If no data to build, we're done
      if (num == 0)
         return;

      // Create the new data
      data = new T[num];
      // Create each element, set as t
      for (size_t i = 0; i < num; i++) {
         data[i] = t;
      }
   }

   /*****************************************
    * VECTOR :: INITIALIZATION LIST constructors
    * Create a vector with an initialization list.
    ****************************************/
   template <typename T>
   vector <T> ::vector(const std::initializer_list<T>& l)
   {

      // ---------- Brayden Jones Code to be completed ----------
      data = nullptr;
      numCapacity = 0;
      numElements = 0;

      if (l.size() == 0)
         return;

      numCapacity = l.size();
      numElements = l.size();
      data = new T[numCapacity];

      size_t i = 0;
      for (auto it = l.begin(); it != l.end(); ++it)
         data[i++] = *it;
   }

   /*****************************************
    * VECTOR :: NON-DEFAULT constructors
    * non-default constructor: set the number of elements,
    * construct each element, and copy the values over
    ****************************************/
   template <typename T>
   vector <T> ::vector(size_t num)
   {

      // ---------- James Gassaway completed ----------
      // Set data as a null ptr for now
      data = nullptr;

      // Set capacity and elements to the correct values 
      numCapacity = num;
      numElements = num;

      // if no data to build, we're done
      if (num == 0)
         return;

      // Create the new data
      data = new T[num];
      // Create each element, set as 0
      for (size_t i = 0; i < num; i++) {
         data[i] = 0;
      }
   }

   /*****************************************
    * VECTOR :: COPY CONSTRUCTOR
    * Allocate the space for numElements and
    * call the copy constructor on each element
    ****************************************/
   template <typename T>
   vector <T> ::vector(const vector& rhs)
   {

      // ---------- Brayden Jones Code to be completed ----------
      data = nullptr;
      numCapacity = 0;
      numElements = 0;

      if (rhs.numElements == 0)
         return;

      numElements = rhs.numElements;
      numCapacity = rhs.numElements;
      data = new T[numCapacity];

      for (size_t i = 0; i < numElements; i++)
         data[i] = rhs.data[i];
   }

   /*****************************************
    * VECTOR :: MOVE CONSTRUCTOR
    * Steal the values from the RHS and set it to zero.
    ****************************************/
   template <typename T>
   vector <T> ::vector(vector&& rhs)
   {

      // ---------- Michael Johnson Code to be completed ----------
      data = rhs.data;
      numCapacity = rhs.numCapacity;
      numElements = rhs.numElements;

      rhs.data = nullptr;
      rhs.numCapacity = 0;
      rhs.numElements = 0;
   }

   /*****************************************
    * VECTOR :: DESTRUCTOR
    * Call the destructor for each element from 0..numElements
    * and then free the memory
    ****************************************/
   template <typename T>
   vector <T> :: ~vector()
   {
      // ---------- Michael Johnson Code to be completed ----------
      delete[] data;
      data = nullptr;
      numCapacity = 0;
      numElements = 0;
   }

   /***************************************
    * VECTOR :: RESIZE
    * This method will adjust the size to newElements.
    * This will either grow or shrink newElements.
    *    INPUT  : newCapacity the size of the new buffer
    *    OUTPUT :
    **************************************/
   template <typename T>
   void vector <T> ::resize(size_t newElements)
   {

      // ---------- Brayden Jones Code to be completed ----------
      // shrink: logically remove elements
      if (newElements <= numElements)
      {
         numElements = newElements;
         return;
      }

      // grow: ensure capacity
      if (newElements > numCapacity)
         reserve(newElements);

      // value-initialize the new slots
      for (size_t i = numElements; i < newElements; ++i)
         data[i] = T();

      numElements = newElements;

   }

   template <typename T>
   void vector <T> ::resize(size_t newElements, const T& t)
   {

      // ---------- Brayden Jones Code to be completed ----------
      // shrink: logically remove elements
      if (newElements <= numElements)
      {
         numElements = newElements;
         return;
      }

      // grow: ensure capacity
      if (newElements > numCapacity)
         reserve(newElements);

      // fill new slots with provided value
      for (size_t i = numElements; i < newElements; ++i)
         data[i] = t;

      numElements = newElements;
   }

   /***************************************
    * VECTOR :: RESERVE
    * This method will grow the current buffer
    * to newCapacity.  It will also copy all
    * the data from the old buffer into the new
    *    INPUT  : newCapacity the size of the new buffer
    *    OUTPUT :
    **************************************/
   template <typename T>
   void vector <T> ::reserve(size_t newCapacity)
   {
      // ---------- James Gassaway completed ----------
      // No need to reserve if there is enough capacity already
      if (numCapacity >= newCapacity)
         return;

      // Reserve a new capacity and make a pointer for it
      T* newData = new T[newCapacity];

      // Move the old data into the new location
      for (auto i = 0; i < numElements; i++) {
         new ((void*)(newData + i)) T(std::move(data[i]));
      }

      // Delete the old data, and store the location of the new container
      delete[] data;
      data = newData;

      // Adjust the capacity
      numCapacity = newCapacity;
   }

   /***************************************
    * VECTOR :: SHRINK TO FIT
    * Get rid of any extra capacity
    *    INPUT  :
    *    OUTPUT :
    **************************************/
   template <typename T>
   void vector <T> ::shrink_to_fit()
   {
      // ---------- James Gassaway completed ----------

      // No need to shrink if elements and capacity are the same
      if (numElements == numCapacity)
         return;
      // Make a new data set
      T* newData = nullptr;
      // Move the data into the data set if there's data to be moved
      if (numElements > 0) {
         // Allocate a new data contianer
         newData = new T[numElements];
         // Move each item into the data
         for (auto i = 0; i < numElements; i++) {
            new ((void*)(newData + i)) T(std::move(data[i]));
         }
      }

      // Delete the old data, and point the data to the newData spot
      delete[] data;
      data = newData;
      // Adjust the capacity
      numCapacity = numElements;

   }



   /*****************************************
    * VECTOR :: SUBSCRIPT
    * Read-Write access
    ****************************************/
   template <typename T>
   T& vector <T> :: operator [] (size_t index)
   {
      // ---------- Michael Johnson Code to be completed ----------
      return data[index];

   }

   /******************************************
    * VECTOR :: SUBSCRIPT
    * Read-Write access
    *****************************************/
   template <typename T>
   const T& vector <T> :: operator [] (size_t index) const
   {
      // ---------- Michael Johnson Code to be completed ----------
      return data[index];
   }

   /*****************************************
    * VECTOR :: FRONT
    * Read-Write access
    ****************************************/
   template <typename T>
   T& vector <T> ::front()
   {

      // ---------- Michael Johnson Code to be completed ----------
      return data[0];
   }

   /******************************************
    * VECTOR :: FRONT
    * Read-Write access
    *****************************************/
   template <typename T>
   const T& vector <T> ::front() const
   {
      // ---------- Michael Johnson Code to be completed ----------
      return data[0];
   }

   /*****************************************
    * VECTOR :: FRONT
    * Read-Write access
    ****************************************/
   template <typename T>
   T& vector <T> ::back()
   {
      // ---------- Michael Johnson Code to be completed ----------
      return data[numElements - 1];
   }

   /******************************************
    * VECTOR :: FRONT
    * Read-Write access
    *****************************************/
   template <typename T>
   const T& vector <T> ::back() const
   {
      // ---------- Michael Johnson Code to be completed ----------
      return data[numElements - 1];
   }

   /***************************************
    * VECTOR :: PUSH BACK
    * This method will add the element 't' to the
    * end of the current buffer.  It will also grow
    * the buffer as needed to accomodate the new element
    *    INPUT  : 't' the new element to be added
    *    OUTPUT : *this
    **************************************/
   template <typename T>
   void vector <T> ::push_back(const T& t)
   {

      // ---------- James Gassaway completed ----------
      if (numCapacity == 0)
         reserve(1);

      if (numElements >= numCapacity)
         reserve(numCapacity * 2);

      new ((void*)(&data[numElements++])) T(std::move(t));
   }

   template <typename T>
   void vector <T> ::push_back(T&& t)
   {
      // ---------- James Gassaway completed ----------


      if (numCapacity == 0)
         reserve(1);

      if (numElements >= numCapacity)
         reserve(numCapacity * 2);

      new ((void*)(&data[numElements++])) T(std::move(t));
   }

   /***************************************
    * VECTOR :: ASSIGNMENT
    * This operator will copy the contents of the
    * rhs onto *this, growing the buffer as needed
    *    INPUT  : rhs the vector to copy from
    *    OUTPUT : *this
    **************************************/
   template <typename T>
   vector <T>& vector <T> :: operator = (const vector& rhs)
   {

      // ---------- Brayden Jones Code to be completed ----------
      // Copy assignment
      if (this == &rhs)
         return *this;

      // If rhs is empty, become empty
      if (rhs.numElements == 0)
      {
         delete[] data;
         data = nullptr;
         numElements = 0;
         numCapacity = 0;
         return *this;
      }

      // Need a bigger buffer: allocate new, then copy, then delete old
      if (numCapacity < rhs.numElements)
      {
         T* newData = new T[rhs.numElements]; // new buffer with rhs's size

         for (size_t i = 0; i < rhs.numElements; ++i)
            newData[i] = rhs.data[i];

         delete[] data;
         data = newData;
         numCapacity = rhs.numElements;
         numElements = rhs.numElements;
         return *this;
      }

      // Enough capacity: just copy into existing storage
      for (size_t i = 0; i < rhs.numElements; ++i)
         data[i] = rhs.data[i];

      numElements = rhs.numElements;
      // numCapacity stays the same
      return *this;
   }
   template <typename T>
   vector <T>& vector <T> :: operator = (vector&& rhs)
   {

      // ---------- Brayden Jones Code to be completed ----------
      // Move assignment
      if (this == &rhs)
         return *this;

      delete[] data;

      // Steal from rhs
      data = rhs.data;
      numCapacity = rhs.numCapacity;
      numElements = rhs.numElements;

      // And make rhs empty
      rhs.data = nullptr;
      rhs.numCapacity = 0;
      rhs.numElements = 0;

      return *this;
   }




} // namespace custom
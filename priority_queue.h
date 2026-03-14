/***********************************************************************
 * Header:
 *    PRIORITY QUEUE
 * Summary:
 *    Our custom implementation of std::priority_queue
 *      __       ____       ____         __
 *     /  |    .'    '.   .'    '.   _  / /
 *     `| |   |  .--.  | |  .--.  | (_)/ /
 *      | |   | |    | | | |    | |   / / _
 *     _| |_  |  `--'  | |  `--'  |  / / (_)
 *    |_____|  '.____.'   '.____.'  /_/
 *
 *
 *    This will contain the class definition of:
 *        priority_queue          : A class that represents a Priority Queue
 * Author
 *    Michael, James, Brayden
 ************************************************************************/

#pragma once

#include <cassert>
#include <stdexcept>
#include <utility>
#include "vector.h"

class TestPQueue;   // forward declaration for unit test class

namespace custom
{

   /*************************************************
    * P QUEUE
    * Create a priority queue.
    *************************************************/
   template<class T>
   class priority_queue
   {
      friend class ::TestPQueue; // give the unit test class access to the privates
      template <class TT>
      friend void swap(priority_queue<TT>& lhs, priority_queue<TT>& rhs);
   public:

      //
      // construct
      //
      // ---------- Michael Code to Complete ----------
      priority_queue()
      {
      }

      // ---------- Michael Code to Complete ----------
      priority_queue(const priority_queue& rhs) :
         container(rhs.container)
      {
      }

      // ---------- Michael Code to Complete ----------
      priority_queue(priority_queue&& rhs) :
         container(std::move(rhs.container))
      {
      }

      // ---------- Michael Code to Complete ----------
      template <class Iterator>
      priority_queue(Iterator first, Iterator last)
      {
         size_t num = 0;
         for (Iterator it = first; it != last; ++it)
            ++num;

         container.reserve(num);

         for (Iterator it = first; it != last; ++it)
            container.push_back(*it);

         heapify();
      }

      // ---------- Michael Code to Complete ----------
      explicit priority_queue(custom::vector<T>&& rhs) :
         container(std::move(rhs))
      {
         heapify();
      }

      // ---------- Michael Code to Complete ----------
      explicit priority_queue(custom::vector<T>& rhs) :
         container(rhs)
      {
         heapify();
      }

      ~priority_queue() {}

      //
      // Access
      //

      // ---------- James Code to Complete ----------
      const T& top() const;

      //
      // Insert
      //

      // ---------- James Code to Complete ----------
      void push(const T& t);

      // ---------- James Code to Complete ----------
      void push(T&& t);

      //
      // Remove
      //
      // ---------- Brayden Code to Complete ----------
      void pop();

      //
      // Status
      //
      // ---------- James Code to Complete ----------
      size_t size() const
      {
          return container.size();
      }

      // ---------- James Code to Complete ----------
      bool empty() const
      {
          return size() == size_t(0);
      }

   private:

       // ---------- Brayden Code to Complete ----------
      void heapify();                     // convert the container in to a heap

      // ---------- Michael Code to Complete ----------
      bool percolateDown(size_t indexHeap);     // fix heap from index down. This is a heap index!

      custom::vector<T> container;

   };

   /************************************************
    * P QUEUE :: TOP
    * Get the maximum item from the heap: the top item.
    ***********************************************/
   template <class T>

   // ---------- James Code to Complete ----------
   const T& priority_queue<T>::top() const
   {
      // Check if empty
      if (empty()) {
         throw std::out_of_range("std:out_of_range");
      }

      // Return the top element
       return container[0];
   }

   /**********************************************
    * P QUEUE :: POP
    * Delete the top item from the heap.
    **********************************************/
   template <class T>

   // ---------- Brayden Code to Complete ----------
   void priority_queue<T>::pop()
   {
   }

   /*****************************************
    * P QUEUE :: PUSH
    * Add a new element to the heap, reallocating as necessary
    ****************************************/
   template <class T>

   // ---------- James Code to Complete ----------
   void priority_queue<T>::push(const T& t)
   {
      // Put the new element in
      container.push_back(t);
      // Get the index we need to percolate from
      size_t index = container.size() / 2;
      // Keep percolating while the index is valid and the necessity is there
      while (index && percolateDown(index))
         index = index / 2;
   }

   // ---------- James Code to Complete ----------
   template <class T>
   void priority_queue<T>::push(T&& t)
   {
      // Put the new element in
      container.push_back(t);
      // Get the index we need to percolate from
      size_t index = container.size() / 2;
      // Keep percolating while the index is valid and the necessity is there
      while (index && percolateDown(index))
         index = index / 2;
   }

   /************************************************
    * P QUEUE :: PERCOLATE DOWN
    * The item at the passed index may be out of heap
    * order. Take care of that little detail!
    * Return TRUE if anything changed.
    ************************************************/
   template <class T>

   // ---------- Michael Code to Complete ----------
   bool priority_queue<T>::percolateDown(size_t indexHeap)
   {
      bool changed = false;
      size_t num = container.size();

      while (indexHeap * 2 <= num)
      {
         size_t left = indexHeap * 2;
         size_t right = left + 1;
         size_t largest = left;

         if (right <= num && container[largest - 1] < container[right - 1])
            largest = right;

         if (container[indexHeap - 1] < container[largest - 1])
         {
            std::swap(container[indexHeap - 1], container[largest - 1]);
            indexHeap = largest;
            changed = true;
         }
         else
            break;
      }

      return changed;
   }

   /************************************************
    * P QUEUE :: HEAPIFY
    * Turn the container into a heap.
    ************************************************/
   template <class T>

   // ---------- Brayden Code to Complete ----------
   void priority_queue<T>::heapify()
   {
   }

   /************************************************
    * SWAP
    * Swap the contents of two priority queues
    ************************************************/
   template <class T>

   // ---------- Brayden Code to Complete ----------
   inline void swap(custom::priority_queue <T>& lhs,
       custom::priority_queue <T>& rhs)
   {
   }

};
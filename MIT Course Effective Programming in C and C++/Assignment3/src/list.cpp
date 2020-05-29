#include "list.h"
#include "list_node.h"
#include "apply.h"
#include "reduce.h"

#include <iostream>

List::List() : _length{0}, _begin{ nullptr }, _back{ nullptr } {}

List::List( const List &list ) : _length{0}, _begin{nullptr}, _back{nullptr} {
  for( auto it = list.begin(); it != list.end(); ++it ) {
    append( *it );
  }
}

List& List::operator=( const List &list ) {
  if( this != &list ) {
    clear();
    for( auto it = list.begin(); it != list.end(); ++it ) {
      append( *it );
    }
  }
  return *this;
}

List::~List() { clear(); }

size_t List::length() const { return _length; }

int& List::value( size_t pos ) {
  auto it = begin();
  for( size_t i = 0; i < pos && it != end(); ++it, ++i );
  if( it == end() ) {
    throw ListOutOfBounds();
  }

  return *it;
}

int List::value( size_t pos ) const {
  auto it = begin();
  for( size_t i = 0; i < pos && it != end(); ++it, ++i );
  if( it == end() ) {
    throw ListOutOfBounds();
  }

  return *it;
}

bool List::empty() const {
  return _length == 0;
}

List::iterator List::begin() { return iterator{ _begin }; }
List::const_iterator List::begin() const { return const_iterator{ _begin }; }
List::iterator List::back() { return iterator{ _back }; }
List::const_iterator List::back() const { return const_iterator{ _back }; }
List::iterator List::end() { return iterator{ nullptr }; }
List::const_iterator List::end() const { return const_iterator{ nullptr }; }

void List::append( int theValue ) {
    ListNode *node = ListNode::create( theValue);

    if (empty()){
        _begin = node;
    }
    else{
        newNode->insertAfter( _back );
        _back = node;
    }

    ++_length;
}

void List::deleteAll( int theValue ) {
    if (!empty()){
            auto curr = _begin;

            while (curr != NULL){

            }

        }

}

List::iterator List::find( iterator s, iterator t, int needle ) {
  for( auto it = s; it != t; ++it ) {
    if( *it == needle ) {
      return it;
    }
  }
  return t;
}

void List::insert( iterator pos, int theValue ) {

}

void List::insertBefore( int theValue, int before ) {

}

void List::apply( const ApplyFunction &interface ) {
  interface.apply( *this );
}

int List::reduce( const ReduceFunction &interface ) const {
  return interface.reduce( *this );
}

void List::print() const {

}

void List::clear() {

}

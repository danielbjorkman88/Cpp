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
    ListNode *newNode = ListNode::create( theValue);

    if (empty()){
        _begin = newNode;
        _back = newNode;
    }
    else{
        newNode->insertAfter( _back );
        _back = newNode;
    }

    ++_length;
}

void List::deleteAll( int theValue ) {
    ListNode *curr = _begin;
    if (!empty()){
        while (_begin->value() == theValue && _begin != _back){
            ListNode *first = _begin;
            if (first->value() == theValue){
                _begin = _begin->next();
                delete first;
                --_length;
            }
        }




        while (curr->next() != NULL && curr != _back){
            if (curr->next()->value() == theValue){
                ListNode::deleteNext( curr );
                --_length;
            }
            curr = curr->next();
        }


    if (_back->value() == theValue){
        curr = _begin;

        while (curr->next() != _back){
            curr = curr->next();
        }
        _back = curr;
        delete curr->next();
        --_length;

    }
    }else{
      _begin = _back = nullptr;
      _length = 0;
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
    ListNode *newNode = ListNode::create( theValue);
    auto *posPtr = node( pos );
    if (empty()){
        _begin = newNode;
    }
    else{
        newNode->insertAfter( posPtr );
    }

    ++_length;

}

void List::insertBefore( int theValue, int before ) {
    if( !empty() ) {
        if( _begin->value() == before ) {
          auto *newNode = ListNode::create( theValue );
          newNode->setNext( _begin );
          _begin = newNode;
          ++_length;
        } else {
          auto *p = _begin;
          for( ; p != _back && p->next()->value() != before; p = p->next() );
          if( p != _back && p->next()->value() == before ) {
            auto *newNode = ListNode::create( theValue );
            newNode->insertAfter( p );
            ++_length;
          }
        }
  }


}

void List::apply( const ApplyFunction &interface ) {
  interface.apply( *this );
}

int List::reduce( const ReduceFunction &interface ) const {
  return interface.reduce( *this );
}

void List::print() const {
    std::cout << "{ ";
    if (!empty()){
        ListNode *curr = _begin;
        while (curr != nullptr){
            std::cout << curr->value() << " -> ";
            curr = curr->next();
        }
        std::cout << " }" << std::endl;
    }
    else{
        std::cout << "Empty list" << std::endl;
    }

}

void List::clear() {
    ListNode *curr = _begin;
    ListNode *prev;
    while(curr != nullptr){
        prev = curr;
        curr = curr->next();
        delete prev;
    }

  _length = 0;
  _begin = nullptr;
  _back = nullptr;
}

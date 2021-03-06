/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */


#ifndef __VERTEX_H_INCLUDED__
#define __VERTEX_H_INCLUDED__

#include <type_traits>
#include <initializer_list>
#include <array>
#include <exception>
#include <algorithm>

/**
 * @class vertex
 * @brief vertext is a base vertex class,
 * contains N components of type T
 */
template <typename T, size_t N>
class vertex {
  public:
    /// default ctor
    vertex<T, N>();
    /// ctor with N values in il
    vertex<T, N>(const std::initializer_list<T>&);
    /// copy ctor
    vertex<T, N>(const vertex<T, N>&);
    /// set value val by index vnum
    void setAt(size_t , const T&);
    /// get value by index vnum
    T& getAt(size_t);
    /// operator =
    vertex<T, N>& operator=(const vertex<T, N>&);
    /// operator ==
    bool operator==(const vertex<T, N>&);
  protected:
    std::array<T, N> coords;
};

template <typename T, size_t N>
vertex<T, N>::vertex() {
    static_assert( N > 1, "too few coordinates! should be 2 or more");
    static_assert(std::is_arithmetic
                  <typename std::remove_cv
                  < typename std::remove_reference
                  <T>::type>::type>::value,
                  "values must have an arithmetic type!");
    coords.fill(0);
}

template <typename T, size_t N>
vertex<T, N>::vertex(const std::initializer_list<T>& il)
    : vertex<T, N>() {
    if(il.size() != N)
        throw std::invalid_argument("vertex::ctor(): incorrect number of vertex coordinates");
    size_t ctr = 0u;
    for(auto& i : il)
        coords[ctr++] = i;
}

template <typename T, size_t N>
void vertex<T, N>::setAt(size_t vnum, const T& val) {
    if(vnum >= N)
        throw std::out_of_range("vertex::setv(): invalid index");
    coords[vnum] = val;
}

template <typename T, size_t N>
T& vertex<T, N>::getAt(size_t vnum) {
    if(vnum >= N)
        throw std::out_of_range("vertex::getv(): invalid index");
    return coords[vnum];
}

template <typename T, size_t N>
vertex<T, N>& vertex<T, N>::operator=(const vertex<T, N>& rhs)
{
  if(this == &rhs)
    return *this;
  std::copy(rhs.coords.cbegin(), rhs.coords.cend(), coords.begin());
  return *this;
}

template <typename T, size_t N>
bool vertex<T, N>::operator==(const vertex<T, N>& rhs)
{
  if(this == &rhs)
    return true;
  return (coords == rhs.coords);
}

template <typename T, size_t N>
vertex<T, N>::vertex(const vertex<T, N>& other)
{
  if( this == &other)
    return;
  std::copy(other.coords.cbegin(), other.coords.cend(), coords.begin());
}

#endif // __VERTEX_H_INCLUDED__

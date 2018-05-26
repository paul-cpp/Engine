/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018
 * Mikhail Domchenkov agplastictown@yandex.ru
 * Paul Sachkov paul.pix71@gmail.com
 */

#ifndef __VERTEX2FC_H_INCLUDED__
#define __VERTEX2FC_H_INCLUDED__

#include <vertex2f.h>
#include <color.h>

using rgba =   color < float, 4>;

class vertex2fc: public vertex2f
{
public:
  vertex2fc();
  vertex2fc(const vertex2fc& rhs);
  vertex2fc(float x, float y, rgba c);
  rgba getColor() const;
  void setColor(const rgba& c);
  vertex2fc& operator=(const vertex2fc& rhs);
  vertex2fc& operator=(const vertex2f& rhs);
  vertex2fc& operator=(const rgba& rhs); //TODO
  bool operator == (const vertex2fc& rhs) const;

private:
  rgba color;
};

vertex2fc::vertex2fc(): vertex2f () {}

vertex2fc::vertex2fc(const vertex2fc& rhs)
  : vertex2f (rhs), color(rhs.getColor()) {}

vertex2fc::vertex2fc(float x, float y, rgba c): vertex2f {x, y}, color(c) {}

rgba vertex2fc::getColor() const
{
  return color;
}

void vertex2fc::setColor(const rgba& c)
{
  color = c;
}

vertex2fc& vertex2fc::operator=(const vertex2fc& rhs)
{
  if(this == &rhs)
    return *this;
  vertex2f::operator=(rhs);
  color = rhs.color;
  return *this;
}

vertex2fc& vertex2fc::operator=(const vertex2f& rhs)
{
  vertex2f::operator=(rhs);
  return *this;
}

vertex2fc& vertex2fc::operator=(const rgba& rhs)
{
  color = rhs;
  return *this;
}

bool vertex2fc::operator ==(const vertex2fc& rhs) const
{
  return (vertex2f::operator==(rhs) && (color == rhs.color));
}

//todo


#endif  //__VERTEX2FC_H_INCLUDED__

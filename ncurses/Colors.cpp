/*
** Colors.cpp for mndk in /home/loic/dev/epitech/cpp/Nibbler/ncurses/mndk
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mer. mars 19 13:25:09 2014 lefloc_l
** Last update dim. avril 06 20:16:03 2014 lefloc_l
*/

#include <iostream>
#include <algorithm>

#include <ncurses.h>

#include "./Colors.hh"
#include "./Error.hh"

using namespace ncurses;

ColorManager *ColorManager::_instance = NULL;

ColorManager::ColorManager() : _colors(COLOR_PAIRS)
{
  std::fill(_colors.begin(), _colors.end(), 0);
}

ColorManager::ColorManager(const ColorManager &other)
{
  (void)other;
}

ColorManager::~ColorManager()
{
}

ColorManager*	ColorManager::getInstance()
{
  if (!_instance)
    _instance = new ColorManager();
  return _instance;
}

short	ColorManager::get()
{
  std::vector<short>::iterator it = std::find(_colors.begin() + 1, _colors.end(), 0);
  if (it != _colors.end())
  {
    ++(*it);
    return std::distance(_colors.begin(), it);
  }
  else
    throw ncurses::Exception("No colors defined");
}

void	ColorManager::get(short num) /**< increase number of this color users */
{
  if (num >= 0)
    ++(_colors.at(num)); //register new owner
}

void	ColorManager::put(short num) /**< put number to the pool, decrease number of this color users */
{
  if (num >= 0)
    _colors.at(num)--;
}


Color::Color():
  _nb_pair(-1),
  _attr(WA_NORMAL)
{

}

Color::Color(short f, short b, attr_t attr):
  _nb_pair(ColorManager::getInstance()->get()),
  _attr(attr)
{
  ASSERT(init_pair(_nb_pair, b, f));
}

Color::Color(const Color& other):
  _nb_pair(other._nb_pair),
  _attr(other._attr)
{
  ColorManager::getInstance()->get(_nb_pair); //get ownership over new number
}

Color::~Color()
{
  ColorManager::getInstance()->put(_nb_pair);
}

void	Color::swap(Color& other)
{
  std::swap(_nb_pair, other._nb_pair);
  std::swap(_attr, other._attr);
}

Color&		Color::operator=(const Color& other)
{
  Color(other).swap(*this);
  return *this;
}

short	Color::num() const
{
  return _nb_pair;
}

attr_t	Color::attr() const
{
  return _attr;
}

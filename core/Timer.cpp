/*
** Timer.cpp for core in /home/loic/dev/epitech/cpp/Nibbler/core
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mer. mars 19 09:31:38 2014 lefloc_l
// Last update Mon Apr 28 17:00:01 2014 thibau_j
*/

#include <time.h>

#include "./Timer.hh"

Timer::Timer(void)
{
  reinit();
}

Timer::Timer(const Timer &other)
{
  this->_beginTime = other.getBeginTime();
}

Timer::~Timer(void)
{
}

Timer&		Timer::operator=(const Timer &other)
{
  this->_beginTime = other.getBeginTime();
  return *this;
}

unsigned long           Timer::getBeginTime(void) const
{
  return _beginTime;
}

bool		Timer::isTimeout(float seconds) const
{
  return (seconds) >= elapsedTime();
}

unsigned long	Timer::elapsedTime(void) const
{
  return ((float) clock() - _beginTime) / (CLOCKS_PER_SEC / 10);
}

void		Timer::reinit(void)
{
  _beginTime = clock();
}

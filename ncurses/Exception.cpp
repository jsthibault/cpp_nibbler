/*
** Exception.cpp for mndk in /home/loic/dev/epitech/cpp/Nibbler/ncurses/mndk
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mar. mars 25 12:05:54 2014 lefloc_l
** Last update mar. mars 25 12:08:40 2014 lefloc_l
*/

#include "./Exception.hh"

ncurses::Exception::Exception(const std::string &msg)
{
  this->_message = msg;
}

ncurses::Exception::~Exception() { }

std::string	ncurses::Exception::what() const
{
  return this->_message;
}

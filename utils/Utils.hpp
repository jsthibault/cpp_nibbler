/*
** Utils.h for core in /home/loic/dev/epitech/cpp/Nibbler/core
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mar. avril 01 21:36:19 2014 lefloc_l
** Last update dim. avril 06 01:53:54 2014 lefloc_l
*/

#ifndef UTILS_H_
# define UTILS_H_

#include <sstream>
#include <string>

#define SIZE_TAB(x)	(sizeof(x) / sizeof(x[0]) )

template<typename T>
T		convert(const std::string &str)
{
  std::stringstream	ss;
  T			value;

  ss << str;
  ss >> value;

  return value;
}

template<typename T>
std::string		convert(T value)
{
  std::ostringstream	ss;

  ss << value;

  return ss.str();
}

#endif /* !UTILS_H_ */

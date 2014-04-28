/*
** Debug.cpp for core in /home/loic/dev/epitech/cpp/Nibbler/core
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mar. avril 01 17:45:01 2014 lefloc_l
// Last update Sat Apr  5 14:41:39 2014 samy ouachek
*/

#include <iostream>
#include "Debug.hh"
#include "Utils.hpp"

void	Msg::Debug(LogLevel log_level, const std::string &message)
{
  if (log_level == LOG_LEVEL_CRITICAL)
    std::cerr << "\033[1;31mCritical error: \033[0m" << message << std::endl;
  else if (log_level == LOG_LEVEL_WARNING)
    std::cerr << "\033[4;33mWarning:\033[0m " << message << std::endl;
  else if (log_level ==  LOG_LEVEL_MESSAGE)
    std::cout << "\033[4;34mMessage:\033[0m " << message << std::endl;
  else if (log_level ==  LOG_LEVEL_INFO)
    std::cout << "\033[4;32mInfo:\033[0m " << message << std::endl;
  else if (log_level ==  LOG_LEVEL_DEBUG)
    std::cout << "\033[0;32m" << message << "\033[0m" << std::endl;
  else
    std::cerr << "Debug: Unknow log_level." << std::endl;
}

void	Msg::Debug(const std::string &str)
{
  Debug(LOG_LEVEL_DEBUG, str);
}

void	Msg::Debug(int nb)
{
  std::string str;

  str = convert<int>(nb);
  Debug(LOG_LEVEL_DEBUG, str);
}

void	Msg::Critical(const std::string &str)
{
  Debug(LOG_LEVEL_CRITICAL, str);
}

void	Msg::Warning(const std::string &str)
{
  Debug(LOG_LEVEL_WARNING, str);
}

void	Msg::Message(const std::string &str)
{
  Debug(LOG_LEVEL_MESSAGE, str);
}

void	Msg::Info(const std::string &str)
{
  Debug(LOG_LEVEL_INFO, str);
}

void	Msg::Error(const std::string &str)
{
  throw MException(str);
}

/*
** Error.cpp for mndk in /home/loic/dev/epitech/cpp/Nibbler/ncurses/mndk
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mer. mars 19 12:16:04 2014 lefloc_l
** Last update dim. avril 06 20:15:08 2014 lefloc_l
*/

#include <iostream>
#include "Error.hh"

void	ncurses::AssertFailure(const std::string& expr, const std::string& file, int line)
{
  std::ostringstream ost;
  ost << expr << std::endl;
  ost << "Failed : " << file << ":" << line;
  throw ncurses::Exception(ost.str());
}

void	nDebug(nLogLevel log_level, const std::string &message)
{
  if (log_level == N_LOG_LEVEL_CRITICAL)
    std::cerr << "\033[1;31mCritical error:\033[0m " << message << std::endl;
  else if (log_level == N_LOG_LEVEL_WARNING)
    std::cerr << "\033[4;33mWarning:\033[0m " << message << std::endl;
  else if (log_level ==  N_LOG_LEVEL_MESSAGE)
    std::cout << "\033[4;34mMessage:\033[0m " << message << std::endl;
  else if (log_level ==  N_LOG_LEVEL_INFO)
    std::cout << "\033[4;32mInfo:\033[0m " << message << std::endl;
  else if (log_level ==  N_LOG_LEVEL_DEBUG)
    std::cout << "\033[0;32m" << message << "\033[0m" << std::endl;
  else
    std::cerr << "nDebug: Unknow log_level." << std::endl;
}

void	nDebug(const std::string &str)
{
  nDebug(N_LOG_LEVEL_DEBUG, str);
}

void	nCritical(const std::string &str)
{
  nDebug(N_LOG_LEVEL_CRITICAL, str);
}

void	nWarning(const std::string &str)
{
  nDebug(N_LOG_LEVEL_WARNING, str);
}

void	nMessage(const std::string &str)
{
  nDebug(N_LOG_LEVEL_MESSAGE, str);
}

void	nInfo(const std::string &str)
{
  nDebug(N_LOG_LEVEL_INFO, str);
}

void	nError(const std::string &str)
{
  throw ncurses::Exception(str);
}


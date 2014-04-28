/*
** Error.h for mndk in /home/loic/dev/epitech/cpp/Nibbler/ncurses/mndk
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mer. mars 19 10:39:59 2014 lefloc_l
** Last update dim. avril 06 20:15:16 2014 lefloc_l
*/

#ifndef ERROR_H_
# define ERROR_H_

#include <sstream>
#include <string>

#include "Exception.hh"

#define ASSERT(x) \
  if ((x) != OK) ncurses::AssertFailure(#x, __FILE__, __LINE__)

namespace ncurses
{
  void	AssertFailure(const std::string& expr, const std::string& file, int line);
}

enum nLogLevel {
  N_LOG_LEVEL_CRITICAL,
  N_LOG_LEVEL_WARNING,
  N_LOG_LEVEL_MESSAGE,
  N_LOG_LEVEL_INFO,
  N_LOG_LEVEL_DEBUG
};

void	nDebug(nLogLevel level, const std::string& message);

void	nDebug(const std::string &);
void	nCritical(const std::string &);
void	nWarning(const std::string &);
void	nMessage(const std::string &);
void	nInfo(const std::string &);
void	nError(const std::string &str);

#endif /* !ERROR_H_ */

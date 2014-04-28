/*
** Debug.h for core in /home/loic/dev/epitech/cpp/Nibbler/core
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mar. avril 01 17:45:05 2014 lefloc_l
** Last update dim. avril 06 01:53:43 2014 lefloc_l
*/

#ifndef DEBUG_H_
# define DEBUG_H_

#include <string>
#include <exception>

enum LogLevel {
  LOG_LEVEL_CRITICAL,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_MESSAGE,
  LOG_LEVEL_INFO,
  LOG_LEVEL_DEBUG
};

namespace Msg
{
  void	Debug(LogLevel level, const std::string &message);
  void	Debug(const std::string &);
  void	Debug(int);
  void	Critical(const std::string &);
  void	Warning(const std::string &);
  void	Message(const std::string &);
  void	Info(const std::string &);
  void	Error(const std::string &str);
}

class	MException
{
 private:
  std::string	_msg;

 public:
  MException(const std::string &msg)
    {
      this->_msg = msg;
    }

  std::string	what() const
    {
      return this->_msg;
    }
};

#endif /* !DEBUG_H_ */

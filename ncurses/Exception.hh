/*
** Exception.hh for mndk in /home/loic/dev/epitech/cpp/Nibbler/ncurses/mndk
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mar. mars 25 12:04:14 2014 lefloc_l
** Last update mar. mars 25 12:08:38 2014 lefloc_l
*/

#ifndef EXCEPTION_H_
# define EXCEPTION_H_

#include <string>

namespace ncurses
{
  class Exception
  {
  private:
    std::string		_message;

  public:
    Exception(const std::string &);
    virtual ~Exception();

    std::string		what() const;
  };

}
#endif /* !EXCEPTION_H_ */

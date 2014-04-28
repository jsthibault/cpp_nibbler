/*
** extern.c for ncurses in /Users/loic/dev/epitech/cpp/Nibbler/ncurses
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  Ven avr 04 18:33:06 2014 lefloc_l
// Last update Sun Apr  6 00:17:08 2014 thibau_j
*/

#include "NcursesWindow.hh"

extern "C"
{

  IWindow *	_new(void)
  {
    IWindow	*tmp = new CursesWindow();

    return tmp;
  }

  void	_delete(IWindow *instance)
  {
    delete instance;
  }

}

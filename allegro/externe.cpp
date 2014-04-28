//
// externe.cpp for externe.cpp in /home/thibauj/rendu/Nibbler/ncurses
//
// Made by thibau_j
// Login   <thibau_j@epitech.net>
//
// Started on  Sun Apr  6 00:15:03 2014 thibau_j
// Last update Sun Apr  6 02:21:28 2014 thibau_j
//

#include "snakeAllegro.hh"

extern "C"
{
  IWindow	*_new()
  {
    IWindow	*tmp = new snakeAllegro();

    (void)tab;
    return (tmp);
  }

  void		_delete(IWindow *instance)
  {
    delete (instance);
  }
}

/*
** App.h for mndk in /home/loic/dev/epitech/cpp/Nibbler/ncurses/mndk
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mer. mars 19 10:17:27 2014 lefloc_l
** Last update mar. mars 25 10:42:17 2014 lefloc_l
*/

#ifndef APP_H_
# define APP_H_

#include <curses.h>

namespace ncurses
{
  class	App
  {
  private:
    App(const App &other);
    App &		operator=(const App &other);
    SCREEN *		_screen;

  public:
    App(); // setup env.
    ~App(); // reset terminal settings

    int			width() const; // width of the screen
    int			height() const; // height of the screen

    void		cursorOn() const;
    void		cursorOff() const;
  };
}
#endif /* !APP_H_ */

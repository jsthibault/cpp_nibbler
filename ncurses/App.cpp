/*
** App.cpp for mndk in /home/loic/dev/epitech/cpp/Nibbler/ncurses/mndk
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mer. mars 19 10:17:27 2014 lefloc_l
** Last update sam. avril 05 17:35:09 2014 lefloc_l
*/

#include <stdlib.h>

#include "./App.hh"
#include "./Error.hh"
#include "./Colors.hh"

ncurses::App::App()
{
  const char	*name;

  // = initscr();
  if (!(name = getenv("TERM")) || *name == '\0')
    name = "unknown";
  if (!(_screen = newterm(const_cast<char *>(name), stdout, stdin)))
    throw ncurses::Exception("Newterm failed.");
  ASSERT(def_prog_mode());
  start_color();

  /*
   * use terminal colors -> useful for transparant background (BLACK color)
   */
  use_default_colors();

  /*
   * disable the buffering
   */
  ASSERT(cbreak());
  ASSERT(noecho());
//  ASSERT(nonl());
  ASSERT(nodelay(stdscr, true));
  ASSERT(notimeout(stdscr, true));
  cursorOff();

  // TODO: mouse events.
  mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, static_cast<mmask_t*>(0));

  /*
   * capture special keys like arrows, Delete...
   */
  ASSERT(keypad(stdscr, TRUE));
}

ncurses::App::~App()
{
  clrtoeol();
  refresh();
  endwin();
  delscreen(_screen);
}

int			ncurses::App::height() const
{
  return LINES;
}

int			ncurses::App::width() const
{
  return COLS;
}

void			ncurses::App::cursorOff() const
{
  curs_set(0);
}

void			ncurses::App::cursorOn() const
{
  curs_set(1);
}

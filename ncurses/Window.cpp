/*
** Window.cpp for mndk in /home/loic/dev/epitech/cpp/Nibbler/ncurses/mndk
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mer. mars 19 11:02:30 2014 lefloc_l
** Last update dim. avril 06 20:18:02 2014 lefloc_l
*/

#include <string>
#include <iostream>

#include <curses.h>

#include "./Error.hh"
#include "./Window.hh"
#include "./Defines.hh"

ncurses::Window::Window()
{
  /*
   * newwin : nlines, ncols, y, x 0 -> fullscreen
   */
  if (!(_win = newwin(0, 0, 0, 0)))
    throw ncurses::Exception("new win failed");

  // enable advanced keycodes
  keypad(_win, TRUE);
}

ncurses::Window::Window(const Window &other)
{
  this->_win = other.getWin();
  this->_header = other.getHeader();
  this->_footer = other.getFooter();
}

ncurses::Window &       ncurses::Window::operator=(const Window &other)
{
  if (&other == this)
    return *this;
  this->_win = other.getWin();
  this->_header = other.getHeader();
  this->_footer = other.getFooter();
  return *this;
}

ncurses::Window::~Window()
{
  delwin(_win);
}

int          ncurses::Window::height() const
{
  int	w, h;

  getmaxyx(_win, h, w);
  return h;
}

int          ncurses::Window::width() const
{
  int	w, h;

  getmaxyx(_win, h, w);
  (void)h;
  return w;
}

void    ncurses::Window::resize(const size_t w, const size_t h)
{
  ASSERT(wresize(_win, h, w));
}

void	ncurses::Window::touchLine(const int start, const int count)
{
  touchline(_win, start, count);
}

void	ncurses::Window::moveCursor(const int y, const int x)
{
  wmove(_win, y, x);
}

int	ncurses::Window::bindKey() const
{
  int	c;

  c = getch();
  return c;
}

void	ncurses::Window::write(const char c)
{
  waddch(_win, c);
}

void	ncurses::Window::write(const std::string & str)
{
  wprintw(_win, "%s", str.data());
}

void	ncurses::Window::write(const int attribut, const std::string & str)
{
  ASSERT(wattron(_win, attribut));
  ASSERT(addstr(str.c_str()));
}

void	ncurses::Window::createBorder(const char ls, const char rs,
    const char ts, const char bs, const char tl, const char tr, const char bl,
    const char bn)
{
  ASSERT(wborder(_win, ls, rs, ts, bs, tl, tr, bl, bn));
}

void	ncurses::Window::createBorder(const char v, const char h, const char c)
{
  createBorder(v, v, h, h, c, c, c, c);
}

void	ncurses::Window::createBorder()
{
  createBorder(DEFAULT_LS, DEFAULT_RS, DEFAULT_TS, DEFAULT_BS,
        DEFAULT_TL, DEFAULT_TR, DEFAULT_BL, DEFAULT_BN);
}

void	ncurses::Window::drawHLine(const char c, int y, int x, int size)
{
  int	save_y = getcury(_win);
  int	save_x = getcurx(_win);

  moveCursor(y, x);
  whline(_win, c, size);
  moveCursor(save_y, save_x);
}

void	ncurses::Window::drawVLine(const char c, int y, int x, int size)
{
  int	save_y = getcury(_win);
  int	save_x = getcurx(_win);

  moveCursor(y, x);
  wvline(_win, c, size);
  moveCursor(save_y, save_x);
}

void	ncurses::Window::frame(size_t x, size_t y, size_t h, size_t w,
    const char ls, const char rs, const char ts, const char bs, const char tl,
    const char tr, const char bl, const char bn)
{
  mvwaddch(_win, y, x, ls);
  mvwaddch(_win, y, x + w, rs);
  mvwaddch(_win, y + h, x, ts);
  mvwaddch(_win, y + h, x + w, bs);
  mvwhline(_win, y, x + 1, tl, w - 1);
  mvwhline(_win, y + h, x + 1, tr, w - 1);
  mvwvline(_win, y + 1, x, bl, h - 1);
  mvwvline(_win, y + 1, x + w, bn, h - 1);
}

void	ncurses::Window::frame(size_t x, size_t y, size_t h, size_t w)
{
  frame(x, y, h, w, DEFAULT_LS, DEFAULT_RS, DEFAULT_TS, DEFAULT_BS,
        DEFAULT_TL, DEFAULT_TR, DEFAULT_BL, DEFAULT_BN);
}

void	ncurses::Window::refresh()
{
  wnoutrefresh(_win);
  wrefresh(stdscr);
  doupdate();
  wgetch(stdscr);
}

void	ncurses::Window::clear()
{
  werase(_win);
  wrefresh(stdscr);
  wstandend(_win); // turn off all attributes of the window
}

void	ncurses::Window::useColor(int nb_pair)
{
  ASSERT(wbkgd(_win, COLOR_PAIR(nb_pair)));
}

void	ncurses::Window::setHeader(const std::string str)
{
  _header = str;
  printHeader();
}

void	ncurses::Window::setFooter(const std::string& str)
{
  _footer = str;
}

void	ncurses::Window::printHeader()
{
  int	i = 0;
  int	mid = (height() / 2) - (_header.length() / 2);

  while (i < mid)
  {
    mvwprintw(_win, 1, i, "#");
    ++i;
  }
  mvwprintw(_win, 1, i + 1, "%s", _header.data());
  i += _header.length() + 2;
  while (i < height())
  {
    mvwprintw(_win, 1, i, "#");
    ++i;
  }
}

void	ncurses::Window::setColor(const ncurses::Color &c)
{
  ASSERT(wattr_set(_win, c.attr(), c.num(), 0));
}

void	ncurses::Window::setBackground(const ncurses::Color &)
{
  ASSERT(wbkgd(_win, COLOR_PAIR(1)));
}

std::string	ncurses::Window::getFooter() const
{
  return this->_footer;
}

std::string	ncurses::Window::getHeader() const
{
  return this->_header;
}

WINDOW*		ncurses::Window::getWin() const
{
  return this->_win;
}


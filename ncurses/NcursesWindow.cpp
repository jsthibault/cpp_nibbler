#include <iostream>
#include <exception>

#include "Keys.hh"
#include "Error.hh"
#include "Colors.hh"

#include "NcursesWindow.hh"
#include "../utils/Utils.hpp"

CursesWindow::CursesWindow()
{
  _app = new ncurses::App();
  _win = new ncurses::Window();
}

CursesWindow::~CursesWindow()
{
  destroy();
}

Event::code	CursesWindow::getEvent()
{
    int		c;

    c = _win->bindKey();
    switch (c)
    {
      case KEY_LEFT:
          return Event::LEFT;
        break;
      case KEY_RIGHT:
          return Event::RIGHT;
        break;
      case ncurses::K_1:
          return Event::LIB1;
        break;
      case ncurses::K_2:
          return Event::LIB2;
        break;
      case ncurses::K_3:
          return Event::LIB2;
        break;
      case ncurses::K_Q:
          return Event::QUIT;
      case ncurses::K_P:
          return Event::PAUSE;
    }
    return Event::NONE;
}

void		CursesWindow::calcBeginPos(int *x, int *y)
{
  *x = (_win->width() - _width) / 2;
  *y = (_win->height() - _height) / 2;

  if (*x < 0 || *y < 0)
    nError("Too small terminal.");
  _win->frame(*x - 1, *y - 1, _height + 2, _width + 2);
}

void            CursesWindow::refresh(map_t const &map)
{
  int		begin_x, begin_y;
  t_mapiter	iter;

  try
  {
    ncurses::Color	def(COLOR_BLACK, COLOR_WHITE);
    ncurses::Color	red(COLOR_TRANSPARANT, COLOR_RED);
    ncurses::Color	blue(COLOR_TRANSPARANT, COLOR_BLUE);

    _win->clear();
    _win->createBorder('|', '=', '#');
    _win->setColor(blue);
    calcBeginPos(&begin_x, &begin_y);

    /*
    ** write snake
    */
    for (iter = map.snake.begin(); iter != map.snake.end(); iter++)
    {
        _win->moveCursor((*iter).y + begin_y, (*iter).x + begin_x);
        _win->setColor(red);
        if (iter == map.snake.begin())
          _win->write("0");
        else
          _win->write(this->getSprite((*iter).type));
    }

    /*
    ** write map
    */
    for (iter = map.others.begin(); iter != map.others.end(); iter++)
    {
        _win->moveCursor((*iter).y + begin_y, (*iter).x + begin_x);
        _win->setColor(red);
        _win->write(this->getSprite((*iter).type));
    }

    this->drawMenu(map.score);
    _win->refresh();
  }
  catch (ncurses::Exception &e)
  {
    nCritical("error :" + e.what());
  }
}

char		CursesWindow::getSprite(Case::case_name type)
{
  size_t	i = 0;

  static const CursesWindow::t_sprites	tab_sprites[] = {
    { '*', Case::FOOD },
    { 'o', Case::SNAKE }
  };

  while (i < SIZE_TAB(tab_sprites))
  {
    if (tab_sprites[i].type == type)
      return (tab_sprites[i].sprite);
    ++i;
  }
  return '_';
}

void		CursesWindow::destroy()
{
  delete _win;
  delete _app;
}

void		CursesWindow::init(int width, int height)
{
  this->_width = width;
  this->_height = height;
}

void		CursesWindow::drawMenu(int score)
{
  ncurses::Color	red(COLOR_RED, COLOR_WHITE);
  ncurses::Color	blue(COLOR_TRANSPARANT, COLOR_BLUE);
  ncurses::Color	h1(COLOR_TRANSPARANT, COLOR_GREEN);

  _win->setColor(blue);
  _win->frame(5, 5, 5, 15);
  _win->moveCursor(6, 10);
  _win->setColor(h1);
  _win->write("score");

  _win->moveCursor(7, 12);
  _win->setColor(red);
  std::string score_str = convert<int>(score);
  _win->write(score_str);
}

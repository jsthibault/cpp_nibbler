//
// SnakeAllegro.cpp for cpp in /home/thibauj/rendu/Nibbler/allegrow-JS
//
// Made by thibau_j
// Login   <thibau_j@epitech.net>
//
// Started on  Fri Apr  4 10:58:55 2014 thibau_j
// Last update Mon Apr  7 02:29:54 2014 thibau_j
//

#include <vector>
#include <allegro.h>
#include <iostream>
#include "snakeAllegro.hh"
#include "../core/IWindow.hh"
#include "../utils/Debug.hh"

snakeAllegro::snakeAllegro()
{
  this->_colorMap = -1;
  this->_colorSnake = -1;
  this->_colorHead = -1;
}

snakeAllegro::~snakeAllegro()
{

}

int		snakeAllegro::giveRandom(int const &nb_mod)
{
  int		nb;

  nb = rand();
  nb %= nb_mod;
  return (nb);
}

void		snakeAllegro::init(int height, int width)
{
  int		nb;
  int		color;
  int           _time = time(NULL);

  if (_time == (time_t)-1)
    Msg::Error("Time failed.\n");
  srand(time(NULL));
  this->_height = height;
  this->_width = width;
  if (allegro_init())
    Msg::Error("Allegro init failed.\n");
  if (install_keyboard())
    Msg::Error("Keybord install failed.\n");
  if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, this->_height * 50, this->_width * 50 , 0, 0))
    Msg::Error("Gtfx mode failed.\n");
  nb = this->giveRandom(20);
  if ((color = makecol(tab[nb].r, tab[nb].g, tab[nb].b)) < 0)
    Msg::Error("Color maker failed.\n");
  tab[nb].r = -1;
  this->_colorMap = color;
  while (tab[nb].r == -1)
    nb = this->giveRandom(20);
  if ((color = makecol(tab[nb].r, tab[nb].g, tab[nb].b)) < 0)
    Msg::Error("Color maker failed.\n");
  tab[nb].r = -1;
  this->_colorSnake = color;
  while (tab[nb].r == -1)
    nb = this->giveRandom(20);
  if ((color = makecol(tab[nb].r, tab[nb].g, tab[nb].b)) < 0)
    Msg::Error("Color maker failed.\n");
  tab[nb].r = -1;
  this->_colorHead = color;
  while (tab[nb].r == -1)
      nb = this->giveRandom(20);
  if ((color = makecol(tab[nb].r, tab[nb].g, tab[nb].b)) < 0)
      Msg::Error("Color maker failed.\n");
  this->_colorFood = color;
}

void		snakeAllegro::displayMap(map_t const &map)
{
  t_mapiter	iter;

  rectfill(screen, 0, 0, this->_height * 50, this->_width * 50, this->_colorMap);
  for (iter = map.snake.begin(); iter != map.snake.end(); iter++)
    {
      if (iter == map.snake.begin())
	circlefill(screen, ((*iter).x * 50) + 25 , ((*iter).y * 50) + 25, 25, this->_colorHead);
      else
	circlefill(screen, ((*iter).x * 50) + 25, ((*iter).y * 50) + 25, 25, this->_colorSnake);
    }
  for (iter = map.others.begin(); iter != map.others.end(); iter++)
    {
      if ((*iter).type == Case::FOOD)
	circlefill(screen, ((*iter).x * 50) + 25, ((*iter).y * 50) + 25, 10, this->_colorSnake);
    }
}

void		snakeAllegro::refresh(map_t const &map)
{
  int		color;

  this->displayMap(map);
  if (!(color = makecol(227,38,54)))
    Msg::Error("Color maker failed.\n");
  // textprintf_ex(screen, font, 10, 10, color, -1, "Score : %d\n", map.score);
}

Event::code	snakeAllegro::getEvent()
{
  if (key[KEY_LEFT])
    {
      return Event::LEFT;
    }
  else if (key[KEY_RIGHT])
    {
      return Event::RIGHT;
    }
  else if (key[KEY_ESC])
    {
      return Event::QUIT;
    }
  else if (key[KEY_1])
    {
      return (Event::LIB1);
    }
  else if (key[KEY_2])
    {
      return (Event::LIB2);
    }
  else if (key[KEY_3])
    {
      return (Event::LIB3);
    }
  else if (key[KEY_P])
    {
      return (Event::PAUSE);
    }
  return Event::NONE;
}

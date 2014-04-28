#include <dlfcn.h>
#include <iostream>
#include <sstream>

#include "Core.hh"
#include "Timer.hh"
#include "../utils/Debug.hh"
#include "../utils/Utils.hpp"

Core::Core(std::string const &libname, size_t width, size_t height) :
  _libname(libname),
  _width(width),
  _height(height)
{
  if (width < 5 || height < 5 || width > 160 || height > 60)
    Msg::Error("Errors with size. (not under 5 and not over 100)");
  _win = NULL;
  _map.score = 0;
  getLibrary(_libname);
}

Core::~Core(void)
{
  this->closeLibrary();
  Msg::Message("Goodbye !");
}

Core		&Core::operator=(__attribute__((__unused__))const Core &other)
{
  return *this;
}

void		Core::closeLibrary(void)
{
  this->_loader->free(_win);
  delete this->_loader;
}

void		Core::getLibrary(std::string const &name)
{
  this->_loader = new dlloader<IWindow>(name);

  if (NULL == (_win = this->_loader->create()))
    Msg::Error("Error when create library.");
  Msg::Debug(name + " loaded successfully");
  _win->init(_width, _height);
}

void		Core::run(void)
{
  bool		run = true;
  Timer		t;

  while (run)
  {
      if (checkEvent() == false)
        return ;
      if (!t.isTimeout(0.03))
      {
        run = reloadMap();
        _win->refresh(_map);
        t.reinit();
      }
  }
}

void		Core::changeLib(Event::code event)
{
  static const std::string	libs[]=
  {
    "bin/lib_nibbler_ncurses.so",
    "bin/lib_nibbler_sdl.so",
    "bin/lib_nibbler_allegro.so",
    "bin/lib_nibbler_menu.so",
  };

  try {
    this->closeLibrary();
    int pos = static_cast<Event::code>((int)event) - static_cast<Event::code>((int)Event::LIB1);

    if (pos < 0 || pos >= (int)SIZE_TAB(libs))
      Msg::Error("Lib doesn't exists.");
    this->getLibrary(libs[pos]);
  }
  catch (MException &e)
  {
    Msg::Critical(e.what());
    exit(0);
  }
}

bool		Core::checkEvent(void)
{
  Event::code	event;

  event = _win->getEvent();
  if (event == Event::NONE)
    return true;
  if (event == Event::QUIT)
    return false;
  else if (event == Event::LIB1 || event == Event::LIB2
    || event == Event::LIB3 || event == Event::PAUSE)
    changeLib(event);
  else if (event == Event::LEFT || event == Event::RIGHT)
    _lastKey = event;
  return true;
}

bool		Core::reloadMap(void)
{
  bool	run;
  int	tmp;

  tmp = (int)this->_map.direction;
  if (this->_lastKey == Event::LEFT)
    _map.direction = static_cast<Event::code>(tmp - 1);
  else if (this->_lastKey == Event::RIGHT)
    _map.direction = static_cast<Event::code>(tmp + 1);
  if (_map.direction < Event::LEFT)
    _map.direction = Event::DOWN;
  if (_map.direction > Event::DOWN)
    _map.direction = Event::LEFT;
  run = move_forward();
  _lastKey = Event::NONE;
  return (run);
}

bool
Core::move_forward(void)
{
  Case::case_name	colision;
  Case::t_pos		dir = {0, 0, Case::SNAKE};

  if (this->_map.direction == Event::LEFT)
    dir = (Case::t_pos){-1, 0, Case::SNAKE};
  else if (this->_map.direction == Event::RIGHT)
    dir = (Case::t_pos){1, 0, Case::SNAKE};
  else if (this->_map.direction == Event::UP)
    dir = (Case::t_pos){0, -1, Case::SNAKE};
  else if (this->_map.direction == Event::DOWN)
    dir = (Case::t_pos){0, 1, Case::SNAKE};

  t_mapiter front = this->_map.snake.begin();
  dir.x += (*front).x;
  dir.y += (*front).y;
  colision = this->checkCollisions(dir);
  this->_map.snake.push_front(dir);
  if (colision != Case::FOOD)
    this->_map.snake.pop_back();
  return (colision != Case::WALL);
}

Case::case_name	Core::checkCollisions(Case::t_pos pos)
{
  t_mapiter	iter;

  if (pos.x < 0 || pos.x > (int)_width
    || pos.y < 0 || pos.y > (int)_height)
    return (Case::WALL);

  /*
  ** check snake
  */
  for (iter = _map.snake.begin(); iter != _map.snake.end(); iter++)
    {
      if ((*iter).x == pos.x && (*iter).y == pos.y)
	return (Case::WALL);
    }

  /*
  ** check rest of map
  */
  for (iter = _map.others.begin(); iter != _map.others.end(); iter++)
    {
      if ((*iter).type == Case::FOOD
	&& (*iter).x ==  (*(_map.snake.begin())).x
	&& (*iter).y ==  (*(_map.snake.begin())).y)
	{
	  this->grow();
	  return (Case::FOOD);
	}
    }
  return (Case::EMPTY);
}

void	Core::grow()
{
  _map.score++;
  _map.others.pop_back();
  put_food();
}

void
Core::put_food(void)
{
  Case::t_pos	pos = {0, 0, Case::FOOD};

  do
    {
      pos.x = ::rand() % _width;
      pos.y = ::rand() % _height;
    } while (std::find(_map.others.begin(), _map.others.end(), pos) != _map.others.end()
      && std::find(_map.snake.begin(), _map.snake.end(), pos) != _map.snake.end()
&& _map.snake.size() + _map.others.size() < _width * _height);
  _map.others.push_back(pos);
}

void		Core::initMap(void)
{
  std::vector<int>	tmp;
  int middle_y = _height / 2;
  int middle_x = _width / 2;

  _map.snake.push_back((Case::t_pos){ middle_x - 1, middle_y, Case::SNAKE });
  _map.snake.push_back((Case::t_pos){ middle_x, middle_y, Case::SNAKE });
  _map.snake.push_back((Case::t_pos){ middle_x + 1, middle_y, Case::SNAKE });
  _lastKey = Event::NONE;
  _map.direction = Event::LEFT;
  put_food();
  _map.score = 0;
}

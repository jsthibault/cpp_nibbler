//
// sdl.cpp for nibbler in /home/ouache_s/depots/github/Nibbler/SDL
//
// Made by samy ouachek
// Login   <ouache_s@epitech.net>
//
// Started on  Sat Apr  5 15:29:48 2014 samy ouachek
// Last update Sun Apr  6 18:04:33 2014 samy ouachek
//

#include "sdl.hh"
#include "../utils/Debug.hh"

/* ctor/dtor */
sdl::sdl(void)
{
  SDL_Init(SDL_INIT_VIDEO);
}

sdl::~sdl(void)
{
  SDL_Quit();
}

/* IWindow implementation */
void
sdl::init(int width, int height)
{
  this->_width = width;
  this->_height = height;
  if ((this->_window = SDL_SetVideoMode(32 * height, 32 * width, 32, SDL_HWSURFACE)) == NULL)
    Msg::Error("Error while loading SDL.");
  SDL_WM_SetCaption("Nibard", NULL);
  if ((_sprites[0] = IMG_Load("sdl/img/00.png")) == NULL
    || (_sprites[1] = IMG_Load("sdl/img/01.png")) == NULL
    || (_sprites[2] = IMG_Load("sdl/img/02.png")) == NULL
    || (_sprites[3] = IMG_Load("sdl/img/03.png")) == NULL
    || (_sprites[4] = IMG_Load("sdl/img/04.png")) == NULL
    || (_sprites[5] = IMG_Load("sdl/img/05.png")) == NULL
    || (_sprites[6] = IMG_Load("sdl/img/06.png")) == NULL
    || (_sprites[7] = IMG_Load("sdl/img/07.png")) == NULL
    || (_sprites[8] = IMG_Load("sdl/img/08.png")) == NULL
    || (_sprites[9] = IMG_Load("sdl/img/09.png")) == NULL
    || (_sprites[10] = IMG_Load("sdl/img/10.png")) == NULL
    || (_sprites[11] = IMG_Load("sdl/img/floor1.png")) == NULL
    || (_sprites[12] = IMG_Load("sdl/img/floor2.png")) == NULL
    || (_sprites[13] = IMG_Load("sdl/img/food.png")) == NULL
    || (_sprites[14] = IMG_Load("sdl/img/left.png")) == NULL
    || (_sprites[15] = IMG_Load("sdl/img/up.png")) == NULL
    || (_sprites[16] = IMG_Load("sdl/img/right.png")) == NULL
    || (_sprites[17] = IMG_Load("sdl/img/down.png")) == NULL)
    Msg::Error("Error while loading images.");
}

Event::code
sdl::getEvent(void)
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  if (event.type == SDL_QUIT)
    return (Event::QUIT);
  else if (event.type == SDL_KEYDOWN)
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return (Event::QUIT);
      else if (event.key.keysym.sym == SDLK_RIGHT)
	{
	  return (Event::RIGHT);
	}
      else if (event.key.keysym.sym == SDLK_LEFT)
	return (Event::LEFT);
      else if (event.key.keysym.sym == SDLK_p)
	return (Event::PAUSE);
      else if (event.key.keysym.sym == SDLK_1)
	return (Event::LIB1);
      else if (event.key.keysym.sym == SDLK_2)
	return (Event::LIB2);
      else if (event.key.keysym.sym == SDLK_3)
	return (Event::LIB3);
    }
  return (Event::NONE);
}

void
sdl::display_background(void)
{
  int	floor = 11;
  int	x = 0;
  int	y = 0;
  SDL_Rect	pos = {
    0, 0, 0, 0
  };

  while (y < _width)
    {
      x = 0;
      while (x < _height)
	{
	  pos = (SDL_Rect){x * 38, y * 38, 0 , 0};
	  if (SDL_BlitSurface(_sprites[floor], NULL, _window, &pos) == -1)
	    Msg::Error("Error while blitting image on screen");
	  floor = (floor == 11) ? 11 : 11;
	  ++x;
	}
      floor = (floor == 11) ? 11 : 11;
      ++y;
    }
  if (SDL_Flip(_window) == -1)
    Msg::Error("Error while flipping screen");
}

void
sdl::display_items(map_t const &map)
{

  int		pokemons = 0;
  t_mapiter	it;
  SDL_Rect	pos = {
    0, 0, 0, 0
  };

  // Display snake
  for (it = map.snake.begin(); it != map.snake.end(); ++it)
    {
      if (pokemons > 9)
	pokemons = 0;
      pos.x = (*it).x * 32;
      pos.y = (*it).y * 32;
      if (SDL_BlitSurface(_sprites[(it == map.snake.begin()) ? 13 + (int)map.direction : pokemons], NULL, _window, &pos) == -1)
	Msg::Error("Error while blitting image on screen");
      ++pokemons;
    }

  // display others
  for (it = map.others.begin(); it != map.others.end(); ++it)
    {
      pos.x = (*it).x * 32;
      pos.y = (*it).y * 32;
      if (SDL_BlitSurface(_sprites[13], NULL, _window, &pos) == -1)
	Msg::Error("Error while blitting image on screen");
    }
  if (SDL_Flip(_window) == -1)
    Msg::Error("Error while flipping screen");
}

void
sdl::refresh(map_t const &map)
{
  display_background();
  display_items(map);
}

/* anti-copy */
sdl::sdl(sdl const &other)
{
  (void)other;
}

const sdl		&sdl::operator=(sdl const &other)
{
  (void)other;
  return (*this);
}

extern "C"
{

  IWindow *	_new(void)
  {
    IWindow *tmp = new sdl();
    return tmp;
  }

  void	_delete(IWindow *instance)
  {
    delete instance;
  }

}

//
// sdl.hh for nibbler in /home/ouache_s/depots/github/Nibbler/SDL
//
// Made by samy ouachek
// Login   <ouache_s@epitech.net>
//
// Started on  Sat Apr  5 15:29:43 2014 samy ouachek
// Last update Sun Apr  6 17:34:39 2014 samy ouachek
//

#ifndef SDL_HH_
# define SDL_HH_

# include "../core/IWindow.hh"
# include <iostream>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>

class	sdl : public IWindow
{
public:
  /* ctor/dtor */
  sdl(void);
  ~sdl(void);

  /* IWindow implementation */
  virtual void		init(int, int);
  virtual Event::code	getEvent(void);
  virtual void		refresh(map_t const &);
  void			display_background(void);
  void	display_items(map_t const &map);

private:
  /* anti-copy */
  sdl(sdl const &other);
  const sdl		&operator=(sdl const &other);

  /* private attributes */
  int	_width;
  int	_height;
  SDL_Surface	*_window;
  SDL_Surface	*_sprites[18];
};

#endif /* !SDL_HH_ */

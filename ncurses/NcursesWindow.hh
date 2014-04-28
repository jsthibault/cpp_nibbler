#ifndef NCURSES_WINDOW_H_
# define NCURSES_WINDOW_H_

#include "Window.hh"
#include "App.hh"
#include "../core/IWindow.hh"

class	CursesWindow : public IWindow
{
private:
  ncurses::Window	*_win;
  ncurses::App		*_app;

  int			_width;
  int			_height;

  void			calcBeginPos(int *, int *);
  void			drawMenu(int score);
  char			getSprite(Case::case_name type);

  typedef struct	s_sprites
  {
    char		sprite;
    Case::case_name	type;
  }			t_sprites;

public:
  CursesWindow();
  virtual ~CursesWindow();

  Event::code	getEvent();
  void		refresh(map_t const &map);
  void		destroy();
  void		init(int, int);

};

#endif /* !NCURSES_WINDOW_H_ */

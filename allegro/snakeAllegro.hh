//
// snake_allegro.hh for snake_allegro.hh in /home/thibauj/rendu/Nibbler/allegrow-JS
//
// Made by thibau_j
// Login   <thibau_j@epitech.net>
//
// Started on  Fri Apr  4 10:16:05 2014 thibau_j
// Last update Sun Apr  6 02:20:52 2014 thibau_j
//

#ifndef SNAKEALLEGRO_HH
# define SNAKEALLEGRO_HH

# include "../core/IWindow.hh"

typedef struct	s_color
{
  int		r;
  int		g;
  int		b;
}		t_color;

static t_color tab[] =
  {
      {0, 188, 158},
      {70, 214, 144},
      {51, 153, 219},
      {178, 122, 195},
      {52, 73, 94},
      {0, 160, 134},
      {70, 190, 129},
      {82, 153, 199},
      {167, 105, 188},
      {86, 99, 115},
      {241, 194, 16},
      {232, 125, 29},
      {235, 76, 55},
      {236, 240, 241},
      {147, 165, 167},
      {246, 155, 12},
      {221, 116, 48},
      {196, 56, 39},
      {202, 207, 211},
      {126, 140, 141},
  };

class					snakeAllegro : public IWindow
{
private:
  int					_colorMap;
  int					_colorSnake;
  int					_colorHead;
  int					_colorFood;
  int					_height;
  int					_width;
  void					displayMap(map_t const &map);
  int					giveRandom(int const &nb_mod);

public:
  snakeAllegro();
  virtual ~snakeAllegro();

  void					refresh(map_t const &map);
  void					init(int height, int width);
  Event::code				getEvent();
};

#endif		/* !SNAKEALLEGRO_HH */

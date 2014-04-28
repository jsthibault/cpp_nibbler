/*
** IWindow.h for core in /home/loic/dev/epitech/cpp/Nibbler/core
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mer. mars 19 08:48:56 2014 lefloc_l
// Last update Sun Apr  6 18:24:31 2014 samy ouachek
*/

#ifndef IWINDOW_H_
# define IWINDOW_H_

#include <list>

namespace Event
{
  enum code
  {
    NONE = 0,
    LEFT,
    UP,
    RIGHT,
    DOWN,
    MENU,
    QUIT,
    LIB1,
    LIB2,
    LIB3,
    PAUSE
  };
}

namespace	Case
{

  enum case_name
    {
      EMPTY,
      SNAKE,
      FOOD,
      WALL
    };

  typedef struct	s_pos
  {
    int		x;
    int		y;
    case_name	type;
    bool	operator==(const struct s_pos &other)
    {
      return (this->x == other.x
	&& this->y == other.y
	&& this->type == other.type);
    }
  }			t_pos;

}

typedef   std::list<Case::t_pos>::const_iterator	t_mapiter;

typedef struct			s_map
{
  std::list<Case::t_pos>	snake;
  std::list<Case::t_pos>	others;
  int				direction;
  int				score;
}				map_t;


class	IWindow
{
public:

  virtual ~IWindow(void) { };

  /*
   * init library
   */
  virtual void	init(int, int) = 0;

  /*
   * just check if an event occured and return the Event::code
   */
  virtual Event::code	getEvent(void) = 0;

  /*
   * refresh the window
   */
  virtual void		refresh(map_t const &) = 0;
};

#endif /* !IWINDOW_H_ */

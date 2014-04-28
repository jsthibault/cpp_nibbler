/*
** Core.h for core in /home/loic/dev/epitech/cpp/Nibbler/core
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mer. mars 19 08:56:10 2014 lefloc_l
// Last update Mon Apr 28 16:59:42 2014 thibau_j
*/

#ifndef CORE_HH_
# define CORE_HH_

#include <string>
#include <vector>
#include <algorithm>

#include "./IWindow.hh"
#include "./dlloader.hh"

class	Core
{
private:
  Event::code		_lastKey;
  std::string		_libname;
  IWindow		*_win;
  dlloader<IWindow>	*_loader;

  size_t		_width;
  size_t		_height;

  map_t			_map;

  Core(const Core &other);
  Core		&operator=(const Core &other);

  /*
   * load the Library
   */
  void		getLibrary(std::string const &name);

  /*
   * run infinite loop.
   */
  bool		reloadMap(void);

  /*
   * call win->getEvent and do stuff
   */
  bool		checkEvent(void);

  /*
   * refresh map according to events
   */
  bool		move_forward(void);

  Case::case_name	checkCollisions(Case::t_pos pos);

  void		put_food(void);

public:
  Core(std::string const &, size_t, size_t);
  ~Core();

  void		*getLibrary(void);
  void		run(void);
  void		closeLibrary(void);
  void		initMap(void);
  void		grow(void);
  void		changeLib(Event::code event);
};

#endif /* !CORE_HH_ */

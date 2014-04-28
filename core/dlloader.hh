//
// dlloader.hh for dlloader in /home/ouache_s/tp/dynamic_libs
//
// Made by samy ouachek
// Login   <ouache_s@epitech.net>
//
// Started on  Wed Mar 26 19:43:34 2014 samy ouachek
// Last update Sat Apr  5 14:32:35 2014 samy ouachek
//

#ifndef DLLOADER_HH_
# define DLLOADER_HH_

# include <string>
# include "IWindow.hh"

template <typename T>
class	dlloader
{
public:
  /* ctor/dtor */
  dlloader(std::string const &lib_name);
  ~dlloader(void);

  /* public member functions */
  T	*create(void);
  void	free(T *instance);

private:
  /* copy creation & assignation forbidden */
  dlloader const	&operator=(dlloader const &other);
  dlloader(dlloader const &other);

  /* private attributes */
  void	*_handle;
  void	*_new;
  void	*_delete;
};

#endif /* !DLLOADER_HH_ */

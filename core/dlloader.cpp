//
// dlloader.cpp for dlloader in /home/ouache_s/tp/dynamic_libs
//
// Made by samy ouachek
// Login   <ouache_s@epitech.net>
//
// Started on  Fri Apr  4 11:08:50 2014 samy ouachek
// Last update Mon Apr 28 16:59:50 2014 thibau_j
//

#include <dlfcn.h>
#include "dlloader.hh"
#include "../utils/Debug.hh"
#include <iostream>

template<typename T>
dlloader<T>::dlloader(std::string const &lib_name)
{
  if ((this->_handle = dlopen(lib_name.c_str(), RTLD_LAZY)) == NULL)
    Msg::Error(dlerror());
  if ((this->_new = dlsym(this->_handle, "_new")) == NULL)
    Msg::Error(dlerror());
  if ((this->_delete = dlsym(this->_handle, "_delete")) == NULL)
    Msg::Error(dlerror());
}

template<typename T>
dlloader<T>::~dlloader(void)
{
  dlclose(this->_handle);
}

template<typename T>
T *
dlloader<T>::create(void)
{
  T *	(*init)(void);

  init = reinterpret_cast<T *(*)(void)>(this->_new);
  return (init());
}

template<typename T>
void
dlloader<T>::free(T *instance)
{
  void	(*del)(T *);

  del = reinterpret_cast<void (*)(T *)>(this->_delete);
  del(instance);
}

template<typename T>
dlloader<T> const &
dlloader<T>::operator=(dlloader const &other)
{
  (void)other;
  return (*this);
}

template<typename T>
dlloader<T>::dlloader(dlloader const &other)
{
  (void)other;
}

template class dlloader<IWindow>;

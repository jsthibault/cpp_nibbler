//
// main.cpp for nibbler in /home/ouache_s/depots/github/Nibbler/core
//
// Made by samy ouachek
// Login   <ouache_s@epitech.net>
//
// Started on  Sat Apr  5 14:32:55 2014 samy ouachek
// Last update Sun Apr  6 18:03:16 2014 samy ouachek
//

#include <iostream>
#include <exception>
#include <stdlib.h>
#include "Core.hh"
#include "../utils/Debug.hh"
#include "../utils/Utils.hpp"

void	usage()
{
  Msg::Info("./nibbler width height lib.so");
}

int	main(int ac, char **av)
{

  if (ac != 4)
    {
      usage();
      return -1;
    }
  if (av[0] == NULL)
    {
      return -1;
    }
  try
    {
      size_t	width = 0;
      size_t	height = 0;

      width = convert<size_t>(av[1]);
      height = convert<size_t>(av[2]);

      Core	core(av[3], width, height);
      core.initMap();
      core.run();
    }
  catch (MException &e)
    {
      Msg::Critical(e.what());
    }
  return (0);
}

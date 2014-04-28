/*
** Timer.h for core in /home/loic/dev/epitech/cpp/Nibbler/core
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mer. mars 19 09:28:33 2014 lefloc_l
// Last update Sat Apr  5 14:35:08 2014 samy ouachek
*/

#ifndef TIMER_HH_
# define TIMER_HH_


class	Timer
{
private:
  unsigned long		_beginTime;

public:
  Timer(void);
  ~Timer(void);
  Timer(const Timer &other);
  Timer &	operator=(const Timer &other);

  unsigned long		elapsedTime(void) const;
  bool			isTimeout(float seconds) const;
  void			reinit(void);

  unsigned long		getBeginTime(void) const;
};

#endif /* !TIMER_HH_ */

/*
** Window.h for mndk in /home/loic/dev/epitech/cpp/Nibbler/ncurses/mndk
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mer. mars 19 10:59:25 2014 lefloc_l
** Last update dim. avril 06 20:18:00 2014 lefloc_l
*/

#ifndef WINDOW_H_
# define WINDOW_H_

#include <string>

#include "Colors.hh"
#include <ncurses.h>

namespace ncurses
{

  class	Window
  {
  private:
    WINDOW*	_win;

    std::string		_header;
    std::string		_footer;

    void		printHeader();

  public:
    Window();
    Window(const Window &other);
    Window &	operator=(const Window &other);

    virtual ~Window();

    std::string		getHeader() const;
    std::string		getFooter() const;
    WINDOW*		getWin() const;

    virtual void	resize(const size_t w, const size_t h);
    int			width() const;
    int			height() const;

    void		refresh();
    void		clear();
    void		touchLine(const int start, const int count);
    void		moveCursor(const int y, const int x);

    int			bindKey() const;

    void		write(const char c);
    void		write(const std::string & str);
    void		write(const int attribut, const std::string & str);

    /*
     * ls - left side,
     * rs - right side,
     * ts - top side,
     * bs - bottom side,
     * tl - top left-hand corner,
     * tr - top right-hand corner,
     * bl - bottom left-hand corner, and
     * br - bottom right-hand corner.
     */
    void		createBorder(const char ls, const char rs, const char ts,
        const char bs, const char tl, const char tr, const char bl, const char bn);
    void		createBorder(const char v, const char h, const char c);
    void		createBorder();

    void		drawVLine(const char c, int y, int x, int size);
    void		drawHLine(const char c, int y, int x, int size);

    void		frame(size_t x, size_t y, size_t h, size_t w);
    void		frame(size_t x, size_t y, size_t h, size_t w,
        const char ls, const char rs, const char ts, const char bs, const char tl,
        const char tr, const char bl, const char bn);

    void		useColor(int nb_pair);

    void		setHeader(const std::string str);
    void		setFooter(const std::string& str);

    void		setColor(const ncurses::Color &c);
    void		setBackground(const ncurses::Color &);

  };

}

#endif /* !WINDOW_H_ */

/*
** Colors.h for mndk in /home/loic/dev/epitech/cpp/Nibbler/ncurses/mndk
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  mer. mars 19 13:25:05 2014 lefloc_l
** Last update dim. avril 06 20:16:12 2014 lefloc_l
*/

#ifndef COLORS_H_
# define COLORS_H_

#include <string>
#include <vector>
#include <ncurses.h>

# define COLOR_TRANSPARANT	0xfff

typedef struct	s_color
{
  std::string	font;
  std::string	background;
}		t_color;

namespace ncurses
{
  class ColorManager
  {
  private:
    ColorManager();
    virtual ~ColorManager();
    ColorManager(const ColorManager &other);
    ColorManager &	operator=(const ColorManager &other);

    static ColorManager*		_instance;
    std::vector<short>			_colors;

  public:
    static ColorManager*		getInstance();

    short				get();
    void				get(short);
    void				put(short);

  };

  /*
   * contents one pair of colors
   */
  class Color
  {
  private:
    void	swap(Color& other);
    short	_nb_pair;
    attr_t	_attr;

  public:
    Color();
    /*
     * attr can be:
     * A_NORMAL        Normal display (no highlight)
     * A_STANDOUT      Best highlighting mode of the terminal.
     * A_UNDERLINE     Underlining
     * A_REVERSE       Reverse video
     * A_BLINK         Blinking
     * A_DIM           Half bright
     * A_BOLD          Extra bright or bold
     * A_PROTECT       Protected mode
     * A_INVIS         Invisible or blank mode
     * A_ALTCHARSET    Alternate character set
     * A_ITALIC        Italics (non-X/Open extension)
     * A_CHARTEXT      Bit-mask to extract a character
     */
    Color(short f, short b, attr_t attr = A_NORMAL);
    Color(const Color& other);
    Color& operator=(const Color& other);
    ~Color();

    short	num() const;
    attr_t	attr() const;
  };
}

#endif /* !COLORS_H_ */

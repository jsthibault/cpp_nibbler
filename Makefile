RM=			rm -rf
CC=			clang++

LIB_DIR=		bin

NAME=			nibbler
OBJ_DIR=		obj
SRC_DIR=		core

SRC=			Core.cpp \
			Timer.cpp \
			main.cpp \
			dlloader.cpp

LIB_NCURSES_NAME=	lib_nibbler_ncurses.so
LIB_SDL_NAME=		lib_nibbler_sdl.so
LIB_ALLEGRO_NAME=	lib_nibbler_allegro.so

LIB_NCURSES_SRC=	App.cpp \
			Colors.cpp \
			Error.cpp \
			Exception.cpp \
			Window.cpp \
			extern.cpp \
			NcursesWindow.cpp

LIB_SDL_SRC=		sdl.cpp \

LIB_ALLEGRO_SRC=	snakeAllegro.cpp \
			externe.cpp


LIB_NCURSES_DIR=	ncurses
LIB_NCURSES_OBJ_DIR=	$(OBJ_DIR)/ncurses

LIB_ALLEGRO_DIR= 	allegro
LIB_ALLEGRO_OBJ_DIR=	$(OBJ_DIR)/allegro

LIB_SDL_DIR=		sdl
LIB_SDL_OBJ_DIR=	$(OBJ_DIR)/sdl

UTILS_DIR=		utils
UTILS_OBJ_DIR=		$(OBJ_DIR)/utils

UTILS_SRC=		Debug.cpp

OBJ=			$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
LIB_NCURSES_OBJ=	$(addprefix $(LIB_NCURSES_OBJ_DIR)/, $(LIB_NCURSES_SRC:.cpp=.o))
LIB_SDL_OBJ=		$(addprefix $(LIB_SDL_OBJ_DIR)/, $(LIB_SDL_SRC:.cpp=.o))
LIB_ALLEGRO_OBJ=	$(addprefix $(LIB_ALLEGRO_OBJ_DIR)/, $(LIB_ALLEGRO_SRC:.cpp=.o))
UTILS_OBJ=		$(addprefix $(UTILS_DIR)/, $(UTILS_SRC:.cpp=.o))



all: $(NAME) $(LIB_NCURSES_NAME) $(LIB_SDL_NAME) $(LIB_ALLEGRO_NAME)


$(NAME): $(OBJ) $(UTILS_OBJ)
	   $(CC) -o $(NAME) $(OBJ) $(UTILS_OBJ) -ldl

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CXXFLAGS)

LDFLAGS= -shared -lncurses
CXXFLAGS= -fPIC -W -Wextra -Wall -g

$(LIB_NCURSES_NAME):	$(LIB_NCURSES_OBJ) $(UTILS_OBJ)
	@mkdir -p $(LIB_DIR)
	$(CC) -o $(LIB_DIR)/$(LIB_NCURSES_NAME) $(LIB_NCURSES_OBJ) $(UTILS_OBJ) $(LDFLAGS)

$(LIB_NCURSES_OBJ_DIR)/%.o: $(LIB_NCURSES_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CXXFLAGS)

LDFLAGS += -shared -lSDL -lSDL_image -lSDL_ttf

$(LIB_SDL_NAME):	$(LIB_SDL_OBJ) $(UTILS_OBJ)
	@mkdir -p $(LIB_DIR)
	$(CC) -o $(LIB_DIR)/$(LIB_SDL_NAME) $(LIB_SDL_OBJ) $(UTILS_OBJ) $(LDFLAGS)

$(LIB_SDL_OBJ_DIR)/%.o: $(LIB_SDL_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CXXFLAGS)


LDFLAGS+=	`allegro-config --libs`

$(LIB_ALLEGRO_NAME):	$(LIB_ALLEGRO_OBJ) $(UTILS_OBJ)
	@mkdir -p $(LIB_DIR)
	$(CC) -o $(LIB_DIR)/$(LIB_ALLEGRO_NAME) $(LIB_ALLEGRO_OBJ) $(UTILS_OBJ) $(LDFLAGS)

$(LIB_ALLEGRO_OBJ_DIR)/%.o: $(LIB_ALLEGRO_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CXXFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) $(LIB_NCURSES_OBJ)
	$(RM) $(LIB_SDL_OBJ)
	$(RM) $(LIB_ALLEGRO_OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(OBJ_DIR)
	$(RM) $(LIB_DIR)

re: fclean all

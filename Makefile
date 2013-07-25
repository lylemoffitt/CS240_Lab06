# Final Compiled Executable
    NAME	:=  imdb
    COMPILER	:=  g++-4.8 # Change if you have a different compiler or version of GCC
    OPTIONS	:=  -Wall -Wextra -Weffc++
    FLAGS	:=  -v -std=c++11

    CC_THIS	:= $(COMPILER) $(OPTIONS) $(FLAGS) -o

all	:   $(NAME)

${%.cc:.cc=.o}	:   ${%.cpp %.h %.cc}
	$(CC_THIS) ${%.o}
${%.h:.h=.o}	:   ${%.cpp %.h}
	$(CC_THIS) ${%.o}
${%.cpp:.cpp=.o}:   ${%.cpp}
	$(CC_THIS) ${%.o}


$(NAME)	:   ${*.o}
	$(CC_THIS) $(NAME)


clean:
	- rm ./$(NAME)
	- rm ./$(ALL_OBJS)

    USE_GCC	:=  g++-4.8 # Change if you have a different compiler or version of GCC
    GCC_OP	:=  -Wall -Wextra -Weffc++

    USE_LLVM	:=  clang++
    LLVM_OP	:=  -gO0 -Weverything -fcaret-diagnostics

# Final Compiled Executable
    NAME	:=  imdb
    COMPILER	:=  $(USE_$(CCC))
    OPTIONS	:=  $($(CCC)_OP)
    FLAGS	:=  -std=c++11

    CC_THIS	:= $(COMPILER) $(OPTIONS) $(FLAGS) -o

# List relevant files
    LS_CC	:= $(*.cc)
    LS_H	:= $(*.h)
    LS_CPP	:= $(*.cpp)


all:   $(LS_CC:.cc=.o) $(LS_H:.h=.o) $(LS_CPP:.cpp=.o)

${%.cc:%.cc=%.o}  :   ${%.cpp %.h %.cc}
	$(CC_THIS) ${%.o}
${%.h:%.h=%.o}    :   ${%.cpp %.h}
	$(CC_THIS) ${%.o}
${%.cpp:%.cpp=%.o}:   ${%.cpp}
	$(CC_THIS) ${%.o}


$(NAME)	:   ${*.o}
	$(CC_THIS) $(NAME)


clean:
	- rm ./$(NAME)
	- rm ./$(ALL_OBJS)

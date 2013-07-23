# Final Compiled Executable
    NAME	:= imdb

###  C    ###
# Sources, Headers, and Objects
    C_SRCS	:= $(*.c)
    C_HDRS	:= $(*.h)

    C_OBJS	:= ${C_SRCS:.c=.o}


###  C++  ###
# Sources, Headers, Templates, and Objects
    CXX_SRCS	:= $(*.cpp)
    CXX_HDRS	:= $(*.hh) $(C_HDRS)
    CXX_TMPL	:= $(*.cc)

    CXX_OBJS	:= ${CXX_SRCS:.cpp=.o}


# Put both lists together
    ALL_OBJS	:= $(C_OBJS) $(CXX_OBJS)

.PHONY: all clean

all: $(NAME)
    $(NAME)	:= $(ALL_OBJS)

    %C_OBJS	:= %C_SRCS %C_HDRS
    %CXX_OBJS	:= %CXX_SRCS %CXX_HDRS %CXX_TMPL


clean:
    @- $(RM) $(NAME)
    @- $(RM) $(ALL_OBJS)





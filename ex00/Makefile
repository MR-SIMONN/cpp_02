SRCS = main.cpp Fixed.cpp

NAME = fixed

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:%.cpp=%.o)

DEPS = Fixed.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $^  -o $@

%.o: %.cpp $(DEPS)
	$(CXX)  -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# ----------------------------------
# PROJECT NAME
# ----------------------------------
NAME = megaphone

# ----------------------------------
# COMPILATION AND FLAGS
# ----------------------------------
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

# ----------------------------------
# PATH
# ----------------------------------
SRC_DIR    = src
OBJ_DIR    = obj

# ----------------------------------
# COLORS
# ----------------------------------
RESET       = \033[0m
BLACK       = \033[0;30m
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
WHITE       = \033[0;37m

# ----------------------------------
# SOURCES
# ----------------------------------
SRCS    = megaphone.cpp
OBJS    = $(SRCS:.cpp=.o)

# ----------------------------------
# RULES
# ----------------------------------

all: $(NAME) banner
banner :
	@echo "  ░██████  ░█████████  ░█████████       $(BLUE)░████$(RESET)  "
	@echo " ░██   ░██ ░██     ░██ ░██     ░██     $(BLUE)░██ ░██$(RESET)  "
	@echo "░██        ░██     ░██ ░██     ░██    $(BLUE)░██ ░████$(RESET) "
	@echo "░██        ░█████████  ░█████████     $(BLUE)░██░██░██$(RESET) "
	@echo "░██        ░██         ░██            $(BLUE)░████ ░██$(RESET) "
	@echo "░██   ░██  ░██         ░██             $(BLUE)░██ ░██$(RESET)  "
	@echo "  ░██████  ░██         ░██              $(BLUE)░████$(RESET)   "
                                                
                                                
                                                                                   
# Final link
$(NAME): $(OBJS)
	@echo "\033[1;34m[LINK] -> Creating $(NAME)...\033[0m"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m[OK] -> $(NAME) ready!\033[0m"

# Compilation of .c in .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	@rm -f $(OBJS)
	@echo "\033[1;31m[CLEAN] -> Removing object files...\033[0m"

# Full Clean
fclean: clean
	@echo "\033[1;31m[FCLEAN] -> Removing executable...\033[0m"
	@rm -f $(NAME)

# Rebuild
re: fclean all

# ----------------------------------
# PHONY
# ----------------------------------
.PHONY: all clean fclean re
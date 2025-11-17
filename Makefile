# === EXECUTABLE NAME ===
NAME			:= philo

# === CONFIGURATION ===
CC 				:= cc
RM				:= rm -f
MKDIR			:= /usr/bin/mkdir -p

# === DIRECTORIES ===
# Source directories for vpath
SRC_DIR        	:= src
# Object file directories
OBJ_DIR_MAND	:= obj/mandatory
OBJ_DIR_BONUS	:= obj/bonus
#Include directories
INC_DIR         := include

# === FLAGS ===
CFLAGS 			:= -Wall -Wextra -Werror
CFLAGS			+= -g3 -O0
MAKEFLAGS 		+= --no-print-directory
CPPFLAGS        := -I$(INC_DIR)
LDFLAGS_PHILO   := -pthread
#CFLAGSEXTRA?? = -g -pthread ...accuracystuff

# === SOURCE FILES ===
vpath %.c $(SRC_DIR)

SRCS_MAND		:=	main.c \
					time.c \

SRC_BONUS		:=

# === OBJECT FILES ===
OBJS_MAND		:= $(patsubst %.c, $(OBJ_DIR_MAND)/%.o, $(SRCS_MAND))
OBJS_BONUS      := $(addprefix $(OBJ_DIR_BONUS)/, $(SRCS_BONUS:.c=.o))

# Dependency files for header changes
DEPS            := $(OBJS_MAND:.o=.d) $(OBJS_BONUS:.o=.d)

# === MAIN RULES ===
## .DEFAULT_GOAL   := all
all: mandatory

-include $(DEPS)

# --- TARGETS ---
mandatory : $(NAME)

$(NAME): $(OBJS_MAND)
	$(CC) $(CFLAGS) $(OBJS_MAND) $(LDFLAGS_PHILO) -o $(NAME)

# --- COMPILATION RULES ---
$(OBJ_DIR_MAND)/%.o: %.c
	@$(MKDIR) -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c
	@$(MKDIR) -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf obj

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus mandatory clean fclean re


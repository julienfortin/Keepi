##
## Makefile <Keepi>
## 
## Made by	Julien Fortin
## contact	<julien.fortin.it@gmail.com>
##

CPP	 		:= g++
NAME		:= keepi

TARGET		:= ./bin

RM			:= rm -rf

FLEX 		:= ./flex
BISON 		:= ./bison

CPPFLAGS	+= -I$(BISON) -I./include/
CPPFLAGS	+= -g

SRCS_DIR	:= ./src

SRCS		:= 	$(SRCS_DIR)/Keepi.cpp \
				$(SRCS_DIR)/KSymtable.cpp \
				$(SRCS_DIR)/KObject.cpp \
				$(SRCS_DIR)/KInteger.cpp \
				$(SRCS_DIR)/KString.cpp \
				$(SRCS_DIR)/KDouble.cpp \
				$(SRCS_DIR)/KBool.cpp \
				$(SRCS_DIR)/KTypes.cpp \
				$(SRCS_DIR)/KTypeException.cpp \
				$(SRCS_DIR)/KZeroDivisionException.cpp \

OBJS		:= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): _bison _flex
	$(CPP) $(CPPFLAGS) -c $(FLEX)/lex.yy.c -o $(FLEX)/lex.yy.o
	$(CPP) $(CPPFLAGS) $(FLEX)/lex.yy.o $(BISON)/$(NAME).tab.c $(SRCS) -o $(TARGET)/$(NAME)

_flex: _bison
	make -C $(FLEX)

_bison:
	make -C $(BISON)

clean: 
	$(RM) $(TARGET)/keepi.dSYM
	make -C $(FLEX) clean
	make -C $(BISON) clean

fclean: clean
	$(RM) $(TARGET)/$(NAME)

re: fclean all

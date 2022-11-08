#ifndef COLOR_H
# define COLOR_H
# include <stdio.h>

#define BLACK "\033[0;30m"
#define RED  "\033[0;31m"
#define GREEN  "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE  "\033[0;34m"
#define PINK  "\033[0;35m"
# define WHITE "\033[0;37m"
#define RESET "\033[0m"

#define RED_B "\033[31;7m"
#define GREEN_B "\033[32;7m"
#define YELLOW_B "\033[33;7m"
void print_error(const char *error);
void print_mgs(const char *msg);
void print_mgs_B(const char *msg);
void print_hint(const char *hint);
void print_hint_B(const char *hint);

#endif


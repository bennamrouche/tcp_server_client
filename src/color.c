//bennamrouche elmehdi

#include "color.h"

void print_error(const char *error)
{
	printf("%s%s%s", RED_B, error, RESET);
}

void print_mgs(const char *msg)
{
	printf("%s%s%s", GREEN, msg, RESET);
}

void print_mgs_B(const char *msg)
{
	printf("%s%s%s", GREEN_B, msg, RESET);
}
void print_hint(const char *hint)
{
	printf("%s%s%s", YELLOW, hint, RESET);
}
void print_hint_B(const char *hint)
{
	printf("%s%s%s",YELLOW_B,hint,RESET);
}

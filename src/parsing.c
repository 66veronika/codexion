#include "codexion.h"

int	is_valid_scheduler(char *str);
int	validate_arguments(char **argv);
void assign_arguments(char **argv, t_data *data);
int is_valid_number(char *str);


int	parse_arguments(int argc, char **argv, t_data *data)
{
	if (argc != 9)
	{
		printf("Error: expected 8 arguments\n");
		return (1);
	}
	if (!validate_arguments(argv))
		return (1);
	assign_arguments(argv, data);
	return (0);
}
static int	is_valid_scheduler(char *str)
{
	if (strcmp(str, "fifo") == 0)
		return (1);
	if (strcmp(str, "edf") == 0)
		return (1);
	printf("Error: invalid scheduler\n");
	return (0);
}

static int	validate_arguments(char **argv)
{
	if (!is_valid_scheduler(argv[8]))
		return (0);
	if (!is_valid_number(argv[1]) || !is_valid_number(argv[2]))
		return (0);
	if (!is_valid_number(argv[3]) || !is_valid_number(argv[4]))
		return (0);
	if (!is_valid_number(argv[5]) || !is_valid_number(argv[6]))
		return (0);
	if (!is_valid_number(argv[7]))
		return (0);
	return (1);
}
static int is_valid_number(char *str)
{
    int i;

    if (!str || str[0] == '\0')
        return (0);
    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    i = 0;
    while (str[i] == '0')
        i++;
    if (str[i] == '\0')
        return (0);
    return (1);
}

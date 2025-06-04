/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:39:47 by njeanbou          #+#    #+#             */
/*   Updated: 2025/06/04 16:40:56 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void clear_terminal()
{
    system("clear");
}

char    **init_array(int width, int height)
{
    char    **array = malloc(height * sizeof(char *));
    if (!array)
        return (NULL);
    for (int i = 0; i < height; ++i)
    {
        array[i] = malloc(width * sizeof(char));
        if (!array[i])
		{
			for (int j = 0; j < i; ++j)
        	    free(array[j]);
        	free(array);
        	if (!array[i])
                return (NULL);
        }
    }
	for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
			array[y][x] = ' ';
		}
    }
    return (array);
}

void    draw_initial_array(char **array, int width, int height)
{
    char c;
    int fd = 0;
    int x = 0, y = 0;
    int pen_down = 0;

    while (read(fd, &c, 1) > 0)
    {
        if (c == 'x')
            pen_down = !pen_down;
        else if (c == 'w' && y > 0)
            y--;
        else if (c == 'a' && x > 0)
            x--;
        else if (c == 's' && y <= height)
            y++;
        else if (c == 'd' && x <= width)
            x++;
        if (pen_down)
            array[y][x] = '0';
        else
            array[y][x] = ' ';
    }
}

int	count_neighbours(char **array, int y, int x, int width, int heigh)
{
	int  n = 0;
	for (int dy = -1; dy <= 1; ++dy)
	{
		for (int dx = -1; dx <= 1; ++dx)
		{
			if (dx == 0 && dy == 0)
				continue;
			int nx = x + dx;
			int ny = y + dy;
			if (nx >= 0 && nx < width && ny >= 0 && ny < heigh)
			{
				if (array[ny][nx] == '0')
					n++;
			}
		}
	}
	// printf("cell = %c, y = %d, x = %d, neighbbours = %d\n", array[y][x], y, x, n);
	return (n);
}

void	apply_rules(char **array, char **new_array, int width, int height)
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int n = count_neighbours(array, y, x, width, height);
			if (array[y][x] == ' ' && n == 3)
				new_array[y][x] = '0';
			else if (array[y][x] == '0')
			{
				if (n == 2 || n == 3)
					new_array[y][x] = '0';
				else if (n < 2)
					new_array[y][x] = ' ';
				else if (n > 3)
					new_array[y][x] = ' ';
			}
			else
				new_array[y][x] = ' ';
		}
	}
}

void    print_array(char **array, int width, int height)
{
    for (int i = 0; i < height; ++i)
    {
        for (int z = 0; z < width; ++z)
        {
			if (array[i][z] == '0')
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
        write(1, "\n", 1);
    }
}

void	simulate(char ***array, int width, int height, int iteration)
{
	char	**new_array = init_array(width, height);
	usleep(100000);
	for (int i = 0; i < iteration; ++i)
	{
		apply_rules(*array, new_array, width, height);
		char **tmp = *array;
		*array = new_array;
		new_array = tmp;
		clear_terminal();
		print_array(*array, width, height);
		usleep(100000);
	}
	for (int i = 0; i < height; ++i)
		free(new_array[i]);
	free(new_array);
}

int main(int ac, char **av)
{
	clear_terminal();
    if (ac != 4)
        return (write(2, "Wrong argument!", 14), 1);

    int width = atoi(av[1]);
    int	height = atoi(av[2]);
	int	iteration = atoi(av[3]);
    
    char    **array = init_array(width, height);
    if (!array)
        return (1);
    draw_initial_array(array, width, height);
	print_array(array, width, height);
	simulate(&array, width, height, iteration);
    
	for (int i = 0; i < height; ++i)
		free(array[i]);
	free(array);
	return (0);
}
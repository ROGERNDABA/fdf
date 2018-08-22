/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:30:39 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/22 08:31:06 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

/*
**This function takes an array and counts how many tokens ca be created in the
**int array to be created;
**
**It checks whether a chararcter is a valid character and not a space or non-
**printable and if te next one is vise versa, which guarantees a count only if
**next character is a space, well, in most these maps
*/

int		cont_count(char *line)
{
	int		count;
	int		i;

	i = -1;
	count = 0;
	while (line[++i])
	{
		if (ft_isgraph(line[i]) && !ft_isgraph(line[i + 1]))
			count++;
	}
	return (count);
}

/*
**-->  int		line_count(char *file) 1. takes the file passed as argv[1]
**2. Opens the file in read only mode and gets the file descriptor if files
**ws correctly opened
**3. Gets all the lines in the file while there are still lines
**4. Uses (i) to count everytime I read a newline and returns (i) which will
**give us information about how many line we have for correct mallocing
*/

int		line_count(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		i++;
		free(line);
	}
	return (i);
}

/*
 **---> char	**get_map(int fd, char *file)
 **1. Gets files correct file  descriptor (fd);
 **2. Gets file passed as (file) in the command line
 **3. Malloc a double pointer array which it's size is given by line count
 **function above and have each pointer point to all other pointed characters.
 **These are the individual lines by get_next_line in the next step
 **4. While get_next_line is geting valid lines from file --> av[1] while there
 **are still any lines to Created
 **5. Strdup duplicates each and every line into the pointer specified n step 3
 **6. Free each line after duplicating it after being previously malloced in GNL
 **7. Close the file after reading from it, VERY GOOD PRACTICE
 **8. Return  the double pointed array (array of arrays);
*/

char	**get_map(int fd, char *file)
{
	int		i;
	char	**map;
	char	*line;

	i = 0;
	map = (char **)malloc(sizeof(char *) * line_count(file));
	while (get_next_line(fd, &line) == 1)
	{
		map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	close(fd);
	return (map);
}

/*
**---> int		*split_tab(char *arr) just splits a string and return an int
**pointer or rather array
**1. Get the string
**2. Create an **array which will save the split string from ft_strsplit which
**kind of works like strok except it tokenizes the entire string into a double
**pointer array of chararcter pointers
**3. Create an int array to save our intergers and allocate it the size of the
**number of tokens per line in our file (remember cont_count?).
**4. go through the split array and change every token into an integer with my
**famous ft_atoi(man atoi) and saves it in my tab int array;
**5. Returns the int pointe to array tab;
*/

int		*split_tab(char *arr)
{
	int		i;
	int		*tab;
	char	**array;

	array = ft_strsplit(arr, ' ');
	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * cont_count(arr))))
		return (0);
	while (array[i])
	{
		tab[i] = ft_atoi(array[i]);
		i++;
	}
	return (tab);
}

/*
**--->  t_stuff	*tab_map(int fd, char *file)
**Noow this function takes the valid file descriptor fd and the file passed and
**a nice structure that has a 2D int pointer, line count from our file and
**token counter from our file.
**1. Get the map with get_map function above and save it to map
**2. Mallocsa a structure pointed my (m)
**3. Initialize every value to zero in the structure (VERY GOOD PRACTICE)
**4. Malloc the 2D int pointer to size of the number of our lines (len)
**5, Assignes each one of these pointers the int converted version of each line
**in map by the split_tab function above
**6. inctiments lin_len as i increases to have token sizes to lin_len
**7. Returns the pointer to the strucure
**
**HORAY, NOW THERES A 2D ARRAY OF INTS FOR BETTER SOLVING AND MANIPULATION
**PUTING PIXELS '(*._.*)'
*/

t_stuff	*tab_map(int fd, char *file)
{
	t_stuff		*m;
	char		**map;
	int			len;
	int			i;

	i = 0;
	len = (line_count(file));
	map = get_map(fd, file);
	m = (t_stuff *)malloc(sizeof(t_stuff));
	m->tab = 0;
	m->lin_len = 0;
	m->c_count = cont_count(map[0]);
	if (!(m->tab = (int **)malloc(sizeof(int *) * len)))
		return (0);
	while (i < len)
	{
		m->tab[i] = split_tab(map[i]);
		i++;
		m->lin_len = i;
	}
	return (m);
}

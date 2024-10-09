/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elallema <elallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:26:35 by elallema          #+#    #+#             */
/*   Updated: 2023/03/19 18:13:51 by elallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	i;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	while (i < 5)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	return (0);
}

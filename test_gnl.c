/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:16:58 by ski               #+#    #+#             */
/*   Updated: 2021/12/09 15:17:00 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void	test_gnl(void)
{
	int		fd;
	char	*filename = "text/text2";
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	n_read_char;
	char	*read_line;
	int		cnt_line;


	read_line = NULL;
	cnt_line = 0;

	n_read_char = 0;
	buffer[BUFFER_SIZE] = '\0';

	/* OUVERTURE DE FICHIER ------------------------------ */
	fd = sub_open_rdonly(filename);
	if (fd == -1)
		return ;

	/* GET NEXT LINE ------------------------------------- */

	read_line = get_next_line();
	cnt_line++;
	
	while (read_line != NULL)
	{
		printf("buffer: %s\n", buffer);
		free(read_line);

		read_line = get_next_line();
		cnt_line++;
	}


	if (read_line == NULL)
	{
		printf("*************************************\n");
		printf("Nothing to read more OR Error occured\n");
		printf("*************************************\n");
	}	
	
	/* FERMETURE FICHIER --------------------------------- */
	sub_close (fd);

	/* --------------------------------------------------- */	
	return ;
}

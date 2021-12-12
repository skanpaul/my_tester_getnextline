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
	char	*filename = "text/text1";
	// char	buffer[BUFFER_SIZE + 1];
	// ssize_t	n_read_char;
	char	*new;
	int		cnt_line;


	new = NULL;
	cnt_line = 0;

	// n_read_char = 0;
	// buffer[BUFFER_SIZE] = '\0';

	/* OUVERTURE DE FICHIER ------------------------------ */
	fd = sub_open_rdonly(filename);
	if (fd == -1)
		return ;

	/* GET NEXT LINE ------------------------------------- */
	while (new == NULL)
	{
		new = get_next_line(fd);
		cnt_line++;

		printf("new line: %s\n", new);
		free(new);
	}

	if (new == NULL)
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

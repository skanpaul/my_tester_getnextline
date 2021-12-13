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
	// char	*filename = "text/nl";
	char	*filename = "text/41_no_nl";
	// char	*filename = "text/text8";
	char	*new;
	int		cnt_line;

	new = NULL;
	cnt_line = 0;
	/* OUVERTURE DE FICHIER ------------------------------ */
	fd = sub_open_rdonly(filename);
	if (fd == -1)
		return ;
	/* GET NEXT LINE ------------------------------------- */
	
	new = get_next_line(fd);  // ICI ICI ICI ICI ICI 
	cnt_line++;
	while (new != NULL)
	{
		printf("Line [%d]:\n", cnt_line);
		ft_print_getnextline(new);

		printf("\n");
		free(new);
		new = get_next_line(fd); // ICI ICI ICI ICI ICI 
		cnt_line++;
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

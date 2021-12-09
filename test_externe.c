/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_externe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:16:43 by ski               #+#    #+#             */
/*   Updated: 2021/12/09 15:16:46 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"
/* ************************************************************************** */
void	test_externe(void)
{
	int		fd;
	char	*file = "text/text1";
	char	buffer[BUFFER_SIZE + 1];

	ssize_t	n_read_char;

	n_read_char = 0;

	/* --------------------------------------------------- */
	printf("\nBUFFER_SIZE: %d\n\n", BUFFER_SIZE);
	/* --------------------------------------------------- */
	/* OUVERTURE DE FICHIER ------------------------------ */
	/* --------------------------------------------------- */
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Open file: !!! FAILED !!!\n");		
		return ;
	}
	else
	{
		printf("Open file: SUCCEED | File descriptor: %d\n", fd);
	}
	/* --------------------------------------------------- */
	/* LECTURE DE FICHIER -------------------------------- */
	/* --------------------------------------------------- */
	n_read_char = read(fd, buffer, BUFFER_SIZE);
	if (n_read_char == -1)
	{
		printf("Read file: !!! FAILED !!!\n");
		return ;
	}
	if (n_read_char == 0)
		printf("Read file: HAS REACHED END OF FILE\n");
	else
		printf("Read file: %zd characters read\n", n_read_char);
	sk_printmem((void*)buffer, BUFFER_SIZE);
	/* --------------------------------------------------- */
	n_read_char = read(fd, buffer, BUFFER_SIZE);
	if (n_read_char == -1)
	{
		printf("Read file: !!! FAILED !!!\n");
		return ;
	}
	if (n_read_char == 0)
		printf("Read file: HAS REACHED END OF FILE\n");
	else
		printf("Read file: %zd characters read\n", n_read_char);
	sk_printmem((void*)buffer, BUFFER_SIZE);
	/* --------------------------------------------------- */
	n_read_char = read(fd, buffer, BUFFER_SIZE);
	if (n_read_char == -1)
	{
		printf("Read file: !!! FAILED !!!\n");
		return ;
	}
	if (n_read_char == 0)
		printf("Read file: HAS REACHED END OF FILE\n");
	else
		printf("Read file: %zd characters read\n", n_read_char);
	sk_printmem((void*)buffer, BUFFER_SIZE);
	/* --------------------------------------------------- */


	if(close(fd) == 0)
		printf("Close file: Succeed\n");
	else
		printf("Close file: !!! FAILED !!!\n");

	
	return ;
}

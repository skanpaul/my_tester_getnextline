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
	char	*filename = "text/text2";
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	n_read_char;

	n_read_char = 0;
	/* OUVERTURE DE FICHIER ------------------------------ */
	fd = sub_open_rdonly(filename);
	if (fd == -1)
		return ;
	/* LECTURE DE FICHIER -------------------------------- */
	n_read_char = sub_read(fd, buffer, BUFFER_SIZE);
	if (n_read_char != -1)
	{
		while (n_read_char != 0)
		{
			// sk_printmem((void*)buffer, BUFFER_SIZE);
			n_read_char = sub_read(fd, (void*)buffer, BUFFER_SIZE);
		}	
	}
	/* FERMETURE FICHIER --------------------------------- */
	sub_close (fd);
	/* --------------------------------------------------- */
	return ;
}

/* ************************************************************************** */
int sub_open_rdonly(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	/* --------------------------------------------------- */
	if (fd == -1)
		printf("Open file: !!! FAILED !!!\n");		
	/* --------------------------------------------------- */
	printf("\n");
	printf("***********************************\n");
	printf("Open [%s]: SUCCEED\n", filename);
	printf("File descriptor: %d | BUFFER_SIZE: %d\n", fd, BUFFER_SIZE);
	printf("***********************************\n");
	printf("\n");
	return (fd);
}
/* ************************************************************************** */
int sub_read(int fd, void *buffer, int buf_size)
{
	ssize_t n_read_char;

	n_read_char = read(fd, buffer, buf_size);
	if (n_read_char == -1)
	{
		printf("Read file: !!! FAILED !!!\n");
		sub_close (fd);
		return (n_read_char);
	}
	printf("Read file: %zd characters read\n", n_read_char);
	if (n_read_char == 0)
	{
		printf("\n");
		printf("**********************************\n");
		printf("Read file: HAS REACHED END OF FILE\n");
		printf("**********************************\n");
		printf("\n");
	}
	return (n_read_char);
}
/* ************************************************************************** */
int sub_close (int fd)
 {
	int result;

	result = close(fd);
	if(result == 0)
		printf("Close file: Succeed\n");
	else
		printf("Close file: !!! FAILED !!!\n");
	 return (result);
 }
/* ************************************************************************** */

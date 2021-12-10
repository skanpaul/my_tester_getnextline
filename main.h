/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:09:13 by ski               #+#    #+#             */
/*   Updated: 2021/12/06 18:09:17 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAIN_H
# define MAIN_H
/* ************************************************************************** */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
/* -------------------------------------------------------------------------- */
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
/* -------------------------------------------------------------------------- */
# include "../getnextline/get_next_line.h"
# include "libft/libft.h"
# include "sk_lib.h"

/* -------------------------------------------------------------------------- */
void	test_externe(void);
void	test_gnl(void);
void	sk_printmem(void *ptr, size_t size);
/* -------------------------------------------------------------------------- */
int		sub_read(int fd, void *buffer, int buf_size);
int		sub_close (int fd);
int		sub_open_rdonly(char *filename);
/* ************************************************************************** */
# endif

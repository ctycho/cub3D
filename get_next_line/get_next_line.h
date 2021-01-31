/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:56:13 by ctycho            #+#    #+#             */
/*   Updated: 2021/01/31 20:59:59 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

int			get_next_line(int fd, char **line);
char		*strdup_till_null(char *s);
size_t		ft_strlen_1(const char *s);
char		*ft_join_str(char *s1, char *s2);
char		*find_null(char *remainder);
int			check_end(char *s);

#endif

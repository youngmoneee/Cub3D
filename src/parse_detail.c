/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:33:09 by youngpar          #+#    #+#             */
/*   Updated: 2022/05/28 21:45:36 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/structure.h"
#include "../inc/parse.h"
#include "../inc/util.h"
#include "../libft/libft.h"

bool	all_parsed(t_parse *parse)
{
	uint	i;
	bool	ret;

	i = -1;
	ret = true;
	while (++i)
		ret &= parse->opt[i].parsed;
	return (ret);
}

bool	all_valid(t_parse *parse)
{
	uint	i;
	bool	ret;

	i = -1;
	ret = true;
	while (++i)
		ret &= parse->opt[i].parsed;
	return (ret);
}

void	set_color(char *line, t_option *opt)
{
	t_option	*op;

	if (*line == 'C')
		op = &opt[CEIL];
	else
		op = &opt[FLOOR];
	if (op->parsed)
	{
		op->valided = false;
		return ;
	}
	op->parsed = true;
	if (*(++line) != ' ')
	{
		op->valided = false;
		return;
	}
	atocolor(line, 16, op);
}

void	atocolor(char *str, int pos, t_option *opt)
{
	int		uc;

	if (pos < 0)
		return ;
	uc = 0;
	while (*str == ' ')
		str++;
	while (ft_isdigit(*str))
	{
		uc = uc * 10 + *str++ - '0';
		if (uc > 255)
			return ;
	}
	opt->color |= (uc << pos);
	while (ft_isspace(*str))
		str++;
	if (!pos && !*str)
	{
		opt->valided = true;
		return;
	}
	else if (*str == ',')
		atocolor(str + 1, pos - 8, opt);
}

static t_options	set_opt(char *line)
{
	if (!ft_strncmp(line, "NO", 3))
		return (NORTH);
	else if (!ft_strncmp(line, "SO", 3))
		return (SOUTH);
	else if (!ft_strncmp(line, "WE", 3))
		return (WEST);
	else if (!ft_strncmp(line, "EA", 3))
		return (EAST);
	return (UNKNOWN);
}

void	set_path(char *line, t_option *opt)
{
	uint	sz;
	uint	idx;
	char	**arg;

	arg = ft_split(line, ' ');
	sz = 0;
	while (arg[sz])
		sz++;
	if (sz != 2 || (set_opt(arg[0]) == UNKNOWN))
		exit_msg("Wrong Identity");
	idx = set_opt(arg[0]);
	if (opt[idx].parsed)
		exit_msg("Redefined Resource Path");
	opt[idx].parsed = true;
	opt[idx].fd = open(arg[1], O_RDONLY);
	if (opt[idx].fd < 0)
		exit_msg("Open Failed");
	while (--sz >= 0)
		free(arg[sz]);
	free(arg);
	opt[idx].valided = true;
}

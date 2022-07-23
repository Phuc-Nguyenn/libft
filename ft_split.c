/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:57:24 by phunguye          #+#    #+#             */
/*   Updated: 2022/03/20 10:57:52 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <string.h>
//#include <stdlib.h>

size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

void	*memalloc(char const*s, char c)
{
	void	*lst;

	if (!s)
		return (NULL);
	lst = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	return (lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = memalloc(s, c);
	if (!lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}

//================
/*
int	ft_wordcount(char const *s, char c)
{
	int	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	*ft_worddup(char const *s, char c, int wordindex)
{
	char	*str;
	int		len;
	int		word_at;
	int		i;
	int		word_i;

	i = -1;
	word_at = 1;
	while (s[++i] && word_at < wordindex)
	{
		while (s[i] == c)
			i++;
		if (s[i])
			word_at++;
		while (s[i] != c && s[i])
			i++;
	}
	word_i = i;
	len = 1;
	while (s[i++] != c)
		len++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[word_i] != c)
		str[i++] = s[word_i++];
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		wordcount;
	int		wordindex;
	char	**str;

	wordcount = ft_wordcount(s, c);
	str = malloc(wordcount * sizeof(char *) + 1);
	if (!str)
		return (NULL);
	i = 0;
	wordindex = 1;
	while (i < wordcount)
		str[i++] = ft_worddup(s, c, wordindex++);
	str[i] = 0;
	return (str);
}*/
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "   Split    this   string  into 
	separate strings lol please and thankyou. lmao XD";
	char	**s = ft_split(str, ' ');
	int		i;

	i = 0;
	while (s[i] != 0)
		printf("%s\n", s[i++]);
	return (0);
}*/
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 13:23:57 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 23:29:16 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct              s_flag
{
    //unsigned int            percent;
    unsigned int            hashtag;
    unsigned int            zero;
    unsigned int            plus;
    unsigned int            minus;
    unsigned int            point;
    unsigned int            space;
    unsigned int            width;
    unsigned int            _l;
    unsigned int            _h;
    unsigned int            _L;
	unsigned int			precision;
	char					conv;
}                           t_flag;

typedef struct              s_out
{
    int                     integ;
    unsigned long long      yessai;
    char                    *string;
    unsigned char           uns_char;
    unsigned int            uns_integ;
    long                    lo;
    long double             lo_double;
    short int               sh_int;
    void                    *void_pointer;
    double                  doub;
    int                     precis;
    long long               ld;
    unsigned long           o;
}                           t_out;

typedef struct				s_compt
{
	int		i;
	int		j;
	int		k;
	int		m;
	char	*num;
	char	*num2;
}							t_compt;

typedef struct              s_count
{
    int                     i;
    int                     j;
}                           t_count;

/*
**	nsm.c
*/
int							parse(char *str, va_list ap);
int                         ft_printf(const char *format, ...);
int                         resolve_option(char *str, va_list ap, t_flag flag, int nb_char);
void                        print_help(t_flag flag, int nb_char);
void	                    ft_putncaract(char c, int size);
void	                    ft_putnstr(char const *s, int size);

/*
**	util.c
*/
char						*ft_itoa_base(int value, int base);
int							ft_atoi_2(char const *str);
char						*ft_strcaps(char *str);
int							ft_pow(int nb, int pow);
int                         ft_putchar_add(char c);
int							ft_putchar_add(char c);

/*
**	ft_choose_resolve.c
*/
int			ft_choose_resolve1(t_out out, va_list ap, t_flag flag, int nb_char);
int			ft_choose_resolve2(t_out out, va_list ap, t_flag flag, char *nbr);

/*
**	wp_streat
*/
int							wp_streat(t_flag flag, char *string);

/*
**	wp_ftreat
*/
int							wp_ftreat(t_flag flag, double nb);
long double					ft_pow10(long double f, int exp);


/*
**	wp_utreat
*/
int							wp_utreat(t_flag flag, long long dig);

/*
**	wp_otreat
*/
int							wp_otreat(t_flag flag, long long dig);

/*
**	wp_dtreat
*/
int         				is_minus(char *len);
int							wp_dtreat(t_flag flag, long long dig);

/*
**	wp_oxtreat
*/
int							wp_oxtreat(t_flag flag, long long dig);

/*
**	jsp
*/
int                         wp_ctreat(t_flag flag, int size, int c);
int                         choose_dig(t_flag flag, int nb_char, va_list ap, t_out out);
int		                    choose_xo(t_flag flag, va_list ap, int nb_char, t_out out);
char	                    *nbr_dig(long long dig, t_flag flag, char *str);
char                        *nbr_digox(long long dig, t_flag flag, char *str);
char                        *ft_uhhtoa_base(unsigned short value, int base);
char                        *ft_ulltoa_base(unsigned long long value, int base);
char                        *ft_utoa_base(unsigned int value, int base);
char	                    *dectohexa(unsigned long long n, t_flag flags);
char	                    *octa_zero(char *seg);
int		                    ret_int(unsigned long long n, int base);
char	                    *cut_str_long(char *seg, t_flag flags);
char	                    *dectoocta(unsigned long n, t_flag flags);
// penser a passer en static les fonctions qui sont utilisees dans un unique fichier

#endif
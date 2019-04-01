/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:07:27 by ashanbha          #+#    #+#             */
/*   Updated: 2019/03/29 09:19:55 by ashanbha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_v
{
	char			*format;
	int				fd;
	va_list			ap;
	int				gv;
	int				flag_hash;
	int				flag_space;
	int				flag_minus;
	int				flag_plus;
	int				flag_zero;
	int				flag_neg;
	int				f_width;
	int				c_width;
	int				h_fl;
	int				hh_fl;
	int				l_fl;
	int				ll_fl;
	int				lc_fl;
	int				f_prec;
	int				c_prec;
	char			hexadecinum[16];
	int				c_i;
	int				hex_o;
	int				hex_rem;
	int				int_fl;
	int				oct_fl;
	int				flt_fl;
	int				m_fl;
	int				u_fl;
	int				x_s;
	int				x_l;
	int				a;
}					t_v;

int					ft_printf(const char *format, ...);
int					ft_fdprintf(int fd, const char *format, ...);
void				figure_stuff(t_v *v);
void				buffadd(t_v *v);
int					ft_atoi(const char *str);
void				*ft_bzero(void *s, size_t n);
int					ft_strlen(char *str);
int					ft_strlenc(char *str, char c);
void				figure_colors(t_v *v);
void				buffadd_string(t_v *v, char *str);
void				figure_not_color(t_v *v);
int					ft_strncmpcolor(const char *col1, const char *col2);
void				figure_actual_color(t_v *v, char *color);
void				figure_flags(t_v *v);
void				flags(t_v *v);
void				h_flag(t_v *v);
void				hh_flag(t_v *v);
void				l_flag(t_v *v);
void				ll_flag(t_v *v);
void				lc_flag(t_v *v);
void				no_flag(t_v *v);
void				ht_flag(t_v *v);
void				pl_flag(t_v *v);
void				min_flag(t_v *v);
void				sp_flag(t_v *v);
void				z_flag(t_v *v);
void				a_flag(t_v *v);
void				figure_width(t_v *v);
void				figure_precision(t_v *v);
void				print_char(t_v *v, char str);
void				print_perc(t_v *v);
void				char_space(t_v *v);
void				reset_flags(t_v *v);
void				width_m_prec(t_v *v);
void				width_m_prec2(t_v *v);
void				width_m_prec3(t_v *v);
void				spz_width(t_v *v);
void				spz_prec(t_v *v);
void				lwidth_m_digm1(t_v *v, long long i);
void				lwidth_m_dig0(t_v *v, long long i);
void				lwidth_m_dig1(t_v *v, long long i);
void				lwidth_m_dig2(t_v *v, long long i);
void				lwidth_m_dig4(t_v *v, long long i);
void				cprec_m_dig0(t_v *v, long long i);
void				int_help1(t_v *v, long long i);
void				int_help2(t_v *v, long long i);
void				int_help3(t_v *v, long long i);
void				int_help4(t_v *v, long long i);
void				int_help5(t_v *v, long long i);
void				int_help6(t_v *v, long long i);
void				int_help7(t_v *v, long long i);
void				int_help8(t_v *v, long long i);
void				int_help9(t_v *v);
void				int_help10(t_v *v);
void				int_help11(t_v *v, long long i);
void				int_help12(t_v *v, long long i);
void				int_help13(t_v *v, long long i);
void				int_help14(t_v *v, long long i);
void				int_help15(t_v *v, long long i);
void				int_help16(t_v *v, long long i);
void				int_help17(t_v *v, long long i);
void				int_help18(t_v *v, long long i);
void				oct_help1(t_v *v, long long i);
void				oct_help2(t_v *v, long long i);
void				oct_help3(t_v *v, long long i);
void				oct_help4(t_v *v, long long i);
void				oct_help5(t_v *v, long long i);
void				oct_help6(t_v *v, long long i);
void				oct_help7(t_v *v, long long i);
void				oct_help8(t_v *v, long long i);
void				oct_help9(t_v *v, long long i);
void				oct_help10(t_v *v, long long i);
void				oct_help11(t_v *v, long long i);
void				oct_help12(t_v *v, long long i);
void				oct_help13(t_v *v, long long i);
void				oct_help14(t_v *v, long long i);
void				oct_help15(t_v *v, long long i);
void				oct_help16(t_v *v, long long i);
void				oct_help17(t_v *v, long long i);
void				oct_help18(t_v *v, long long i);
void				hex_help1(t_v *v, unsigned long long i);
void				hex_help2(t_v *v, unsigned long long i);
void				hex_help3(t_v *v, unsigned long long i);
void				hex_help4(t_v *v, unsigned long long i);
void				hex_help5(t_v *v, unsigned long long i);
void				hex_help6(t_v *v, unsigned long long i);
void				hex_help7(t_v *v, unsigned long long i);
void				hex_help8(t_v *v, unsigned long long i);
void				hex_help9(t_v *v, unsigned long long i);
void				hex_help10(t_v *v, unsigned long long i);
void				hex_help11(t_v *v, unsigned long long i);
void				hex_help12(t_v *v, unsigned long long i);
void				hex_help13(t_v *v, unsigned long long i);
void				hex_help14(t_v *v, unsigned long long i);
void				hex_help15(t_v *v, unsigned long long i);
void				u_help1(t_v *v, unsigned long long i);
void				u_help2(t_v *v, unsigned long long i);
void				u_help3(t_v *v, unsigned long long i);
void				u_help4(t_v *v, unsigned long long i);
void				u_help5(t_v *v, unsigned long long i);
void				flt_help1(t_v *v, long double i);
void				flt_help2(t_v *v, long double i);
void				flt_help3(t_v *v, long double i);
void				flt_help4(t_v *v, long double i);
void				flt_help5(t_v *v, long double i);
void				flt_help6(t_v *v, long double i);
void				flt_help7(t_v *v, long double i);
void				flt_help8(t_v *v, long double i);
void				flt_help9(t_v *v, long double i);
void				flt_help10(t_v *v, long double i);
void				flt_help11(t_v *v, long double i);
void				flt_help12(t_v *v, long double i);
void				flt_help13(t_v *v, long double i);
void				flt_help14(t_v *v, long double i);
void				flt_help15(t_v *v, long double i);
void				flt_help16(t_v *v, long double i);
void				print_s(t_v *v, char *str);
void				print_strspace(t_v *v, char *str);
void				print_strchar(t_v *v, char *str);
void				s_help1(t_v *v, char *str);
void				s_help2(t_v *v, char *str);
void				s_help3(t_v *v, char *str);
void				print_int(t_v *v, long long i);
void				print_u(t_v *v, unsigned long long i);
void				print_o(t_v *v, unsigned long long i);
void				print_x(t_v *v, unsigned long long i, int j);
void				print_flt(t_v *v, long double i);
char				*ft_strdup(const char *s1);
void				itoa_isnegative(int *n, int *negative);
char				*ft_itoa(int n);
char				*ft_itoa_u(unsigned int n);
char				*ft_itoa_base(int value, int base, char up);
void				lltoa_isnegative(long long *n, int *negative);
void				addstrtobuff(t_v *v, char *str, int limit);
char				*ft_lltoa(long long n);
char				*ft_lltoa_u(unsigned long long n);
char				*ft_lltoa_base(unsigned long value, int base, char up);
void				print_p(t_v *v);
char				*ft_strjoin(char *s1, char *s2);
void				*ft_memalloc(size_t size);
char				*ft_ldtoa(long double n);
char				*dec_to_hexa(t_v *v, unsigned long long n, char str);
char				*dec_to_hexa_prp(t_v *v);
char				*dec_to_hexa_e(char *hex, char *hexi_deci_num, int i);
int					num_digit(long long i);
int					num_float(long double i);
int					flt_decp(long double i);
int					ft_min(int x, int y);
char				*bdecp(long double i);
char				*adecp(long double i);
char				*potato_supreme(long double n, char *first, int neg);
char				*mighty_potato(long double n, char *first, size_t len,
		int neg);
char				*low_carb_potato(long double n, int neg);
char				*confident_potato(char *str, char *first, size_t len,
		int neg);
long double			potato_magic(long double n, char *first, size_t len);
char				*self_conscious_potato(char *str, int i);
char				*round_potato(long double n);
char				*insert_c(char *s1, char c, unsigned long long n);
char				*replace_c(char *s1, char c, unsigned long long n);
long double			ft_pow(long double base, long double ex);
char				*str_chop(char *str, int n);
char				*str_chop2(char *str, int n);
int					ft_max(int a, int b);

# define MAX_COLOR_SIZE	7
# define COL_BLACK		"\e[0;30m"
# define COL_RED		"\e[0;31m"
# define COL_GREEN		"\e[0;32m"
# define COL_YELLOW		"\e[0;33m"
# define COL_BLUE		"\e[0;34m"
# define COL_PURPLE		"\e[0;35m"
# define COL_CYAN		"\e[0;36m"
# define COL_WHITE		"\e[0;37m"
# define COL_RESET		"\e[0m"
#endif

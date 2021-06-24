#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int				minus;
	int				zero;
	int				point;
	unsigned int	type;
	int				star;
	int				width;
	int				len_word;
	int				pointer;
}				t_flags;

int				ft_type(int c);
int				ft_proverka_flags(int c);
int				ft_processor(int c, t_flags *flags, va_list args);
void			ft_init_flags(t_flags *flags);
int				ft_treat_save(const char *save, va_list args, t_flags *flags);
int				ft_printf(const char *input, ...);
void			zeroing_without_len_word(t_flags *flags);
int				ft_treat_string(char *str, t_flags *flags);
t_flags			ft_flag_digit(char c, t_flags flags);
void			ft_flag_digit_width(int c, t_flags *flags);
int				ft_flag_width(int width, int minus, int zero, t_flags *flags);
t_flags			ft_flag_minus(t_flags flags);
int				ft_flag_null(const char *save, int start, \
t_flags *flags, va_list args);
void			ft_flag_width_minus(int width, int minus, \
int zero, t_flags *flags);
int				ft_flag_parse(const char *save, int i, \
t_flags *flags, va_list args);
int				ft_isdigit(int c);
char			*ft_strdup(const char *s1);
int				ft_putint_fd(int c);
void			ft_putstr_fd(char *s, t_flags *flags);
char			*ft_strrev(char *str);
int				ft_strlen_two(char *s);
void			ft_putchar_fd(char c, t_flags *flags);
t_flags			ft_flag_digit_point(int c, t_flags flags);
int				ft_putstr(char s);
int				ft_lennbr(long i);
int				ft_lennbr_unsigned(unsigned int i);
int				hexa_dis(unsigned int n);
void			hexa_dis_sys(unsigned int n, t_flags *flags);
int				ft_treat_hexa_X(unsigned int h, t_flags *flags);
int				ft_treat_hexa(unsigned int h, t_flags *flags, int len);
int				ft_treat_char(char i, t_flags *flags);
int				ft_putnbr_minus(long n, t_flags *flags);
int				ft_treat_int(long i, t_flags *flags, int len);
int				ft_proc_pnt(unsigned long long h, t_flags *flags, int len);
void			point_d_i(long h, t_flags *flags, int len);
void			ft_putnbr_fd(long n, t_flags *flags);
void			w_p_h_d(long h, t_flags *flags);
void			width_d(long h, t_flags *flags, int len);
int				w_h_pointer(long h, t_flags *flags, int len);
void			point_d(long h, t_flags *flags, int len);
int				w_p_d_i(long h, t_flags *flags, int len);
int				w_p_d(long h, t_flags *flags, int len);
void			minus_d(long h, t_flags *flags, int len);
void			p_m_d(long h, t_flags *flags, int len);
void			m_w_h_pointer(long h, t_flags *flags, int len);
int				m_w_p_d(long h, t_flags *flags, int len);
int				ft_lennbr_uint(unsigned int i);
int				ft_putnbr_minus_uint(unsigned int n, t_flags *flags);
void			ft_putnbr_uint(unsigned int n, t_flags *flags);
void			w_uint(unsigned int h, t_flags *flags, int len);
int				w_h_pointer_uint(unsigned int h, t_flags *flags, int len);
void			point_uint(unsigned int h, t_flags *flags, int len);
void			minus_uint(unsigned int h, t_flags *flags, int len);
void			p_m_uint(unsigned int h, t_flags *flags, int len);
void			m_w_uint(unsigned int h, t_flags *flags, int len);
void			m_w_h_pointer_uint(unsigned int h, t_flags *flags);
void			point_m_uint(unsigned int h, t_flags *flags, int len);
int				w_p_uint(unsigned int h, t_flags *flags, int len);
int				m_w_p_uint(unsigned int h, t_flags *flags, int len);
int				ft_treat_percent(int h, t_flags *flags);
int				width_point_h(unsigned int h, int len, t_flags *flags);
int				point_minus(unsigned int h, int len, t_flags *flags);
int				point(unsigned int h, int len, t_flags *flags);
int				minus_width_point(unsigned int h, int len, t_flags *flags);
int				minus_width_h_pointer(unsigned int h, int len, t_flags *flags);
int				width_minus(unsigned int h, int len, t_flags *flags);
int				width(unsigned int h, int len, t_flags *flags);
int				width_point(unsigned int h, int len, t_flags *flags);
int				minus(unsigned int h, int len, t_flags *flags);
int				minus_width_h(unsigned int h, int len, t_flags *flags);
char			*ft_count(unsigned long long nb);
int				ft_chet(unsigned long long nb);
void			width_pointer_h(unsigned long long h, int len, t_flags *flags);
void			minus_width_h_pointer_pnt(unsigned long long h, \
int len, t_flags *flags);
void			ft_count_putstr(char *dest, unsigned long long h, \
t_flags *flags);
void			width_pnt(char *dest, unsigned long long h, \
int len, t_flags *flags);
void			minus_width_pnt(char *dest, unsigned long long h, \
int len, t_flags *flags);
void			width_h_pnt(unsigned long long h, int len, t_flags *flags);
void			width_point_pnt( int len, t_flags *flags);
void			minus_width_pointer_pnt(unsigned long long h, t_flags *flags);
void			ft_proc_pnt_two(unsigned long long h, int len, \
t_flags 		*flags, char *dest);
void			minus_width_pointer_pnt(unsigned long long h, t_flags *flags);
void			point_pnt(unsigned long long h, int len, t_flags *flags);
void			width_point_pnt_if(unsigned long long h, int len, \
char			*dest, t_flags *flags);
void			nominus_nowidth_nopointer_h(t_flags *flags);
void			hexa_dis_sys_X(unsigned int n, t_flags *flags);
void			point_minus_X(unsigned int h, t_flags *flags, int len);
void			width_point_h_X(unsigned int h, t_flags *flags, int len);
void			minus_width_h_pointer_X(unsigned int h, \
t_flags *flags, int len);
int				minus_width_point_X(unsigned int h, t_flags *flags, int len);
void			minus_width_h_X(unsigned int h, t_flags *flags, int len);
void			width_X(unsigned int h, t_flags *flags, int len);
void			h_width_pointer(unsigned int h, t_flags *flags);
void			minus_X(unsigned int h, t_flags *flags, int len);
int				cshet_ret(char *str, t_flags *flags, int len);
void			p_l_str(t_flags *flags, int len);
void			ft_cshet(char *str, t_flags *flags, int len);
void			p_w_w_str(char *str, t_flags *flags, int len);
int				p_pointer_w_p_m_w_str(char *str, t_flags *flags, int len);
void			p_w_str(char *str, t_flags *flags, int len);
void			m_p_w_str(char *str, t_flags *flags, int len);
int				str_m_w_p(char *str, t_flags *flags, int len);
int				p_pointer_w_m_z_str(char *str, t_flags *flags, int len);
void			str_w_m_p(char *str, t_flags *flags, int len);
void			w_str_p(char *str, t_flags *flags, int len);
void			p_pointer_now_nom_noz_str(char *str, t_flags *flags, int len);
int				w_pointer_nop_m(t_flags *flags);
unsigned int	ft_treat_uint(unsigned int h, t_flags *flags, int len);
#endif
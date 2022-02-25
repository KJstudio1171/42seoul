`int		ft_isalpha(int c);`

알파벳인지 검사

`int		ft_isdigit(int c);`

숫자인지 검사

`int		ft_isalnum(int c);`

숫자 또는 알파벳인지 검사

`int		ft_isascii(int c);`

0 ~ 127사이의 문자인지 검사

`int		ft_isprint(int c);`

프린트 가능한 문자인지 검사

`size_t	ft_strlen(const char *str);`

문자열의 길이

`void	*ft_memset(void *ptr, int value, size_t num);`

ptr을 num개의 value로 set

`void	*ft_bzero(void *ptr, size_t num);`

ptr을 num개의 0으로 set

`void	*ft_memcpy(void *dest, const void *source, size_t num);`

dest에 num개의 source를 copy(복사시 메모리가 겹칠 수 있다.)

`void	*ft_memmove(void *dest, const void *src, size_t num);`

메모리가 겹치지 않는 memcpy

`size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);`

NULL문자를 포함한 크기인 dstsize만큼의 src를 복사

`size_t	ft_strlcat(char *dst, const char *src, size_t size);`

총합의 크기가 NULL문자를 포함한 크기인 size가 되도록 src를 dst뒤에 복사

`int		ft_strncmp(const char *str1, const char *str2, size_t n);`

두 문자열을 비교해서 같으면 0 아니면 다른 문자의 차를 반환

`int		ft_toupper(int c);`

문자를 대문자로 변환

`int		ft_tolower(int c);`

문자를 소문자로 변환

`char	*ft_strchr(const char *str, int c);`

문자열에서 문자를 찾아 그 위치의 포인터 반환

`char	*ft_strrchr(const char *str, int c);`

strchr의 리버스 방향

`void	*ft_memchr(const void *ptr, int value, size_t num);`

ptr의 num까지 길이중에서 value를 찾아 그 위치를 반환

`int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)`;

ptr1과 ptr2를 비교해서 다르면 차이를 반환, 같으면 0을 반환

`char	*ft_strnstr(const char *big, const char *little, size_t len);`
big의 len길이중에서 little을 찾아서 그위치를 반환 없으면 NULL반환

`int		ft_atoi(const char *nptr);`

문자열 숫자를 int형 숫자로 반환

`void	*ft_calloc(size_t n, size_t size);`

메모리를 할당하고 0으로 초기화

`char	*ft_strdup(const char *src);`

문자열 src를 복사한 메모리를 할당하고 반환


`char	*ft_substr(char const *s, unsigned int start, size_t len);`

start부터 len길이만큼의 문자열을 복사한 메모리를 할당하고 반환


`char	*ft_strjoin(char const *s1, char const *s2);`

s1과 s2를 연결한 문자열을 복사한 메모리를 할당하고 반환

`char	*ft_strtrim(char const *s1, char const *set);`

set문자열에 들어있는 문자를 문자열의 앞뒤에서 제거한 문자열을 복사한 메모리를 할당하고 반환


`char	**ft_split(char const *s, char c);`

문자열을 문자c를 기준으로 나누어 각각의 포인터를 담은 배열을 반환

`char	*ft_itoa(int n);`

int형 숫자를 문자열 숫자로 반환

`char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));`

index와 문자열 s의 문자를 하나씩 순차적으로 함수f에 적용한 결과값을 복사한 메모리를 할당하고 반환 


`void	ft_striteri(char *s, void (*f)(unsigned int, char *));`
index와 문자열 s의 문자를 하나씩 순차적으로 함수f에 적용


`void	ft_putchar_fd(char c, int fd);`

fd에 문자c를 기록

`void	ft_putstr_fd(char *s, int fd);`

fd에 문자열s를 기록

`void	ft_putendl_fd(char *s, int fd);`

fd에 문자열s를 기록한다음에 개행


`void	ft_putnbr_fd(int n, int fd);`

fd에 숫자n을 기록

`t_list	*ft_lstnew(void *content);`

링크드 리스트 생성

`void	ft_lstadd_front(t_list **lst, t_list *new);`

링크드 리스트 앞에 리스트 추가

`int		ft_lstsize(t_list *lst);`

링크드 리스트의 전체 크기 측정

`t_list	*ft_lstlast(t_list *lst);`

링크드 리스트의 마지막 리스트 반환


`void	ft_lstadd_back(t_list **lst, t_list *new);`

링크드 리스트의 마지막에 리스트 추가

`void	ft_lstdelone(t_list *lst, void (*del)(void *));`

리스트 lst에 del함수를 적용하고 메모리 해제

`void	ft_lstclear(t_list **lst, void (*del)(void *));`

리스트전체에 lstdelone적용

`void	ft_lstiter(t_list *lst, void (*f)(void *));`

리스트 전체에 함수f적용

`t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));`

리스트 전체에 f를 적용한 리스트를 할당하고 반환
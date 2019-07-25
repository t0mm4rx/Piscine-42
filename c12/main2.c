#include "ex00/ft_list.h"
#include "ex04/ft_list_push_back.c"
#include "ex05/ft_list_push_strs.c"
#include "ex08/ft_list_reverse.c"
#include "ex12/ft_list_remove_if.c"
#include "ex13/ft_list_merge.c"
#include "ex15/ft_list_reverse_fun.c"
#include "ex16/ft_sorted_list_insert.c"
#include "ex17/ft_sorted_list_merge.c"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list *res;

	res = 0;
	if ((res = malloc(sizeof(t_list))))
	{
		res->data = data;
		res->next = 0;
	}
	return (res);
}

void ft_print_list(t_list *list)
{
	while(list)
	{
		printf("%s", (char *)list->data);
		printf(" -> ");
		list = list->next;
	}
	printf("NULL\n");
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	free_ftc(void *data)
{
	(void)data;
}

int		main(void)
{
	printf("Test exo04\n");
	t_list *list1;
	list1 = 0;
	ft_list_push_back(&list1, "bip");
	ft_list_push_back(&list1, "pouet");
	ft_list_push_back(&list1, "salut");
	ft_print_list(list1);

	printf("Test ex05\n");
	char *a[] = {"test", "test2", "test3"};
	t_list *list2 = ft_list_push_strs(3, a);
	ft_print_list(list2);

	printf("Test exo08\n");
	ft_list_reverse(&list2);
	ft_print_list(list2);

	printf("Test ex12\n");
	char *c[] = {"Test1", "Test2", "Test3"};
	t_list *tab = ft_list_push_strs(3, c);
	ft_list_remove_if(&tab, "Test1", &ft_strcmp, &free_ftc);
	ft_print_list(tab);

	printf("Test ex13\n");
	ft_list_merge(&list1, list2);
	ft_print_list(list1);

	printf("Test ex15\n");
	ft_list_reverse_fun(list1);
	ft_print_list(list1);

	printf("Test ex16\n");
	ft_sorted_list_insert(&list1, "btestttt", &ft_strcmp);
	ft_print_list(list1);

	printf("Test ex17\n");
	char *b[] = {"a", "b", "ta", "ok"};
	t_list *list3 = ft_list_push_strs(4, b);
	ft_sorted_list_merge(&list1, list3, &ft_strcmp);
	ft_print_list(list1);

	return (0);
}
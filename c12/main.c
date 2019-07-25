#include "ex00/ft_list.h"
#include "ex00/ft_create_elem.c"
#include "ex01/ft_list_push_front.c"
#include "ex02/ft_list_size.c"
#include "ex03/ft_list_last.c"
#include "ex04/ft_list_push_back.c"
#include "ex05/ft_list_push_strs.c"
#include "ex06/ft_list_clear.c"
#include "ex07/ft_list_at.c"
#include "ex08/ft_list_reverse.c"
#include "ex09/ft_list_foreach.c"
#include "ex12/ft_list_remove_if.c"
#include "ex13/ft_list_merge.c"
#include "ex14/ft_list_sort.c"
#include <stdio.h>

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

void	handle_data(void *data)
{
	printf("%s\n", (char*)data);
}

int		remove_p(char *d1, char *d2)
{
	(void)d2;
	return (!(d1[0] == 'p'));
}

void	free_list(void *el)
{
	(void)el;
}

int		cmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int main()
{
	t_list *list;
	t_list *list2;
	t_list *list3;

	printf("* test creation tableau:\n");
	list = ft_create_elem("premier");
	ft_list_push_front(&list, "avant");
	ft_list_push_back(&list, "deuxieme");
	ft_print_list(list);
	printf("* size: %d\n", ft_list_size(list));
	printf("* last: %s\n", ft_list_last(list)->data);

	printf("* test ft_list_push_strs:\n");
	char *a[] = {"test", "test1", "pa", "test2", "pouet"};
	list2 = ft_list_push_strs(5, a);
	ft_print_list(list2);
	printf("* element 1: %s\n", ft_list_at(list2, 1)->data);
	ft_list_reverse(&list2);
	printf("* after reverse:\n");
	ft_print_list(list2);
	printf("* test foreach:\n");
	ft_list_foreach(list2, &handle_data);
	ft_list_remove_if(&list2, "test", &remove_p, &free_list);
	printf("* test remove_if:\n");
	ft_print_list(list2);
	printf("* test tri (strcmp):\n");
	ft_list_sort(&list2, &cmp);
	ft_print_list(list2);
	printf("* test merge:\n");
	list = ft_list_push_strs(5, a);
	list3 = ft_create_elem("liste3");
	ft_list_merge(&list3, list);
	//ft_list_merge(&list3, list2);
	ft_print_list(list3);
}

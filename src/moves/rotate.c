/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:14:55 by wiljimen          #+#    #+#             */
/*   Updated: 2024/09/18 18:43:39 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_list **stack_from, char *str)
{
	t_list	*first;
	t_list	*second;

	if (!stack_from || !*stack_from || !(*stack_from)->next)
        return;
	first = *stack_from;
	second = (*stack_from)->next;
	ft_lstadd_back(stack_from, first);
	first->next = NULL;
	*stack_from = second;
	ft_printf("%s", str);
}

void	rotate_r(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, "r");
	rotate(stack_b, "r");
}

void	rev_rotate(t_list **stack_from, char *str)
{
	t_list	*first;
	t_list	*last_node;
	t_list	*pre_last_node;
	
	if (!stack_from || !*stack_from || !(*stack_from)->next)
        return;
	first = *stack_from;
	last_node = ft_lstlast(first);
	pre_last_node = first;
	while(pre_last_node->next->next)
		pre_last_node = pre_last_node->next;
	ft_lstadd_front(stack_from, last_node);
	pre_last_node->next = NULL;
	ft_printf("%s\n", str);
}

void	rev_rr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a, "r");
	rev_rotate(stack_b, "r");
	ft_printf("rrr\n");
}

// // Función para crear un nuevo nodo de la lista
// t_list *create_node(int content, int index) {
//     t_list *new_node = malloc(sizeof(t_list));
//     if (!new_node)
//         return NULL;

//     new_node->content = malloc(sizeof(int));
//     if (!new_node->content) {
//         free(new_node);
//         return NULL;
//     }

//     *(int *)new_node->content = content;
//     new_node->index = index;
//     new_node->next = NULL;
//     return new_node;
// }

// int main() {
//     t_list *stack = NULL;

//     // Crear una lista enlazada de ejemplo
//     t_list *node1 = create_node(1, 0);
//     t_list *node2 = create_node(2, 1);
//     t_list *node3 = create_node(3, 2);
//     t_list *node4 = create_node(4, 3);

//     // Enlazar los nodos
//     ft_lstadd_back(&stack, node1);
//     ft_lstadd_back(&stack, node2);
//     ft_lstadd_back(&stack, node3);
//     ft_lstadd_back(&stack, node4);

//     // Imprimir la lista antes de rotate
//     printf("Lista antes de rotate:\n");
//     print_list(stack);

//     // Aplicar rotate
//     rotate(&stack, 'r');

//     // Imprimir la lista después de rotate
//     printf("Lista después de rotate:\n");
//     print_list(stack);

//     // Liberar memoria
//     t_list *temp;
//     while (stack->next != NULL) {
//         temp = stack;
//         stack = stack->next;
//         free(temp->content);
//         free(temp);
//     }

//     return 0;
// }
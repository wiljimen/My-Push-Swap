/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:21:05 by wiljimen          #+#    #+#             */
/*   Updated: 2024/09/02 18:26:37 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// void	swap(t_list **stack_from)
// {
// 	t_list	*first;
// 	t_list	*second;

// 	first = *stack_from;
// 	second = (*stack_from)->next;
// 	ft_lstadd_front(stack_from, second);
// }

// void print_list(t_list *lst) {
//     while (lst) {
//         ft_printf("Content: %d, Index: %d\n", *(int*)lst->content, lst->index);
//         lst = lst->next;
//     }
//     ft_printf("\n");
// }

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
//     swap(&stack);

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
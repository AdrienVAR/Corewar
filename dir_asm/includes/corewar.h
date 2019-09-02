/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 14:29:38 by advardon          #+#    #+#             */
/*   Updated: 2019/08/28 15:08:11 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "./libft/libft.h"

/*
****************************GARBAGE_COLLECTOR***********************************
*/

void            garbage_collector(t_list **head, void *param);
void            free_gc(t_list *head);
void            add_tab_gc(t_list *structure, void **tab);

#endif

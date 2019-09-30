# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    shared_val.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cizeur <cizeur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 09:36:56 by cgiron            #+#    #+#              #
#    Updated: 2019/09/30 15:32:47 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##										##
##		SHARED VALUE BETWEEN MAKEFILES	##
##										##

CHECK_SHARED_VAL		:= 1
SHARE_SRC_DIR			:= src
SHARE_OBJ_DIR			:= obj
SHARE_INC_DIR			:= includes

vpath %.c $(SHARE_SRC_DIR)
vpath %.h $(SHARE_INC_DIR)
vpath %.o $(SHARE_OBJ_DIR)
vpath %.d $(SHARE_OBJ_DIR)

SHARE_FLAGS				:= -Wall -Wextra -Werror
OPTI_FLAGS				:= -O3 -ffreestanding -fno-builtin -flto
#OPTI_FLAGS				:= -g
SHARE_FLAGS				+= -I $(SHARE_INC_DIR)
SHARE_DEBUG				:= -g3

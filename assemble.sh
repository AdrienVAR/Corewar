# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    assemble.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: advardon <advardon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 17:57:30 by cgiron            #+#    #+#              #
#    Updated: 2019/09/30 14:45:18 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

################################ Functions #####################################

function usage() {
printf "\nusage: sh ./assemble.sh [-m map_folder] [-p program]\n"
printf "Apply asm to .s file\n\
	- in folder -m\n\
	- wih program -p\n\
	- with valgrind -v\n\
	- with -c\n"
}

	########################## Variables initialization ############################

	map_folder=.
	program=./asm
	valgrind=0
	error=0

	############################# Options parser ###################################

	while [ "$1" != "" ]; do
		OPT=$1
		case $OPT in
			-h | --help)
				usage
				exit 0
				;;
			-v)
				valgrind=1
				;;
	
			-s)
				error=1
				;;
			-p)
				shift
				program=$1
				;;
			-m)
				shift
				map_folder=$1
				;;
			*)
				usage
				exit
				;;
		esac
		shift
	done

	################################ Main loop #####################################

	usage

	echo "\n\nGENERATOR   :\033[0;32m" $generator_ex
	echo "\033[0moptions :\033[0;32m" $options
	echo "\033[0mMAP FOLDER :\033[0;32m" $map_folder
	echo "\033[0mGENERATE TILL\033[0;32m" $n_maps "\033[0m MAPS"
	echo "\033[0m"

		if test -f "$program"; then
			echo "\033[0;32m$program exist\033[0m"
		else
			echo "\033[0;31m$program absent\033[0m"
			exit 1
		fi
		for filename in $map_folder/*.s; do
			map_str=$filename
			echo "Now testing \033[0;32m$map_str\033[0m"
			$program $map_str
			success=$($program $map_str | grep "Success")
			if [ -z "$success" ]; then
				cat -n $map_str
			fi
			if [ "$valgrind" -eq 1 ]; then
				echo "With valgrind"
				valgrind $program $map_str  >&1 
			fi
		done



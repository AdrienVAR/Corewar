# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_script_lem_in.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 17:57:30 by cgiron            #+#    #+#              #
#    Updated: 2019/09/30 11:58:15 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

################################ Functions #####################################

function usage() {
printf "\nusage: sh ./test_script_lem_in.sh [-n number of maps] [-m map_folder] [-e with_generator]\n\
	[-g generator][-o generator_opitons][-v with_verif][-t showtime][-p program][-po program options]\n\n"
printf "Lemin map folder generator-tester\n\
	- till n maps\n\
	- in a folder of map (-m)\n\
	- with generator (-g)\n\
	- with generator options (-o)\n\
	- !!!-e for generator careful -m [map_folder] erased\n"
	}

	########################## Variables initialization ############################

	map_folder=./maps_tester
	program=./asm
	valgrind=0

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
		for filename in $map_folder/*; do
			map_str=$filename
			echo "Now testing \033[0;32m$map_str\033[0m"
			$program $map_str
			if [ "$valgrind" -eq 1 ]; then
				echo "With valgrind"
				valgrind $program $map_str  >&1 
			fi
		done



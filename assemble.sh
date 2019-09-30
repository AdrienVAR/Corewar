# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    assemble.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: advardon <advardon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 17:57:30 by cgiron            #+#    #+#              #
#    Updated: 2019/09/30 17:45:00 by cgiron           ###   ########.fr        #
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
	- with -vm for vm name\n\
	- with -c for vm execution\n\
	- with -clean to remove all *.cor\n"
}

########################## Variables initialization ############################

map_folder=.
program=./asm
corewar=0
valgrind=0
vm=./corewar
error=0
clean=0

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
		-clean)
			clean=1
			;;
		-s)
			error=1
			;;
		-p)
			shift
			program=$1
			;;
		-vm)
			shift
			vm=$1
			;;
		-c)
			corewar=1
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


echo "\033[0mTEST FOLDER :\033[0;32m" $map_folder
echo "\033[0m"


echo "CLeaning *.cor"
rm $map_folder/*.cor

if [ "$clean" -eq 1 ]; then
	exit 1
fi

if test -f "$program"; then
	echo "\033[0;32m$program exist\033[0m"
else
	echo "\033[0;31m$program absent\033[0m"
	exit 1
fi
if [ "$corewar" -eq 1 ]; then
	if test -f "$vm"; then
		echo "\033[0;32m$vm exist\033[0m"
	else
		echo "\033[0;31m$vm absent\033[0m"
		exit 1
	fi
fi

for filename in $map_folder/*.s; do
	map_str=$filename
	echo "Now testing \033[0;32m$map_str\033[0m"
	$program $map_str
	success=$($program $map_str | grep "Success")
	if [ -z "$success" ]; then
		cat -n $map_str
	else
		if [ "$corewar" -eq 1 ]; then
			./$vm "${filename%.s}.cor"
		fi
	fi
	if [ "$valgrind" -eq 1 ]; then
		echo "With valgrind"
		valgrind $program $map_str  >&1 
	fi
done



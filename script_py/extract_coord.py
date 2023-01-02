# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    extract_coord.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auzun <auzun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 04:12:40 by auzun             #+#    #+#              #
#    Updated: 2022/12/30 12:51:31 by auzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

with open('file_name.stl', 'r') as f:
	vertices = []
	for line in f:
		words = line.split()
	if words[0] == 'vertex':
		vertices.append((words[1], words[2], words[3]))
with open('../scenes_bonus/new_file.rt', 'w') as out_file:
	i = 0
	for vertex in vertices:
		if i == 0:
			out_file.write("tr ")
		out_file.write(f"{vertex[0]},{vertex[1]},{vertex[2]} ")
		i += 1
		if i == 3:
			out_file.write("255,255,255 0 none none\n")
			i = 0

/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   memrevcpy.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cgiron <cgiron@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/09 15:21:16 by cgiron			#+#	#+#			 */
/*   Updated: 2019/09/09 15:26:14 by cgiron		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

void		*memrevcpy(void *dst, const void *src, int n)
{
	int					i;
	unsigned char		*dchar;
	const unsigned char *schar;

	if (!dst && !src)
		return (dst);
	i = 0;
	dchar = (unsigned char *)dst;
	schar = (const unsigned char*)src;
	while (i < n)
	{
		dchar[i] = schar[n - 1 - i];
		i++;
	}
	return (dst);
}

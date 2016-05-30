/*
** defines.h for  in /home/barrie_j/Documents/Sem_2/PSU_2014_42sh/RedBlackTree
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Thu Apr 23 16:46:22 2015 Jean BARRIERE
** Last update Sun May 31 21:26:53 2015 Jean BARRIERE
*/

#ifndef DEFINES_H_
# define DEFINES_H_

/*
** FOR A GLOBAL USE
*/
# define ERR_MALLOC	"Error: cannot perform malloc\n"
# define SPIP		"|"
# define DPIP		"||"
# define SAND		"&"
# define DAND		"&&"
# define SRDL		"<"
# define SRDR		">"
# define DRDL		"<<"
# define DRDR		">>"
# define SEPARATOR	';'
# define PIP		'|'
# define AND		'&'
# define RDL		'<'
# define RDR		'>'
# define SQT		'\''
# define DGT		'"'
# define MQT		'`'
# define NODE_TYPE_JOIN	0
# define NODE_TYPE_ATTR	1
# define NODE_TYPE_VLUE	2
# define NODE_TYPE_MGQT	3

/*
** TO BE UNDERSTOOD
*/
# define WTH_FREE	1
# define NOT_FREE	0

/*
** MACCROS
*/
# define RETMSGSTD(msg, nb)	put_msg(1, msg, nb)
# define RETMSGERR(msg, nb)	put_msg(2, msg, nb)

#endif /* !DEFINES_H_ */

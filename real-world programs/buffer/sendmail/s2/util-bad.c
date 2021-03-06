
//#include <ctype.h>
//#include <stdio.h>
#include <string.h>
//#include "sendmail-bad.h"

#define SPACELEFT(buf, bp)   (sizeof buf - ((bp) - buf))

/*
**  XALLOC -- Allocate memory and bitch wildly on failure.
**
**	THIS IS A CLUDGE.  This should be made to give a proper
**	error -- but after all, what can we do?
**
**	Parameters:
**		sz -- size of area to allocate.
**
**	Returns:
**		pointer to data region.
**
**	Side Effects:
**		Memory is allocated.
*/

char *
xalloc(sz)
	register int sz;
{
	register char *p;

	/* some systems can't handle size zero mallocs */
	if (sz <= 0)
		sz = 1;

	p = malloc((unsigned) sz);
	if (p == NULL)
	{
		perror("Out of memory!!");	
	}
	return (p);
}

/*
**  BUILDFNAME -- build full name from gecos style entry.
**
**	This routine interprets the strange entry that would appear
**	in the GECOS field of the password file.
**
**	Parameters:
**		p -- name to build.
**		login -- the login name of this user (for &).
**		buf -- place to put the result.
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/


/*
**  BUILDFNAME -- build full name from gecos style entry.
**
**	This routine interprets the strange entry that would appear
**	in the GECOS field of the password file.
**
**	Parameters:
**		p -- name to build.
**		login -- the login name of this user (for &).
**		buf -- place to put the result.
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/

void
buildfname(gecos, login, buf)
	register char *gecos;
	char *login;
	char *buf;
{
	register char *p;
	register char *bp = buf;
	int l;

	if (*gecos == '*')
		gecos++;

	/* find length of final string */
	l = 0;
	for (p = gecos; *p != '\0' && *p != ',' && *p != ';' && *p != '%'; p++)
	{
		if (*p == '&')
			l += strlen(login);
		else
			l++;
	}

	/* now fill in buf */
	for (p = gecos; *p != '\0' && *p != ',' && *p != ';' && *p != '%'; p++)
	{
	  if (*p == '&')
	    {

	      printf ("strcpy(bp,login)\n");
	      printf ("strlen(bp) = %d strlen(login) = %d\n", 
		      strlen(bp), strlen(login));
	      /*BAD*/
	      (void) strcpy(bp, login);
	      *bp = toupper(*bp);
	      while (*bp != '\0')
		bp++;
	    }
	  else {
	    /*BAD*/
	    *bp++ = *p;
	    printf ("bp-buf = %d\n", (bp-buf));
	  }	    
	}
	*bp = '\0';

	printf("buf can store at most %d bytes; strlen(buf) = %d\n", MAXNAME+1, strlen(buf));
}

/*

</source>

*/


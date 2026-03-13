*This project has been created as part of the 42 curriculum by tokrabem.*

# Get_next_line
## DESCRIPTION

***Get_next_line*** is a project within the 42 cursus to read a line from a file descriptor. Repeated calls to **get_next_line()** should read text point by the file descriptor, one line at time. 

**The purpose:**

 - Understand the utility of static variable and file descriptor.
 - Learn how to open, read and close file thanks to fd.
 - Gain skills based on algorithms, code structure and file manipulation.
 - Share knowledge and insights thanks to peer-learning
 
 **Rules of implementation:**
 - Repeated calls to get_next_line() should read the text pointed by a file descriptor, one line at time.
 - The function should return the line that was read and return NULL if there is nothing left.
 - The function should handle both line read in a file or in a standard input.
 - A BUFFER_SIZE will be defined to set the size of a line to read.
 - The line that was read should include \n.
 - The function should handle perfectly the End Of file.
 - The code must be compiled with the command as follows ```cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 .c```
 - Libft library is forbidden.
 - lseek() is forbidden.

 **Return values:**

 - A line read pointed by a file descriptor, \n included.
 - NULL pointer if there's nothing left.
 

## INSTRUCTIONS

### Clone the repository
```git clone ```

### Contents of the project:
This project contains three main files:

 - **get_next_line.c:** the main function that read the line within a file
 - **get_next_line_utils.c**: this file implements all the utils function needed by the get_next_line function.
 - **get_next_line.h:** here stand the prototypes of all the functions throughout the project.

### Example of usage (main.c) :
```bash
#include "fcntl.h"
#include "get_next_line.h"
#include "stdio.h"

int	main(void)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d: %s\n", count++, line);
		free(line);
	}
	close(fd);
	printf("Final count: %d\n", count);
	return (0);
}
```

### Compilation
To compile the function, use this command:
```cc get_next_line.c get_next_line_utils.c main.c -o get_next_line```

### Flag:
```-D BUFFER_SIZE=n```

## RESOURCES

### Official resources

 - Official documentation ```man read, man open```, usage of ``static variable``
 - Some articles and learning platform on the internet and obviously www.youtube.com to apprehend some new concepts thanks to tutorials.
 - Peer-learning system within 42 School based on exchanges, contribution and learning from projects.

### About AI

What I used it for?

 - Giving me an idea on how can I proceed and build the project from scratch.
 - Offset some information judged important but I didn't figure out in the articles or tutorials.
 - Asking few tips real quick and no more.
 - Being an emotional support when tests failed. 
 
 What I did not use it for?
 - Asking directly all the code that I didn't even understand.
 - Building the whole project that will be tricky for me.
 - Substitute the peer-learning by AI's usage and put away the real system of 42 School.

## Bonus part:
The purpose of this bonus part is as follows:

 - Develop get_next_line() using only one static variable.
 - The get_next_line function can manage multiple file descriptors at he same time. No matter how many files it should read from, it would handle them perfectly without confusion.
 
 ### Additional parts:
 - **get_next_line_bonus.c**
 - **get_next_line_utils_bonus.c**
 - **get_next_line_bonus.h**

### Example of usage (main.c):
```bash
#include "fcntl.h"
#include "get_next_line.h"
#include "stdio.h"

int	main(void)
{
	int		count;
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;

	count = 0;
	fd1 = open("file.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		return (1);
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%d: %s", ++count, line);
		free(line);
	}
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("%d: %s", ++count, line);
		free(line);
	}
	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("%d: %s", ++count, line);
		free(line);
	}
	free(line);
	
	close(fd1);
	close(fd2);
	close(fd3);
	
	printf("\nFinal count: %d\n", count);
	
```
This part can be compiled as the same as the main part.

## Technical details:
 This function follows the rules and the Norm solicited by 42.\
 The function has been tested in several ways, didn't show any form of error and handle the same behavior as the original one.

## Author
42 login : *tokrabem*\
For eventual questions or remarks, feel free to contact me within 42 network.

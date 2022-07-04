/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:06:25 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/04 10:49:19 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int main (int argc, char **argv)
// {
// 	int fd[2];

// 	if (pipe(fd) == -1)
// 		return (1);
// 	int pid1 = fork();
// 	if (pid1 < 0)
// 		return (2);  
// 	if (pid1 == 0)
// 	{
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("ping", "ping", "-c", "5", "google.com", NULL);
// 	}
// 	int pid2 = fork();
// 	if (pid2 < 0)
// 		return (3);
// 	if (pid2 == 0)
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("grep", "grep", "rtt", NULL);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);

// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// }


// int	main(int argc, char **argv)
// {
// 	int fd[2];
// 	if (pipe(fd) == -1)
// 		return (1);
// 	int pid1 = fork();
// 	if (pid1 == -1)
// 	{
// 		printf ("error");
// 		return (2);
// 	}
// 	if (pid1 == 0)
// 	{
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("ping", "ping", "-c", "5", "google.com", NULL);
// 	}
// 	int pid2 = fork();
// 	if (pid2 == -1)
// 		return (3);
// 	if (pid2 == 0)
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("grep", "grep", "-c", "bytes", NULL);
// 	}
	
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// }

// int main (int argc, char **argv)
// {
// 	if (argc != 5)
// 		return (1);
// 	int pid = fork();
// 	if (pid == 0)
// 	{
// 		int fd_open = open("joy.txt", O_WRONLY | O_CREAT);
// 		if (fd_open == -1)
// 			return (2);
// 		printf("fd to outfile.txt %d\n", fd_open);
// 		int fd_dup = dup2(fd_open, STDOUT_FILENO);
// 		close(fd_open);
// 		int err = execlp("pipex.c" "pipex.c", NULL);
// 		if (err == -1)
// 		{
// 			printf("can't execute");
// 			return (3);
// 		}
// 	}
// 	else
// 	{
// 	int type_status;
// 	wait(&type_status);
// 		if (WIFEXITED(type_status))
// 		{
// 	int status_code = WEXITSTATUS(type_status);
// 			if (status_code == 0)
// 				printf("success");
// 			else
// 				printf("status code is %d\n", status_code);
// 		}
// 	}
// }



int main (int argc, char **argv)
{
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		int fd = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
		if (fd == -1)
			return (1);
		printf ("The fd to pingresults %d\n", fd);
		int fd2 = dup2 (fd, STDOUT_FILENO);
		close (fd);
		int err = execlp("ping", "ping", "-c", "3", "google.com", NULL);	
		if (err == -1)
		{
			printf ("couldnt find smth to execute\n");
			return (2);
		}
	}
	else
	{
		int wstatus;
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			int statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
				printf("success");
			else
				printf("error status code is %d\n", statusCode);
		}
		// printf("success\n");
		// printf("process is going\n");
	}
}

// int main (int argc, char **argv)
// {
// 	// 5 ==> 5 * 4 = 20 ==> 20
	
// 	int p1[2];  // child to parent
// 	int p2[2]; // parent to child
	
// 	if (pipe(p1) == -1)
// 	{
// 		return 1;
// 	}
// 		int pid = fork();
// 		if (pid == -1)
// 		{
// 			return (2);
// 		}
// 		if (pid == 0)
// 		{
// 			close (p1[0]);
// 			close (p2[1]);
// 			int x;
// 			if(read(p2[0], &x, sizeof(x)) == -1)
// 				return (3);
// 			printf("Received %d\n", x);
// 			x = x * 4;
// 			if (write (p1[1], &x, sizeof(x)) == -1)
// 			{
// 				return (4);
// 			}
// 			printf("Wrote %d\n", x);
// 		}
// 		else {
// 			srand(time(NULL));
// 			int y = rand() % 10;
// 			if (write(p1[1], &y, sizeof(y)) == -1)
// 			{
// 				return (5);
// 			}
// 			// printf("wrote %d\n", y);
// 			if (read(p1[0], &y, sizeof(y)) == -1)
// 			{
// 				return (6);
// 			}
// 			printf("Result is %d\n", y);
// 			wait(NULL);
// 		}
// 		close(p1[0]);
// 		close(p1[1]);
	
// }




// int main (int argc, char **argv)
// {
// 	if (mkfifo("myfifo1", 0777) == -1)
// 	{
// 		if (errno != EEXIST)
// 			printf("error again");
// 		// printf("error occured");
// 	}
// 	printf ("Opening...\n");
	
// 	int fd = open("myfifo1", O_WRONLY);
// 	printf("opened\n");
// 	int x = 27;
// 	if (write (fd, &x, sizeof(x)) == -1)
// 	{
// 		return (2);
// 	}
// 	printf("Written\n");
// 	close(fd);
// 	printf("close\n");
// 	return (0);
// }




// int main (int argc, char **argv)
// {

// 	int arr[] = {3, 2, 4, 1, 6, 5};
// 	int arr_size = sizeof(arr)/sizeof(int);
// 	int start, end;
// 	int fd[2];
// 	if (pipe(fd) == -1)
// 		return (1);
// 	int id = fork();
// 	if (id == -1)
// 		return (2);
// 	if (id == 0)
// 	{
// 		start = 0;
// 		end = start + arr_size / 2;
// 	}
// 	else
// 	{
// 		start = arr_size / 2;
// 		end = arr_size;
// 	}
// 	int sum = 0;
// 	int i = start;
// 	while (i < end)
// 	{
// 		sum = sum + arr[i];
// 		i++;
// 	}
// 	printf ("sum is %d\n", sum);

// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		write(fd[1], &sum, sizeof(sum));
// 		close (fd[1]);
// 	}
// 	else 
// 	{
// 		int sumChild;
// 		close (fd[1]);
// 		read(fd[0], &sumChild, sizeof(sumChild));
// 		close(fd[0]);
		
// 		int totalSum = sum + sumChild;
// 		printf ("the total is %d\n", totalSum);
// 		wait(NULL);
// 	}
// }

// int main (int argc, char **argv)
// {
// 	int id = fork();
// 	if (id == 0)
// 		sleep(1);
// 	printf ("current id is %d, parent id is %d\n", getpid(), getppid());
// 	int res = wait(NULL);
// 	if (res == -1)
// 		printf ("no children to wait");
// 	else
// 		printf ("%d finished execution\n", res);
// }

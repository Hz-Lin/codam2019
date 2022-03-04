#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

size_t	ft_strlen(char *s)
{
	int	i = 0;

	while (s[i])
		i++;
	return (i);
}

void	ft_strerror(char *msg, char *arg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	if (arg)
		write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, "\n", 1);
	kill(0, SIGINT);
}

void	ft_cd(char **arg)
{
	if (!arg[1] || arg[2])
		ft_strerror("error: cd: bad arguments", NULL);
	else if (chdir(arg[1]) == -1)
		ft_strerror("error: cd: cannot change directory to ", arg[1]);
}

void	child_process(char **arg, int *fd, int fd_in, int last, char *envp[])
{
	if (dup2(fd_in, STDIN_FILENO) == -1)
		ft_strerror("error: fatal", NULL);
	if (last == 0)
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_strerror("error: fatal", NULL);
	close(fd_in);
	close(fd[0]);
	close(fd[1]);
	if (execve(arg[0], arg, envp) == -1)
		ft_strerror("error: cannot execute ", arg[0]);
}

int		ft_execute(char **arg, char *envp[], int fd_in)
{
	pid_t	pid;
	int		fd[2];
	int		i = 0;
	int		last = 0;

	while (arg[i] && strcmp(arg[i], "|") != 0)
		i++;
	if (!arg[i])
		last = 1;
	arg[i] = 0;
	if (pipe(fd) == -1 || (pid = fork()) == -1)
		ft_strerror("error: fatal", NULL);
	else if (pid == 0)
		child_process(arg, fd, fd_in, last, envp);
	else
	{
		if (dup2(fd[0], fd_in) == -1)
			ft_strerror("error: fatal", NULL);
		close(fd[0]);
		close(fd[1]);
	}
	if (last == 0)
		return (i + 1);
	return (i);
}

void	launch_cmd(char **arg, char *envp[])
{
	int	i = 0;
	int	count = 0;
	int	status;
	int	fd_in;

	if (strcmp(arg[0], "cd") == 0)
		return (ft_cd(arg));
	if ((fd_in = dup(STDIN_FILENO)) == -1)
		ft_strerror("error: fatal", NULL);
	while (arg[i])
	{
		i += ft_execute(arg + i, envp, fd_in);
		count++;
	}
	close(fd_in);
	while (count > 0)
	{
		waitpid(-1, &status, 0);
		count--;
	}
}

int	main(int argc, char **argv, char *envp[])
{
	int	i = 1;
	int	start = 1;

	if (argc < 2)
		return (0);
	while (argv[i] && strcmp(argv[i], ";") == 0)
		i++;
	start = i;
	while (argv[i])
	{
		if (strcmp(argv[i], ";") == 0)
		{
			argv[i] = 0;
			launch_cmd(argv + start, envp);
			i++;
			while (argv[i] && strcmp(argv[i], ";") == 0)
				i++;
			start = i;
		}
		else
			i++;
	}
	if (argv[start])
		launch_cmd(argv + start, envp);
	return (0);
}
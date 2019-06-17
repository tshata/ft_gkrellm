all : ft_gkrellm

ft_gkrellm : CPU.Class.cpp Hostname.Class.cpp OSInfo.Class.cpp main.cpp Date.Class.cpp Map.cpp RAM.Class.cpp 
	clang++ CPU.Class.cpp Hostname.Class.cpp OSInfo.Class.cpp main.cpp Date.Class.cpp Map.cpp RAM.Class.cpp -lncurses -o ft_gkrellm -Wall -Werror -Wextra

clean : 
	rm ft_gkrellm

fclean : clean

re : fclean all

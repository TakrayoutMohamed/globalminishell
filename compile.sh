#! /bin/bash
make ./execution/libmini.a ./execution/libft/libft.a ./parsing/libpars.a 
# cc testing/convert_parsing_lst_to_execution_tst.c ./execution/libmini.a ./execution/libft/libft.a\
#  ./parsing/libpars.a convert_parsing_lst_to_execution.c -o convert_llst_lst

# cc testing/convert_parsing_env_to_execution_tst.c ./execution/libmini.a ./execution/libft/libft.a\
#  ./parsing/libpars.a convert_parsing_env_to_execution.c -o convert_llst_env

cc testing/convert_execution_env_to_parsing_tst.c ./execution/libmini.a ./execution/libft/libft.a\
 ./parsing/libpars.a convert_parsing_env_to_execution.c convert_execution_env_to_parsing.c -o convert_lst_env_to_llstenv


#! /bin/bash
# make libmini.a
# cc testing/convert_parsing_lst_to_execution_tst.c ./execution/libmini.a ./execution/libft/libft.a\
#  ./parsing/libpars.a convert_parsing_lst_to_execution.c -o convert_llst_lst

cc testing/convert_parsing_env_to_execution_tst.c ./execution/libmini.a ./execution/libft/libft.a\
 ./parsing/libpars.a convert_parsing_env_to_execution.c -o convert_llst_env


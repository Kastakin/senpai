/*
 * args.c
 *
 * Licensed under MIT license
 *
 */

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "args.h"
#include "util.h"
#include "text.h"

t_args *args_init(t_args *args)
{
  if (args == NULL)
    return (retstr(NULL, TEXT_ARGS_INIT_FAILURE, __FILE__, __LINE__));

  args->path = NULL;
  args->out_path = NULL;
  args->timestep = ARGS_TIMESTEP_DEFAULT;
  args->max_time = ARGS_MAX_TIME_DEFAULT;
  return (args);
}

t_args *args_parse(t_args *args, int argc, char **argv)
{
  int64_t i;

  for (i=1; i<argc; ++i)
  {
    if ((!strcmp(argv[i], FLAG_INPUT) || !strcmp(argv[i], FLAG_INPUT2)) && (i+1)<argc)
      args->path = argv[++i];
    else if ((!strcmp(argv[i], FLAG_OUTPUT) || !strcmp(argv[i], FLAG_OUTPUT2)) && (i+1)<argc)
      args->out_path = argv[++i];
    else if ((!strcmp(argv[i], FLAG_TIME) || !strcmp(argv[i], FLAG_TIME2)) && (i+1)<argc)
      args->max_time = atof(argv[++i])*1E-12; /* Scale from picoseconds */
    else if ((!strcmp(argv[i], FLAG_TIMESTEP) && (i+1)<argc))
      args->timestep = atof(argv[++i])*1E-12; /* Scale from picoseconds */
  }

  if (args->path == NULL || args->out_path == NULL)
    return (retstr(NULL, TEXT_ARGS_PARSE_FAILURE, __FILE__, __LINE__));
  return (args);
}

/*
 * universe.h
 *
 * Licensed under MIT license
 *
 */

#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <universe.h>
#include <constants.h>
#include <vec3d.h>
#include <text.h>

#include <stdint.h>
#include <stdio.h>

typedef struct s_particle t_particle;
struct s_particle
{
  double mass;
  double charge;
  double radius;

  t_vec3d pos;
  t_vec3d spd;
  t_vec3d acc;
  t_vec3d frc;
};

typedef struct s_universe t_universe;
struct s_universe
{
  /* Universe constants */
  double  c_grav;
  double  c_elec;
  double  c_time;

  double time; /* Current time */
  t_particle particle[C_PART_NB];
  FILE *fd_tab[C_PART_NB]; /* Each particle will its log written to a corresponding .csv file */
};

t_particle *particle_init(t_particle *particle);
t_universe *particle_update_frc(t_universe *universe, const uint64_t part_id);
t_universe *particle_update_acc(t_universe *universe, const uint64_t part_id);
t_universe *particle_update_spd(t_universe *universe, const uint64_t part_id);
t_universe *particle_update_pos(t_universe *universe, const uint64_t part_id);

t_universe *universe_init(t_universe *universe);
t_universe *universe_iterate(t_universe *universe);

#endif

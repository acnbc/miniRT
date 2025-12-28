#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct  s_tuple
{
    double  x;
    double  y;
    double  z;
    bool    is_vector;
}               t_tuple;

typedef struct  s_rgb
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}               t_rgb;

typedef enum
{
    A,
    C,
    L,
    sp,
    pl,
    cy
} e_id;

typedef struct  s_amb_light
{
    e_id    id;
    double  light_ratio;
    t_rgb   colors;
}               t_amb_light;

typedef struct  s_camera
{
    e_id    id;
    t_tuple view_point;
    t_tuple orientation_vector;
    double   field_of_view;
}               t_camera;

typedef struct  s_light
{
    e_id    id;
    t_tuple light_point;
    double   brightness;
}               t_light;

typedef struct  s_sphere
{
    double  diameter;
}               t_sphere;

typedef struct  s_plane
{
    t_tuple normalized_vector;
}               t_plane;

typedef struct  s_cylinder
{
    t_tuple normalized_vector;
    double  diameter;
    double  height;
}               t_cylinder;

typedef union
{
    t_sphere    sphere;
    t_plane     plane;
    t_cylinder  cylinder;
} u_object;

typedef struct  s_object
{
    e_id            id;
    t_tuple         coord;
    t_rgb           colors;
    u_object        object;
    struct s_object *next;
}               t_object;

typedef struct  s_scene
{
    t_amb_light amb_light;
    t_camera    camera;
    t_light     light;
    t_object    *objects;
}               t_scene;

#endif
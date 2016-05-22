//
// Created by wo on 5/20/16.
//

#ifndef RRR_SURF_BUF_H
#define RRR_SURF_BUF_H

#include "lua.h"
#include "../generic/aarr.h"

#define buf_method(c, w)\
int\
l_ ## c ## _ ## w ## _buf(lua_State* L);

#define create_buf(w) buf_method(create, w)
#define push_buf(w) buf_method(push, w)
#define destroy_buf(w) buf_method(destroy, w)

#define new_buf_type(w)\
struct rl_ ## w ## _buf {\
  struct r_aarr* hnd;

#define end(w)\
};\
create_buf(w);\
push_buf(w);\
destroy_buf(w);

new_buf_type(surf)
end(surf)

#define RL_SURF_BUF_MT_KEY "rrr.rl_surf_buf"

new_buf_type(light)
end(light)

#define RL_LIGHT_BUF_MT_KEY "rrr.rl_light_buf"

new_buf_type(material)
end(material)

new_buf_type(g)
end(g)

#define RL_MATERIAL_BUF_MT_KEY "rrr.rl_material_buf"

#define check_surf_buf(L, i)\
  (struct rl_surf_buf*) luaL_checkudata(L, i, RL_SURF_BUF_MT_KEY)
#define check_light_buf(L, i)\
  (struct rl_light_buf*) luaL_checkudata(L, 1, RL_LIGHT_BUF_MT_KEY)
#define check_material_buf(L, i)\
  (struct rl_material_buf*) luaL_checkudata(L, 1, RL_MATERIAL_BUF_MT_KEY)

void
install_buf_metatables(lua_State* L);

int
l_append_wavefront_object(lua_State *L);

int
l_add_surface(lua_State* L);

#endif //RRR_SURF_BUF_H
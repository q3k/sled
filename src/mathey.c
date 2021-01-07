// Mathey, tiny math helpers.
// Why? Cause they're handy.
// Why not macros? Cause smaller binary size.
//
// Copyright (c) 2019, Adrian "vifino" Pistol <vifino@tty.sh>
// 
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
// 
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#include "mathey.h"

byte bdiff(byte a, byte b) {
	if (a > b) return a - b;
	if (a < b) return b - a;
	return 0;
}

byte bmin(byte a, byte b) {
	return (a > b) ? a : b;
}

byte bmax(byte a, byte b) {
	return (a < b) ? a : b;
}

inline float square(float x) {
  return x*x;
}

vec2 vadd(vec2 v1, vec2 v2) {
	vec2 r = {
		.x = v1.x + v2.x,
		.y = v1.y + v2.y,
	};
	return r;
}

vec2 vmul(vec2 vec, float val) {
	vec2 r = {
		.x = vec.x * val,
		.y = vec.y * val,
	};
	return r;
}

vec3 v3add(vec3 v1, vec3 v2) {
	vec3 r = {
		.x = v1.x + v2.x,
		.y = v1.y + v2.y,
		.z = v1.z + v2.z,
	};
	return r;
}

vec2 multm2v2(matrix2_2 m, vec2 v) {
	vec2 r = {
		.x = (m.v1_1 * v.x) + (m.v1_2 * v.y),
		.y = (m.v2_1 * v.x) + (m.v2_2 * v.y),
	};
	return r;
}

vec3 multm3v3(matrix3_3 m, vec3 v) {
  vec3 r = {
      .x = (m.v1_1*v.x) + (m.v1_2*v.y) + (m.v1_3*v.z),
      .y = (m.v2_1*v.x) + (m.v2_2*v.y) + (m.v2_3*v.z),
      .z = (m.v3_1*v.x) + (m.v3_2*v.y) + (m.v3_3*v.z)
  };
  return r;
}

vec2 multm3v2(matrix3_3 m, vec2 v) {
  vec2 r = {
      .x = (m.v1_1*v.x) + (m.v1_2*v.y) + (m.v1_3),
      .y = (m.v2_1*v.x) + (m.v2_2*v.y) + (m.v2_3)
  };
  return r;
}

vec4 multm4v4(matrix4_4 m, vec4 v) {
  vec4 r = {
      .x = (m.v1_1*v.x) + (m.v1_2*v.y) + (m.v1_3*v.z) + (m.v1_4*v.w),
      .y = (m.v2_1*v.x) + (m.v2_2*v.y) + (m.v2_3*v.z) + (m.v2_4*v.w),
      .z = (m.v3_1*v.x) + (m.v3_2*v.y) + (m.v3_3*v.z) + (m.v3_4*v.w),
      .w = (m.v4_1*v.x) + (m.v4_2*v.y) + (m.v4_3*v.z) + (m.v4_4*v.w)
  };
  return r;
}

vec3 multm4v3(matrix4_4 m, vec3 v) {
  vec3 r = {
      .x = (m.v1_1*v.x) + (m.v1_2*v.y) + (m.v1_3*v.z) + (m.v1_4),
      .y = (m.v2_1*v.x) + (m.v2_2*v.y) + (m.v2_3*v.z) + (m.v2_4),
      .z = (m.v3_1*v.x) + (m.v3_2*v.y) + (m.v3_3*v.z) + (m.v3_4)
  };
  return r;
}

matrix2_2 multm2(matrix2_2 m1, matrix2_2 m2) {
	matrix2_2 r = {
		.v1_1 = (m1.v1_1 * m2.v1_1) + (m1.v1_2 * m2.v2_1),
		.v1_2 = (m1.v1_1 * m2.v1_2) + (m1.v1_2 * m2.v2_2),
		.v2_1 = (m1.v2_1 * m2.v1_1) + (m1.v2_2 * m2.v2_1),
		.v2_2 = (m1.v2_1 * m2.v1_1) + (m1.v2_2 * m2.v2_1),
	};
	return r;
}

matrix3_3 multm3(matrix3_3 m1, matrix3_3 m2) {
  matrix3_3 r = {
      .v1_1 = m1.v1_1*m2.v1_1 + m1.v1_2*m2.v2_1 + m1.v1_3*m2.v3_1,
      .v1_2 = m1.v1_1*m2.v1_2 + m1.v1_2*m2.v2_2 + m1.v1_3*m2.v3_2,
      .v1_3 = m1.v1_1*m2.v1_3 + m1.v1_2*m2.v2_3 + m1.v1_3*m2.v3_3,

      .v2_1 = m1.v2_1*m2.v1_1 + m1.v2_2*m2.v2_1 + m1.v2_3*m2.v3_1,
      .v2_2 = m1.v2_1*m2.v1_2 + m1.v2_2*m2.v2_2 + m1.v2_3*m2.v3_2,
      .v2_3 = m1.v2_1*m2.v1_3 + m1.v2_2*m2.v2_3 + m1.v2_3*m2.v3_3,

      .v3_1 = m1.v3_1*m2.v1_1 + m1.v3_2*m2.v2_1 + m1.v3_3*m2.v3_1,
      .v3_2 = m1.v3_1*m2.v1_2 + m1.v3_2*m2.v2_2 + m1.v3_3*m2.v3_2,
      .v3_3 = m1.v3_1*m2.v1_3 + m1.v3_2*m2.v2_3 + m1.v3_3*m2.v3_3
    };
  return r;
};

matrix4_4 multm4(matrix4_4 m1, matrix4_4 m2) {
  matrix4_4 r = {
      .v1_1 = m1.v1_1*m2.v1_1 + m1.v1_2*m2.v2_1 + m1.v1_3*m2.v3_1 + m1.v1_4*m2.v4_1,
      .v1_2 = m1.v1_1*m2.v1_2 + m1.v1_2*m2.v2_2 + m1.v1_3*m2.v3_2 + m1.v1_4*m2.v4_2,
      .v1_3 = m1.v1_1*m2.v1_3 + m1.v1_2*m2.v2_3 + m1.v1_3*m2.v3_3 + m1.v1_4*m2.v4_3,
      .v1_4 = m1.v1_1*m2.v1_4 + m1.v1_2*m2.v2_4 + m1.v1_3*m2.v3_4 + m1.v1_4*m2.v4_4,

      .v2_1 = m1.v2_1*m2.v1_1 + m1.v2_2*m2.v2_1 + m1.v2_3*m2.v3_1 + m1.v2_4*m2.v4_1,
      .v2_2 = m1.v2_1*m2.v1_2 + m1.v2_2*m2.v2_2 + m1.v2_3*m2.v3_2 + m1.v2_4*m2.v4_2,
      .v2_3 = m1.v2_1*m2.v1_3 + m1.v2_2*m2.v2_3 + m1.v2_3*m2.v3_3 + m1.v2_4*m2.v4_3,
      .v2_4 = m1.v2_1*m2.v1_4 + m1.v2_2*m2.v2_4 + m1.v2_3*m2.v3_4 + m1.v2_4*m2.v4_4,

      .v3_1 = m1.v3_1*m2.v1_1 + m1.v3_2*m2.v2_1 + m1.v3_3*m2.v3_1 + m1.v3_4*m2.v4_1,
      .v3_2 = m1.v3_1*m2.v1_2 + m1.v3_2*m2.v2_2 + m1.v3_3*m2.v3_2 + m1.v3_4*m2.v4_2,
      .v3_3 = m1.v3_1*m2.v1_3 + m1.v3_2*m2.v2_3 + m1.v3_3*m2.v3_3 + m1.v3_4*m2.v4_3,
      .v3_4 = m1.v3_1*m2.v1_4 + m1.v3_2*m2.v2_4 + m1.v3_3*m2.v3_4 + m1.v3_4*m2.v4_4,

      .v4_1 = m1.v4_1*m2.v1_1 + m1.v4_2*m2.v2_1 + m1.v4_3*m2.v3_1 + m1.v4_4*m2.v4_1,
      .v4_2 = m1.v4_1*m2.v1_2 + m1.v4_2*m2.v2_2 + m1.v4_3*m2.v3_2 + m1.v4_4*m2.v4_2,
      .v4_3 = m1.v4_1*m2.v1_3 + m1.v4_2*m2.v2_3 + m1.v4_3*m2.v3_3 + m1.v4_4*m2.v4_3,
      .v4_4 = m1.v4_1*m2.v1_4 + m1.v4_2*m2.v2_4 + m1.v4_3*m2.v3_4 + m1.v4_4*m2.v4_4,

    };
  return r;
};

matrix3_3 identity3() {
  matrix3_3 r = {
    .v1_1 = 1,
    .v1_2 = 0,
    .v1_3 = 0,
    .v2_1 = 0,
    .v2_2 = 1,
    .v2_3 = 0,
    .v3_1 = 0,
    .v3_2 = 0,
    .v3_3 = 1
  };
  return r;
}

matrix4_4 identity4() {
  matrix4_4 r = {
    .v1_1 = 1,
    .v1_2 = 0,
    .v1_3 = 0,
    .v1_4 = 0,
    .v2_1 = 0,
    .v2_2 = 1,
    .v2_3 = 0,
    .v2_4 = 0,
    .v3_1 = 0,
    .v3_2 = 0,
    .v3_3 = 1,
    .v3_4 = 0,
    .v4_1 = 0,
    .v4_2 = 0,
    .v4_3 = 0,
    .v4_4 = 1,
  };
  return r;
}

matrix3_3 composem3(int n, ...) {
  va_list valist;
  va_start(valist, n);

  matrix3_3 r = identity3();
  for (int i = 0; i < n; i++) {
    matrix3_3 x = va_arg(valist, matrix3_3);
    r = multm3(r,x);
  }

  va_end(valist);
  return r;
}

matrix4_4 composem4(int n, ...) {
  va_list valist;
  va_start(valist, n);

  matrix4_4 r = identity4();
  for (int i = 0; i < n; i++) {
    matrix4_4 x = va_arg(valist, matrix4_4);
    r = multm4(r,x);
  }

  va_end(valist);
  return r;
}

matrix3_3 rotation3(float angle) {
  matrix3_3 r = {
    .v1_1 = cos(angle),
    .v1_2 = -sin(angle),
    .v1_3 = 0,
    .v2_1 = sin(angle),
    .v2_2 = cos(angle),
    .v2_3 = 0,
    .v3_1 = 0,
    .v3_2 = 0,
    .v3_3 = 1
  };
  return r;
}

matrix4_4 rotation4x(float angle) {
  matrix4_4 r = {
    .v1_1 = 1,
    .v1_2 = 0,
    .v1_3 = 0,
    .v1_4 = 0,
    .v2_1 = 0,
    .v2_2 = cos(angle),
    .v2_3 = -sin(angle),
    .v2_4 = 0,
    .v3_1 = 0,
    .v3_2 = sin(angle),
    .v3_3 = cos(angle),
    .v3_4 = 0,
    .v4_1 = 0,
    .v4_2 = 0,
    .v4_3 = 0,
    .v4_4 = 1
  };
  return r;
}

matrix4_4 rotation4y(float angle) {
  matrix4_4 r = {
    .v1_1 = cos(angle),
    .v1_2 = 0,
    .v1_3 = sin(angle),
    .v1_4 = 0,
    .v2_1 = 0,
    .v2_2 = 1,
    .v2_3 = 0,
    .v2_4 = 0,
    .v3_1 = -sin(angle),
    .v3_2 = 0,
    .v3_3 = cos(angle),
    .v3_4 = 0,
    .v4_1 = 0,
    .v4_2 = 0,
    .v4_3 = 0,
    .v4_4 = 1
  };
  return r;
}

matrix4_4 rotation4z(float angle) {
  matrix4_4 r = {
    .v1_1 = cos(angle),
    .v1_2 = -sin(angle),
    .v1_3 = 0,
    .v1_4 = 0,
    .v2_1 = sin(angle),
    .v2_2 = cos(angle),
    .v2_3 = 0,
    .v2_4 = 0,
    .v3_1 = 0,
    .v3_2 = 0,
    .v3_3 = 1,
    .v3_4 = 0,
    .v4_1 = 0,
    .v4_2 = 0,
    .v4_3 = 0,
    .v4_4 = 1
  };
  return r;
}

matrix4_4 rotation4xyz(float x_angle, float y_angle, float z_angle) {
  return composem4(3, rotation4x(x_angle), rotation4y(y_angle), rotation4z(z_angle));
}

matrix4_4 rotation4zyx(float x_angle, float y_angle, float z_angle) {
  return composem4(3, rotation4z(z_angle), rotation4y(y_angle), rotation4x(x_angle));
}

matrix3_3 translation3(float x, float y) {
  matrix3_3 r = {
    .v1_1 = 1,
    .v1_2 = 0,
    .v1_3 = x,
    .v2_1 = 0,
    .v2_2 = 1,
    .v2_3 = y,
    .v3_1 = 0,
    .v3_2 = 0,
    .v3_3 = 1
  };
  return r;
}

matrix4_4 translation4(float x, float y, float z) {
  matrix4_4 r = {
    .v1_1 = 1,
    .v1_2 = 0,
    .v1_3 = 0,
    .v1_4 = x,
    .v2_1 = 0,
    .v2_2 = 1,
    .v2_3 = 0,
    .v2_4 = y,
    .v3_1 = 0,
    .v3_2 = 0,
    .v3_3 = 1,
    .v3_4 = z,
    .v4_1 = 0,
    .v4_2 = 0,
    .v4_3 = 0,
    .v4_4 = 1
  };
  return r;
}

matrix3_3 translation3_v2(vec2 v) {
  return translation3(v.x, v.y);
}

matrix3_3 translation3_v3(vec3 v) {
  return translation3(v.x, v.y);
}

matrix4_4 translation4_v3(vec3 v) {
  return translation4(v.x, v.y, v.z);
}

matrix4_4 translation4_v4(vec4 v) {
  return translation4(v.x, v.y, v.z);
}

matrix3_3 scale3(float x_factor, float y_factor) {
  matrix3_3 r = {
    .v1_1 = x_factor,
    .v1_2 = 0,
    .v1_3 = 0,
    .v2_1 = 0,
    .v2_2 = y_factor,
    .v2_3 = 0,
    .v3_1 = 0,
    .v3_2 = 0,
    .v3_3 = 1
  };
  return r;
}

matrix4_4 scale4(float x_factor, float y_factor, float z_factor) {
  matrix4_4 r = {
    .v1_1 = x_factor,
    .v1_2 = 0,
    .v1_3 = 0,
    .v1_4 = 0,
    .v2_1 = 0,
    .v2_2 = y_factor,
    .v2_3 = 0,
    .v2_4 = 0,
    .v3_1 = 0,
    .v3_2 = 0,
    .v3_3 = z_factor,
    .v3_4 = 0,
    .v4_1 = 0,
    .v4_2 = 0,
    .v4_3 = 0,
    .v4_4 = 1
  };
  return r;
}

matrix3_3 shear3(float x_shear, float y_shear) {
  matrix3_3 r = {
    .v1_1 = 1,
    .v1_2 = x_shear,
    .v1_3 = 0,
    .v2_1 = y_shear,
    .v2_2 = 1,
    .v2_3 = 0,
    .v3_1 = 0,
    .v3_2 = 0,
    .v3_3 = 1
  };
  return r;
}

matrix4_4 shear4(float xy_shear, float xz_shear, float yx_shear, float yz_shear, float zx_shear, float zy_shear) {
  matrix4_4 r = {
    .v1_1 = 1,
    .v1_2 = xy_shear,
    .v1_3 = xz_shear,
    .v1_4 = 0,
    .v2_1 = yx_shear,
    .v2_2 = 1,
    .v2_3 = yz_shear,
    .v2_4 = 0,
    .v3_1 = zx_shear,
    .v3_2 = zy_shear,
    .v3_3 = 1,
    .v3_4 = 0,
    .v4_1 = 0,
    .v4_2 = 0,
    .v4_3 = 0,
    .v4_4 = 1
  };
  return r;
}

vec4 vec3tovec4(vec3 v) {
  vec4 a = {
    .x = v.x,
    .y = v.y,
    .z = v.z,
    .w = 1
  };
  return a;
}

vec3 vec4tovec3(vec4 a) {
  vec3 v = {
    .x = a.x,
    .y = a.y,
    .z = a.z
  };
  return v;
}

vec3 vec2tovec3(vec2 v) {
  vec3 a = {
    .x = v.x,
    .y = v.y,
    .z = 1
  };
  return a;
}

vec2 vec3tovec2(vec3 a) {
  vec2 v = {
    .x = a.x,
    .y = a.y
  };
  return v;
}


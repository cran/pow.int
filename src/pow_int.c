/*
 * pow.int - Binary Exponentiation
 * Copyright (C) 2022 Jonathan Debove
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <Rinternals.h>
#include <Rmath.h>
#include <R_ext/Itermacros.h>

SEXP C_pow_int(SEXP x, SEXP n)
{
	R_xlen_t ix, nx = XLENGTH(x);
	R_xlen_t in, nn = XLENGTH(n);
	R_xlen_t iy, ny = (nx >= nn ? nx : nn);
	SEXP y = PROTECT(allocVector(REALSXP, ny));
	double *xx = REAL(x);
	int *xn = INTEGER(n);
	double *xy = REAL(y);
	MOD_ITERATE2(nn, nx, ny, iy, ix, in,
		xy[iy] = R_pow_di(xx[ix], xn[in]);
	);
	UNPROTECT(1);
	return y;
}

static const R_CallMethodDef CallEntries[] = {
	{ "C_pow_int", (DL_FUNC) &C_pow_int, 2 },
	{ NULL,	NULL, 0 },
};

void R_init_pow_int(DllInfo *dll)
{
	R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
	R_useDynamicSymbols(dll, FALSE);
	R_forceSymbols(dll, TRUE);
}


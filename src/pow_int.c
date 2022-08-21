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
#include <R_ext/Rdynload.h>

SEXP C_pow_int(SEXP s1, SEXP s2)
{
	R_xlen_t i, i1, i2, n, n1, n2;
	SEXP ans;

	n1 = XLENGTH(s1);
	n2 = XLENGTH(s2);
	n = (n1 >= n2) ? n1 : n2;

	PROTECT(ans = allocVector(REALSXP, n));

	double *da = REAL(ans);
	double *d1 = REAL(s1);
	int *d2 = INTEGER(s2);
	if (n2 == 1) {
		R_ITERATE(n, i, da[i] = R_pow_di(d1[i], d2[0]););
	} else if (n1 == 1) {
		R_ITERATE(n, i, da[i] = R_pow_di(d1[0], d2[i]););
	} else if (n1 == n2) {
		R_ITERATE(n, i, da[i] = R_pow_di(d1[i], d2[i]););
	} else {
		MOD_ITERATE2(n, n1, n2, i, i1, i2,
				da[i] = R_pow_di(d1[i1], d2[i2]););
	}

	UNPROTECT(1);

	return ans;
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


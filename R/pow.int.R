# pow.int - Binary Exponentiation
# Copyright (C) 2022 Jonathan Debove
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

pow.int <- function(x, n)
{
	nx <- length(x)
       	nn <- length(n)
	if (nx == 0L || nn == 0L) return (numeric(0))

	if (is.array(x) && is.array(n) && any(dim(x) != dim(n))) {
		stop("non-conformable arrays")
	}
	rn <- range(c(nx, nn))
	if (rn[2L] %% rn[1L] != 0L) {
		warning("longer object length is not a multiple of ",
				"shorter object length");
	}

	storage.mode(x) <- "double"
	storage.mode(n) <- "integer"
	ans <- .Call(C_pow_int, x, n)

	if (length(ans) == nx) {
		mostattributes(ans) <- attributes(x)
	} else if (length(ans) == nn) {
		mostattributes(ans) <- attributes(n)
	}

	ans
}

`%^%` <- pow.int


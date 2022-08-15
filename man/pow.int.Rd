\name{pow.int}
\alias{pow.int}
\alias{\%^\%}
\title{
	Binary Exponentiation
}
\description{
	Fast exponentiation when the exponent is an integer.
}
\usage{
pow.int(x, n)
x \%^\% n
}
\arguments{
  \item{x}{a numeric vector giving the base.}
  \item{n}{an integer vector giving the exponent.}
}
\value{A numeric vector.}
\author{Jonathan Debove}
\note{
	This function is just a wrapper around \code{R_pow_di} in the Rmath
	library.
}
\examples{
3 \%^\% 12L

# Basic tests
x <- runif(10)
n <- as.integer(runif(length(x), 0, 100))
stopifnot(all.equal(pow.int(x, n),  x ^ n))
stopifnot(all.equal(pow.int(x[1], n),  x[1] ^ n))
stopifnot(all.equal(pow.int(x, n[1]),  x ^ n[1]))
stopifnot(all.equal(pow.int(x[1:2], n),  x[1:2] ^ n))
stopifnot(all.equal(pow.int(x, n[1:2]),  x ^ n[1:2]))
}
